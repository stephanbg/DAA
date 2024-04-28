/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 19 de Abril de 2024
 * @file voraz.cc
 * @brief Implementación de la clase Voraz que hereda de AlgoritmosDiversidadMaxima
 * para resolver el problema de Maximum diversity problem.
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p08/src}
 */

#include "voraz.h"

/**
 * @brief Ejecuta el algoritmo voraz para resolver el problema.
 * 
 * @param kProblema El problema a resolver.
 * @param kNumElementosEnSolucion El número de elementos a seleccionar en la solución.
 * @return La solución obtenida por el algoritmo voraz.
 */
Solucion Voraz::ejecutar(const Problema& kProblema, const int kNumElementosEnSolucion, const int kIteraciones) {
  std::pair<Matriz, std::vector<int>> elementos_problema(
    kProblema.getCoordenadas(), kProblema.getIndicesProblema()
  );
  faseConstructiva(kProblema, elementos_problema, kNumElementosEnSolucion);
  busquedaLocal(kProblema, elementos_problema);
  return solucion_;
}

/**
 * @brief Realiza la fase constructiva del algoritmo voraz.
 * 
 * @param kProblema El problema a resolver.
 * @param elementos_problema Los elementos del problema utilizados durante la fase constructiva.
 * @param kNumElementosEnSolucion El número de elementos a seleccionar en la solución.
 */
void Voraz::faseConstructiva(
  const Problema& kProblema,
  std::pair<Matriz, std::vector<int>>& elementos_problema,
  const int kNumElementosEnSolucion
) {
  // Variables
  Matriz& solucion_coordenadas = solucion_.setCoordenadas();
  // Algoritmo
  std::vector<double> centro_gravedad = calcularCentroGravedad(elementos_problema.first);
  do {
    const std::pair<std::vector<double>, int> kElementoMasLejanoEIndiceFicticio = (
      obtenerElementoEIndiceFicticioMasAlejadoDeCentroGravedad(centro_gravedad, elementos_problema.first)
    );
    solucion_.añadirNuevoElementoEIndice(
      kElementoMasLejanoEIndiceFicticio.first, elementos_problema.second[kElementoMasLejanoEIndiceFicticio.second]
    );
    elementos_problema.first.eliminarElemento(kElementoMasLejanoEIndiceFicticio.second);
    elementos_problema.second.erase(elementos_problema.second.begin() + kElementoMasLejanoEIndiceFicticio.second);
    centro_gravedad = calcularCentroGravedad(solucion_coordenadas);   
  } while (solucion_coordenadas.size() != kNumElementosEnSolucion);
  calcularFuncionObjetivo(kProblema.getDistancias());
}

/**
 * @brief Realiza la fase de búsqueda local del algoritmo voraz.
 * 
 * @param kProblema El problema a resolver.
 * @param kElementosRestantes Los elementos del problema que quedan por explorar después de la fase constructiva.
 */
void Voraz::busquedaLocal(
  const Problema& kProblema,
  const std::pair<Matriz, std::vector<int>>& kElementosRestantes
) {
  // Variables
  Solucion mejor_solucion = solucion_;
  const Solucion kSolucionInicial = mejor_solucion;
  const Matriz& kDistancias = kProblema.getDistancias();
  const int kSizeElementosRestantes = kElementosRestantes.first.size();
  const int kSizeElementosSolucion = solucion_.size();
  double mejor_funcion_objetivo = solucion_.getFuncionObjetivo(), funcion_objetivo_actual;
  // Empieza algoritmo
  for (int i = 0; i < kSizeElementosSolucion; ++i) {
    for (int j = 0; j < kSizeElementosRestantes; ++j) {
      solucion_ = kSolucionInicial;
      solucion_.insertarNuevoPuntoEIndice(i, kElementosRestantes.first[j], kElementosRestantes.second[j]);
      funcion_objetivo_actual = calcularFuncionObjetivoParcial(kSolucionInicial, i, kDistancias);
      if (mejor_funcion_objetivo < funcion_objetivo_actual) {   
        mejor_funcion_objetivo = funcion_objetivo_actual;
        mejor_solucion = solucion_;
      }
    }
  }
  solucion_ = mejor_solucion;
  solucion_.setFuncionObjetivo() = mejor_funcion_objetivo;
}