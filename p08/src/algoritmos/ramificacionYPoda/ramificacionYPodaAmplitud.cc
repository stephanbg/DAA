/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 2 de Abril de 2024
 * @file ramificacionYPodaAmplitud.cc
 * @brief Implementación de la clase RamificacionYPodaAmplitud que hereda de AlgoritmosDiversidadMaxima
 * para resolver el problema de Maximum diversity problem.
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p08/src}
 */

#include "ramificacionYPodaAmplitud.h"

/**
 * @brief Ejecuta el algoritmo de Ramificación y Poda con búsqueda en amplitud para resolver el problema.
 * Expandiendo el nodo con cota superior más pequeña
 *
 * @param kProblema El problema a resolver.
 * @param kNumElementosEnSolucion Número de elementos en la solución deseada.
 * @param kIteraciones Número de iteraciones o pasos del algoritmo.
 * @return La mejor solución encontrada.
 */
Solucion RamificacionYPodaAmplitud::ejecutar(
  const Problema& kProblema, const int kNumElementosEnSolucion, const int kIteraciones
) {  
  const Matriz& kDistancias = kProblema.getDistancias();
  GRASP algortimo;
  solucion_ = algortimo.ejecutar(kProblema, kNumElementosEnSolucion, kIteraciones);
  Solucion mejor_solucion = solucion_;
  double cota_inferior = mejor_solucion.getFuncionObjetivo();
  const std::pair<Matriz, std::vector<int>>& kElementosProblema = std::make_pair(
    kProblema.getCoordenadas(), kProblema.getIndicesProblema()
  );  
  ramificacionYPoda(kDistancias, kElementosProblema, kNumElementosEnSolucion, mejor_solucion, cota_inferior);
  return solucion_;
}

/**
 * @brief Implementa el algoritmo de Ramificación y Poda con búsqueda en amplitud
 * para explorar el espacio de soluciones.
 *
 * @param kDistancias Matriz de distancias entre elementos.
 * @param kElementosProblema Elementos del problema (coordenadas y sus índices).
 * @param kNumElementosEnSolucion Número de elementos en la solución deseada.
 * @param mejor_solucion La mejor solución encontrada hasta el momento.
 * @param cota_inferior Cota inferior actual para el problema.
 */
void RamificacionYPodaAmplitud::ramificacionYPoda(
  const Matriz& kDistancias, const std::pair<Matriz, std::vector<int>>& kElementosProblema,
  const int kNumElementosEnSolucion, Solucion& mejor_solucion, double& cota_inferior
) {
  // Calculo dis min y max
  std::vector<std::tuple<double, double, int>> distancias_min_max = calcularDistanciasMinMax(kDistancias, kNumElementosEnSolucion);
  std::sort(distancias_min_max.begin(), distancias_min_max.end(),
            [](const auto& a, const auto& b) {
              return std::get<1>(a) > std::get<1>(b);
            });
  auto comparador = [](const auto& a, const auto& b) {
    return a.second > b.second;
  };   
  // Cola que ordena los nodos hojas de menor a mayor cota         
  std::priority_queue<std::pair<Solucion, double>,
                      std::vector<std::pair<Solucion, double>>,
                      decltype(comparador)> cola(comparador);
  const int kNumElementosProblema = kElementosProblema.first.size(); 
  int cantidad_hijos_a_generar = kNumElementosProblema - kNumElementosEnSolucion + 1; // n - m + 1
  std::pair<Solucion, double> solucion_parcial;
  // Creo el primer nivel si no hay que podar
  if (!nodoAPodar(solucion_parcial.first, kNumElementosEnSolucion, cota_inferior, 0.0, distancias_min_max)) {  
    for (int i = 0; i < cantidad_hijos_a_generar; ++i) { // Primer nivel
      solucion_parcial.first = Solucion{};
      solucion_parcial.first.añadirNuevoElementoEIndice(kElementosProblema.first[i], kElementosProblema.second[i]);
      cola.push(std::make_pair(solucion_parcial.first, 0.0));
    }
  }
  int nivel;
  while (!cola.empty()) {
    solucion_parcial = cola.top();
    cola.pop();
    nivel = solucion_parcial.first.size();
    // Creo los hijos de cada nodo si no hay que podar
    if (nodoAPodar(
        solucion_parcial.first,
        kNumElementosEnSolucion - nivel,
        cota_inferior,
        solucion_parcial.second,
        distancias_min_max
      )
    ) continue;    
    for (
      int i = solucion_parcial.first.getIndicesElementosIntroducidos()[nivel - 1] + 1;
      (i < kNumElementosProblema && nivel < kNumElementosEnSolucion);
      ++i
    ) {
      solucion_ = solucion_parcial.first;
      solucion_.añadirNuevoElementoEIndice(kElementosProblema.first[i], kElementosProblema.second[i]);
      // Si se alcanza solución completa revisar si hay que actualizar cota
      if (solucion_.size() == kNumElementosEnSolucion) {
        double cota = calcularFuncionObjetivoParcialConInsercion(kDistancias);
        if (cota > cota_inferior) {
          mejor_solucion = solucion_;
          cota_inferior = cota;
        }
      }
      cola.push(std::make_pair(solucion_, calcularFuncionObjetivoParcialConInsercion(kDistancias)));
    }
  }
  solucion_ = mejor_solucion;
  solucion_.setFuncionObjetivo() = cota_inferior;
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
bool RamificacionYPodaAmplitud::nodoAPodar(
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
  return (sum < kCotaInferior) ? true : false;
}

/**
 * @brief Calcula las sumas de distancias mínimas y máximas para cada elemento de la matriz de distancias.
 *
 * @param kDistancias Matriz de distancias entre elementos.
 * @param kNumElementosEnSolucion Número de elementos en la solución deseada.
 * @return Vector de tuplas que contiene la suma de distancias mínimas y máximas para cada elemento.
 */
std::vector<std::tuple<double, double, int>> RamificacionYPodaAmplitud::calcularDistanciasMinMax(
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

/**
 * @brief Obtiene los elementos del problema que no están incluidos en la mejor solución.
 *
 * @param kProblema El problema del cual se obtendrán los elementos.
 * @param kMejorSolucion La mejor solución actual del problema.
 * @return Un par que contiene una matriz de coordenadas de elementos y un vector de índices
 * de elementos que están fuera de la solución.
 */
std::pair<Matriz, std::vector<int>> RamificacionYPodaAmplitud::obtenerElementosFueraDeSolucion(
  const Problema& kProblema,
  const Solucion& kMejorSolucion
) const {
  Matriz cada_elemento_matriz;
  std::vector<int> cada_elemento_indice;
  const std::vector<int>& kIndicesIntroducidos = kMejorSolucion.getIndicesElementosIntroducidos();
  const int kSizeIndicesEnSolucion = kIndicesIntroducidos.size();
  for (const int& kIndiceProblema : kProblema.getIndicesProblema()) {
    bool esta_en_solucion = false;
    for (int i = 0; i < kSizeIndicesEnSolucion; ++i) {
      if (kIndicesIntroducidos[i] == kIndiceProblema) {
        esta_en_solucion = true;
        break;
      }
    }
    if (!esta_en_solucion) {
      cada_elemento_matriz.setMatriz().push_back(kProblema.getCoordenadas()[kIndiceProblema]);
      cada_elemento_indice.push_back(kIndiceProblema);
    }
  }
  return std::make_pair(cada_elemento_matriz, cada_elemento_indice);
}