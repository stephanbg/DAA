/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Marzo de 2024
 * @file fuerza_bruta_tsp.cc
 * @brief Implementación de la clase FuerzaBrutaTSP que hereda de la clase TSP
 * para resolver dicho problema
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p06/src}
 * @see {@link https://docs.google.com/document/d/1a691HPtHQL4qBtI2qaTMTp23wxZvU8-CCIbGOyNJRQo/edit}
 */

#include "fuerza_bruta_tsp.h"

/**
 * @brief Ejecuta el algoritmo de fuerza bruta para resolver el Problema del Viajante de Comercio.
 * 
 * @param grafo Grafo no dirigido completo que representa el problema del viajante de comercio.
 */
void FuerzaBrutaTSP::ejecutar(const GrafoNoDirigidoCompleto& grafo) {
  auto ini = Clock::now();
  const std::vector<Nodo*>& nodos = grafo.getGrafo();
  std::vector<int> indices(nodos.size());
  std::iota(indices.begin(), indices.end(), 0); // Inicializa los índices con 0, 1, 2, ..., n-1
  long double mejor_coste = -1;
  int indice_actual, indice_siguiente;
  std::vector<int> mejor_permutacion;
  do {
    if (ControlTiempo::tiempoTranscurrido(ini, Clock::now())) {
      tiempoEjecucion_ = -1;
      const int kSizeMejorPermutacion = mejor_permutacion.size();
      for (int i = 0; i < kSizeMejorPermutacion; ++i) {
        caminoMinimo_.push_back(nodos[mejor_permutacion[i]]);
      }
      caminoMinimo_.push_back(nodos[mejor_permutacion.front()]);      
      coste_ = mejor_coste;
      return;  
    }   
    long double coste_actual = 0.0;
    for (int i = 0; i < indices.size() - 1; ++i) {
      indice_actual = indices[i];
      indice_siguiente = indices[i + 1];
      // Calcula el coste de pasar de un nodo al siguiente
      // Suma el peso de la arista entre estos nodos al coste actual
      for (const auto& a : nodos[indice_actual]->getNodosVecinos()) {
        if (a.getNodoDestino() == nodos[indice_siguiente]) {
          coste_actual += a.getPeso();
          break;
        }
      }
    }
    // Añade el coste de volver al nodo inicial
    for (const auto& a : nodos[indices.back()]->getNodosVecinos()) {
      if (a.getNodoDestino() == nodos[indices.front()]) {
        coste_actual += a.getPeso();
        break;
      }
    }
    // Comprueba si el coste actual es mejor que el mejor coste encontrado hasta ahora
    if (mejor_coste == -1 || coste_actual < mejor_coste) {
      mejor_coste = coste_actual;
      mejor_permutacion = indices;
    }
  } while (std::next_permutation(indices.begin() + 1, indices.end())); // Genera la siguiente permutación
  // Construye el camino mínimo a partir de la mejor permutación encontrada
  const int kSizeMejorPermutacion = mejor_permutacion.size();
  for (int i = 0; i < kSizeMejorPermutacion; ++i) {
    caminoMinimo_.push_back(nodos[mejor_permutacion[i]]);
  }
  // Añade el nodo origen
  caminoMinimo_.push_back(nodos[mejor_permutacion.front()]);
  auto fin = Clock::now();
  tiempoEjecucion_ = std::chrono::duration_cast<std::chrono::microseconds>(fin - ini).count();
  coste_ = mejor_coste;
}

/**
 * @brief Muestra el camino mínimo
 * 
 */
void FuerzaBrutaTSP::mostrarCaminoMinimo() const {
  std::cout << "Camino mínimo para algoritmo Fuerza Bruta\n";
  std::cout << "-----------------------------------------" << std::endl;
  const int kSizeCaminoMinimo = caminoMinimo_.size();
  for (int i = 0; i < kSizeCaminoMinimo; ++i) {
    std::cout << caminoMinimo_[i]->getId();
    if (i < kSizeCaminoMinimo - 1) std::cout << " -> ";
  }
  std::cout << std::endl;
}

/**
 * @brief Muestra el tiempo de ejecución
 * 
 */
void FuerzaBrutaTSP::mostrarTiempoEjecución() const {
  std::cout << "Tiempo de ejecución para algoritmo Fuerza Bruta\n";
  std::cout << "-----------------------------------------------" << std::endl;
  std::cout << tiempoEjecucion_ << " µs" << std::endl;
}