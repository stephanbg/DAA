/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 2 de Abril de 2024
 * @file ramificacionYPodaProfundidad.cc
 * @brief Implementación de la clase RamificacionYPodaProfundidad que hereda de AlgoritmosDiversidadMaxima
 * para resolver el problema de Maximum diversity problem.
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p08/src}
 */

#include "ramificacionYPodaProfundidad.h"

/**
 * @brief Ejecuta el algoritmo de Ramificación y Poda con búsqueda en profundidad para resolver el problema.
 *
 * @param kProblema El problema a resolver.
 * @param kNumElementosEnSolucion Número de elementos en la solución deseada.
 * @param kIteraciones Número de iteraciones o pasos del algoritmo.
 * @return La mejor solución encontrada.
 */
Solucion RamificacionYPodaProfundidad::ejecutar(
  const Problema& kProblema, const int kNumElementosEnSolucion, const int kIteraciones
) {  
  const Matriz& kDistancias = kProblema.getDistancias();
  const std::pair<Matriz, std::vector<int>>& kElementosProblema = std::make_pair(
    kProblema.getCoordenadas(), kProblema.getIndicesProblema()
  );
  GRASP algortimo;
  Solucion mejor_solucion = algortimo.ejecutar(kProblema, kNumElementosEnSolucion, kIteraciones);
  double cota_inferior = mejor_solucion.getFuncionObjetivo();
  std::vector<std::tuple<double, double, int>> distancias_min_max = calcularDistanciasMinMax(kDistancias, kNumElementosEnSolucion);
  std::sort(distancias_min_max.begin(), distancias_min_max.end(),
            [](const auto& a, const auto& b) {
              return std::get<1>(a) > std::get<1>(b);
            });
  ramificacionYPoda(
    kDistancias, kElementosProblema, kNumElementosEnSolucion, mejor_solucion, cota_inferior, 0, distancias_min_max
  );
  solucion_ = mejor_solucion;
  return solucion_;
}

/**
 * @brief Implementa el algoritmo de Ramificación y Poda con búsqueda en profundidad
 * para explorar el espacio de soluciones.
 *
 * @param kDistancias Matriz de distancias entre elementos.
 * @param kElementosProblema Elementos del problema (coordenadas y sus índices).
 * @param kNumElementosEnSolucion Número de elementos en la solución deseada.
 * @param mejor_solucion La mejor solución encontrada hasta el momento.
 * @param cota_inferior Cota inferior actual para el problema.
 * @param kIndice Índice actual en la exploración del árbol de soluciones.
 * @param kDistanciasMinMax Lista ordenada de distancias mínimas y máximas.
 */
void RamificacionYPodaProfundidad::ramificacionYPoda(
  const Matriz& kDistancias, const std::pair<Matriz, std::vector<int>>& kElementosProblema,
  const int kNumElementosEnSolucion, Solucion& mejor_solucion, double& cota_inferior,
  const int kIndice, const std::vector<std::tuple<double, double, int>>& kDistanciasMinMax
  ) {
  if (solucion_.size() == kNumElementosEnSolucion) {
    double cota = calcularFuncionObjetivoParcialConInsercion(kDistancias);
    if (cota > cota_inferior) {
      cota_inferior = cota;
      mejor_solucion = solucion_;
    }
    return;
  }
  if (kIndice >= kElementosProblema.first.size()) return;
  if (nodoAPodar(
      solucion_, kNumElementosEnSolucion - solucion_.size(), cota_inferior,
      calcularFuncionObjetivo(kDistancias), kDistanciasMinMax
    )
  ) return;  
  // Ramificación: incluir el punto actual en el conjunto
  solucion_.añadirNuevoElementoEIndice(kElementosProblema.first[kIndice], kElementosProblema.second[kIndice]);  
  ramificacionYPoda(
    kDistancias, kElementosProblema, kNumElementosEnSolucion,
    mejor_solucion, cota_inferior, kIndice + 1, kDistanciasMinMax
  );
  // Ramificación: no incluir el punto actual en el conjunto
  solucion_.eliminarUltimoElementoEIndice();
  ramificacionYPoda(
    kDistancias, kElementosProblema, kNumElementosEnSolucion,
    mejor_solucion, cota_inferior, kIndice + 1, kDistanciasMinMax
  );
}

/**
 * @brief Determina si un nodo del árbol de búsqueda debe ser podado según una cota inferior.
 *
 * @param kSolucionAExpandir Solución actual que se está expandiendo.
 * @param kNumRestoDeNodosFuturos Número de nodos restantes a expandir desde el nodo actual.
 * @param kCotaInferior Cota inferior actual del problema.
 * @param kFuncionObjetivo Función objetivo de la solución actual.
 * @param kDistanciasMinMax Lista ordenada de distancias mínimas y máximas.
 * @return true si se debe podar el nodo, false en caso contrario.
 */
bool RamificacionYPodaProfundidad::nodoAPodar(
  const Solucion& kSolucionAExpandir,
  const int kNumRestoDeNodosFuturos,
  const double kCotaInferior,
  const double kFuncionObjetivo,
  const std::vector<std::tuple<double, double, int>>& kDistanciasMinMax
) {
  const int kNumElementosEnSolucionActual = kSolucionAExpandir.size();
  const int kNumNodosTotales = kDistanciasMinMax.size();
  double sum = kFuncionObjetivo;
  int contador = 0;
  for (int i = 0; i < kNumNodosTotales; ++i) {
    bool nodo_existe_en_solucion = false;
    for (int j = 0; j < kNumElementosEnSolucionActual; ++j) {
      if (kSolucionAExpandir.getIndicesElementosIntroducidos()[j] == std::get<2>(kDistanciasMinMax[i])) {
        nodo_existe_en_solucion = true;
        break;
      }
    }
    if (!nodo_existe_en_solucion) {
      sum += std::get<1>(kDistanciasMinMax[i]);
      if (++contador == kNumRestoDeNodosFuturos) break;
    }
  }
  return (sum <= kCotaInferior) ? true : false;
}

/**
 * @brief Calcula las sumas de distancias mínimas y máximas para cada elemento de la matriz de distancias.
 *
 * @param kDistancias Matriz de distancias entre elementos.
 * @param kNumElementosEnSolucion Número de elementos en la solución deseada.
 * @return Vector de tuplas que contiene la suma de distancias mínimas y máximas para cada elemento.
 */
std::vector<std::tuple<double, double, int>> RamificacionYPodaProfundidad::calcularDistanciasMinMax(
  const Matriz& kDistancias,
  const int kNumElementosEnSolucion
) const {
  const int kFilas = kDistancias.size();
  std::vector<std::tuple<double, double, int>> min_max_distancias(kFilas);
  double sum_distancias_min, sum_distancias_max;
  for (int f = 0; f < kFilas; ++f) {
    std::vector<double> fila_ordenada_menor_mayor = kDistancias[f];
    std::sort(fila_ordenada_menor_mayor.begin(), fila_ordenada_menor_mayor.end());
    sum_distancias_min = 0.0;
    sum_distancias_max = 0.0;
    for (int c = 0, aux_c = 0; c < kNumElementosEnSolucion; ++c) {
      if (c >= f) aux_c = c + 1;
      else aux_c = c;
      sum_distancias_min += fila_ordenada_menor_mayor[aux_c];
      sum_distancias_max += fila_ordenada_menor_mayor[fila_ordenada_menor_mayor.size() - aux_c];
    }
    min_max_distancias[f] = std::make_tuple(sum_distancias_min, sum_distancias_max, f);
  }
  return min_max_distancias;
}