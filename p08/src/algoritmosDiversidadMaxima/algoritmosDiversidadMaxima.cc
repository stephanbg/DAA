/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 19 de Abril de 2024
 * @file algoritmosDiversidadMaxima.cc
 * @brief Implementación de la clase abstracta AlgoritmosDiversidadMaxima
 * para resolver el problema de Maximum diversity problem.
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p08/src}
 */

#include "algoritmosDiversidadMaxima.h"

/**
 * @brief Calcula el centro de gravedad de un conjunto de coordenadas.
 * 
 * @param kCoordenadas La matriz de coordenadas de los elementos.
 * @return Un vector que representa el centro de gravedad.
 */
const std::vector<double> AlgoritmosDiversidadMaxima::calcularCentroGravedad(
  const Matriz& kCoordenadas
) const {
  const int kNumElementos = kCoordenadas.getMatriz().size();
  const int kNumDimensiones = kCoordenadas.getMatriz()[0].size();
  std::vector<double> coordenadas_centro_gravedad(kNumDimensiones);
  double sumatorio_coordenadas;
  for (int columna = 0; columna < kNumDimensiones; ++columna) {
    sumatorio_coordenadas = 0.0;
    for (int fila = 0; fila < kNumElementos; ++fila) {
      sumatorio_coordenadas += kCoordenadas[fila][columna];
    }
    coordenadas_centro_gravedad[columna] = (sumatorio_coordenadas / kNumElementos);
  }
  return coordenadas_centro_gravedad;
}

/**
 * @brief Obtiene el elemento más alejado del centro de gravedad de un conjunto de elementos.
 * 
 * @param kCentroGravedad El centro de gravedad calculado previamente.
 * @param kElementosRestantes La matriz de elementos restantes.
 * @return Un par que contiene el elemento más alejado y su índice.
 */
const std::pair<std::vector<double>, int>
AlgoritmosDiversidadMaxima::obtenerElementoEIndiceFicticioMasAlejadoDeCentroGravedad(
  const std::vector<double>& kCentroGravedad,
  const Matriz& kElementosRestantes
) const {
  std::pair<std::vector<double>, int> elemento_mas_lejano;
  const int kNumDimensiones = kElementosRestantes[0].size();
  const int kSizeElementosRestantes = kElementosRestantes.size();
  double mayor_distancia_euclidiana = 0.0, cada_distancia_euclidiana;
  // Compruebo cuál es el más lejano
  for (int fila = 0; fila < kSizeElementosRestantes; ++fila) {
    cada_distancia_euclidiana = 0.0;
    for (int indice_dimension = 0; indice_dimension < kNumDimensiones; ++indice_dimension) {
      cada_distancia_euclidiana += (
        (kElementosRestantes[fila][indice_dimension] - kCentroGravedad[indice_dimension]) *
        (kElementosRestantes[fila][indice_dimension] - kCentroGravedad[indice_dimension])
      );
    }
    cada_distancia_euclidiana = sqrt(cada_distancia_euclidiana);
    if (fila == 0 || cada_distancia_euclidiana > mayor_distancia_euclidiana) {
      mayor_distancia_euclidiana = cada_distancia_euclidiana;
      elemento_mas_lejano.first = kElementosRestantes[fila];
      elemento_mas_lejano.second = fila;
    }
  }
  return elemento_mas_lejano;
}

/**
 * @brief Calcula la función objetivo de la solución actual.
 * 
 * @param kDistancias La matriz de distancias entre elementos.
 * @return El valor de la función objetivo.
 */
const double AlgoritmosDiversidadMaxima::calcularFuncionObjetivo(const Matriz& kDistancias) {
  double& funcion_objetivo = solucion_.setFuncionObjetivo();
  funcion_objetivo = 0;
  const std::vector<int>& kIndices = solucion_.getIndicesElementosIntroducidos();
  const int kSizeIndices = kIndices.size();
  for (int i = 0; i < kSizeIndices; ++i) {
    for (int j = i + 1; j < kSizeIndices; ++j) {
      funcion_objetivo += kDistancias[kIndices[i]][kIndices[j]];
    }
  }
  return funcion_objetivo;
}

/**
 * @brief Calcula la función objetivo parcial después de la inserción de un nuevo elemento en la solución.
 * 
 * @param kSolucionInicial La solución inicial antes de la inserción.
 * @param kIndiceElementoIntroducido El índice del elemento introducido en la solución.
 * @param kDistancias La matriz de distancias entre elementos.
 * @return El valor de la función objetivo parcial.
 */
const double AlgoritmosDiversidadMaxima::calcularFuncionObjetivoParcial(
  const Solucion& kSolucionInicial,
  const int kIndiceElementoIntroducido,
  const Matriz& kDistancias
) {
  // Restar antes y Sumar Despues
  const int kSizeSolucion = solucion_.size();
  double& funcion_objetivo = solucion_.setFuncionObjetivo(); 
  const std::vector<int>& kIndicesAntes = kSolucionInicial.getIndicesElementosIntroducidos();
  const std::vector<int>& kIndicesDespues = solucion_.getIndicesElementosIntroducidos();
  for (int i = 0; i < kSizeSolucion; ++i) {
    if (i == kIndiceElementoIntroducido) continue;
    funcion_objetivo -= kDistancias[kIndicesAntes[kIndiceElementoIntroducido]][kIndicesAntes[i]];
    funcion_objetivo += kDistancias[kIndicesDespues[kIndiceElementoIntroducido]][kIndicesDespues[i]];
  }
  return funcion_objetivo;
}