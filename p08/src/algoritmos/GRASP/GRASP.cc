/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 19 de Abril de 2024
 * @file GRASP.cc
 * @brief Implementación de la clase GRASP que hereda de AlgoritmosDiversidadMaxima
 * para resolver el problema de Maximum diversity problem.
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p08/src}
 */

#include "GRASP.h"

/**
 * @brief Ejecuta el algoritmo GRASP para resolver un problema dado.
 * 
 * @param kProblema El problema que se va a resolver.
 * @param kNumElementosEnSolucion El número de elementos en la solución generada por GRASP.
 * @param kIteraciones El número máximo de iteraciones para ejecutar el algoritmo GRASP.
 * @return La mejor solución encontrada por GRASP.
 */
Solucion GRASP::ejecutar(const Problema& kProblema, const int kNumElementosEnSolucion, const int kIteraciones) {  
  const Matriz& kCoordenadas = kProblema.getCoordenadas();
  const std::vector<int>& kInidcesProblema = kProblema.getIndicesProblema();
  std::pair<Matriz, std::vector<int>> elementos_problema(
    kCoordenadas, kInidcesProblema
  );  
  const std::vector<double> kMedidaCalidad = calcularMedidaCalidad(elementos_problema, kProblema.getDistancias());
  faseConstructiva(kProblema, elementos_problema, kNumElementosEnSolucion, kMedidaCalidad);
  Solucion mejor_solucion = solucion_;
  double mejor_funcion_objetivo = solucion_.getFuncionObjetivo();
  int iter = 0;
  while (++iter < kIteraciones) {
    std::pair<Matriz, std::vector<int>> elementos_problema(kCoordenadas, kInidcesProblema);
    faseConstructiva(kProblema, elementos_problema, kNumElementosEnSolucion, kMedidaCalidad);
    const double kFuncionObjetivoCadaIter = solucion_.getFuncionObjetivo();
    if (kFuncionObjetivoCadaIter > mejor_funcion_objetivo) {
      mejor_funcion_objetivo = kFuncionObjetivoCadaIter;
      mejor_solucion = solucion_;
    }
  }
  solucion_ = mejor_solucion;
  solucion_.setFuncionObjetivo() = mejor_funcion_objetivo;
  return solucion_;  
}

/**
 * @brief Realiza la fase constructiva de GRASP para construir una solución inicial.
 * 
 * @param kProblema El problema que se va a resolver.
 * @param elementos_problema Los elementos del problema con sus coordenadas e índices.
 * @param kNumElementosEnSolucion El número de elementos que debe tener la solución inicial.
 * @param kMedidaCalidad El vector que contiene la medida de calidad de cada elemento del problema.
 */
void GRASP::faseConstructiva(
  const Problema& kProblema,
  std::pair<Matriz, std::vector<int>>& elementos_problema,
  const int kNumElementosEnSolucion,
  const std::vector<double>& kMedidaCalidad
) {
  int numElementosEnSolucion = 0;
  const Matriz& kDistancias = kProblema.getDistancias();
  Solucion solucion_fase_constructiva;
  do {
    // Indices de elementos
    const std::vector<int> kLRC = calcularLRC(elementos_problema, kDistancias, kMedidaCalidad);
    const int kIndiceElemento = seleccionarAleatoriamenteElementoDeLRC(kLRC);
    solucion_fase_constructiva.añadirNuevoElementoEIndice(
      elementos_problema.first[kIndiceElemento], elementos_problema.second[kIndiceElemento]
    );
    elementos_problema.first.eliminarElemento(kIndiceElemento);
    elementos_problema.second.erase(elementos_problema.second.begin() + kIndiceElemento);    
  } while (++numElementosEnSolucion < kNumElementosEnSolucion);
  solucion_ = solucion_fase_constructiva;
  calcularFuncionObjetivo(kDistancias);
}

/**
 * @brief Calcula la lista restringida de candidatos (LRC) basada en la medida de calidad
 *        de los elementos del problema.
 * 
 * @param kElementosProblema Los elementos del problema con sus coordenadas e índices.
 * @param kDistancias La matriz de distancias entre los elementos del problema.
 * @param kMedidaCalidad El vector que contiene la medida de calidad de cada elemento del problema.
 * @return La lista restringida de candidatos (LRC).
 */
std::vector<int> GRASP::calcularLRC(
  const std::pair<Matriz, std::vector<int>>& kElementosProblema,
  const Matriz& kDistancias,
  const std::vector<double>& kMedidaCalidad
) const {
  std::vector<int> indicesNoSeleccionados(kElementosProblema.second.size());
  std::iota(indicesNoSeleccionados.begin(), indicesNoSeleccionados.end(), 0);
  std::sort(indicesNoSeleccionados.begin(), indicesNoSeleccionados.end(), [&](int a, int b) { 
    return kMedidaCalidad[a] > kMedidaCalidad[b]; 
  });
  const double kAlpha = 0.5;
  const int kLRCSize = kAlpha * indicesNoSeleccionados.size();
  std::vector<int> LRC(indicesNoSeleccionados.begin(), indicesNoSeleccionados.begin() + kLRCSize);
  return LRC;
}

/**
 * @brief Calcula la medida de calidad para cada elemento del problema en base a las distancias.
 * 
 * @param kElementosProblema Los elementos del problema con sus coordenadas e índices.
 * @param kDistancias La matriz de distancias entre los elementos del problema.
 * @return Un vector que contiene la medida de calidad de cada elemento del problema.
 */
std::vector<double> GRASP::calcularMedidaCalidad(
  const std::pair<Matriz, std::vector<int>>& kElementosProblema,
  const Matriz& kDistancias
) const {
  const int kNumIndices = kElementosProblema.second.size();
  const int kNumPuntosTotales = kDistancias.size();
  std::vector<double> diversidadPuntosRestantes(kNumIndices);
  for (int i = 0; i < kNumIndices; ++i) {
    double suma_distancias = 0.0;
    for (int j = 0; j < kNumPuntosTotales; ++j) {
      if (kElementosProblema.second[i] == j) continue;
      suma_distancias += kDistancias[kElementosProblema.second[i]][j];
    }
    diversidadPuntosRestantes[i] = (suma_distancias / (kNumPuntosTotales - 1));
  }
  return diversidadPuntosRestantes;
}

/**
 * @brief Selecciona aleatoriamente un elemento de la lista restringida de candidatos (LRC).
 * 
 * @param kLRC La lista restringida de candidatos (LRC) de donde se seleccionará el elemento.
 * @return El índice del elemento seleccionado aleatoriamente de la LRC.
 */
const int GRASP::seleccionarAleatoriamenteElementoDeLRC(const std::vector<int>& kLRC) const {
  std::random_device dispositivo_aleatorio;
  std::mt19937 generador(dispositivo_aleatorio());  
  std::uniform_int_distribution<> dis(0, kLRC.size() - 1);
  return kLRC[dis(generador)];
}