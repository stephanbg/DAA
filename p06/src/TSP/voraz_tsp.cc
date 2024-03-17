/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Marzo de 2024
 * @file voraz_tsp.cc
 * @brief Implementación de la clase VorazTSP que hereda de la clase TSP
 * para resolver dicho problema
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p06/src}
 * @see {@link https://docs.google.com/document/d/1a691HPtHQL4qBtI2qaTMTp23wxZvU8-CCIbGOyNJRQo/edit}
 */

#include "voraz_tsp.h"

/**
 * @brief Ejecuta el algoritmo voraz para resolver el Problema del Viajante de Comercio.
 * 
 * @param grafo Grafo no dirigido completo que representa el problema del viajante de comercio.
 */
void VorazTSP::ejecutar(const GrafoNoDirigidoCompleto& grafo) {
  auto ini = Clock::now();
  std::vector<bool> visitados(grafo.getGrafo().size(), false);
  int indice_nodo_actual = 0, indice_vecino;
  const Nodo* cada_nodo_ini = grafo.getGrafo()[indice_nodo_actual];
  const Nodo* nodoDestino;
  long double mejor_peso_destino;
  caminoMinimo_.push_back(cada_nodo_ini);
  visitados[indice_nodo_actual] = true;
  do {
    if (ControlTiempo::tiempoTranscurrido(ini, Clock::now())) {
      tiempoEjecucion_ = -1;
      calcularCoste();
      return;  
    }
    mejor_peso_destino = std::numeric_limits<long double>::infinity();
    // Recorro todos los vecinos buscando el mejor no visitado
    for (const auto& vecino : cada_nodo_ini->getNodosVecinos()) {
      indice_vecino = grafo.getIndiceNodo(vecino.getNodoDestino()->getId());
      if (!(visitados[indice_vecino]) && (vecino.getPeso() < mejor_peso_destino)) {
        nodoDestino = vecino.getNodoDestino();
        mejor_peso_destino = vecino.getPeso();
      }
    }
    // El nuevo nodo es el vecino
    cada_nodo_ini = nodoDestino;
    caminoMinimo_.push_back(cada_nodo_ini); // Lo añado al camino mínimo
    indice_nodo_actual = grafo.getIndiceNodo(cada_nodo_ini->getId());
    visitados[indice_nodo_actual] = true; // Lo marco ha visitado (vecino)
  } while (contieneFalso(visitados));
  caminoMinimo_.push_back(grafo.getGrafo()[0]);
  auto fin = Clock::now();
  tiempoEjecucion_ = (std::chrono::duration_cast<std::chrono::microseconds>(fin - ini)).count();
  calcularCoste();
}

/**
 * @brief Muestra el camino mínimo
 * 
 */
void VorazTSP::mostrarCaminoMinimo() const {
  std::cout << "Camino mínimo para algoritmo Voraz\n";
  std::cout << "----------------------------------" << std::endl;
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
void VorazTSP::mostrarTiempoEjecución() const {
  std::cout << "Tiempo de ejecución para algoritmo Voraz\n";
  std::cout << "----------------------------------------" << std::endl;
  std::cout << tiempoEjecucion_ << " µs" << std::endl;
}