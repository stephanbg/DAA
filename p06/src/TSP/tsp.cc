/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Marzo de 2024
 * @file tsp.cc
 * @brief Implementación de la clase abstracta TSP
 * que servirá de clase base para todos los tipso de algoritmos para resolver el TSP
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p06/src}
 * @see {@link https://docs.google.com/document/d/1a691HPtHQL4qBtI2qaTMTp23wxZvU8-CCIbGOyNJRQo/edit}
 */

#include "tsp.h"

/**
 * @brief Calcula el coste total del camino mínimo.
 * 
 * Este método calcula el coste total del camino mínimo almacenado en la instancia del TSP.
 * Itera sobre los nodos del camino mínimo y suma el coste de las aristas entre nodos adyacentes.
 * 
 * @return El coste total del camino mínimo.
 */
const long double TSP::calcularCoste() {
  coste_ = 0.0;
  for (int i = 0; i < caminoMinimo_.size() - 1; ++i) {
    const Nodo* nodo_actual = caminoMinimo_[i];
    const Nodo* nodo_siguiente = caminoMinimo_[i + 1];
    coste_ += nodo_actual->getCoste(nodo_siguiente);
    const auto& vecinos = nodo_actual->getNodosVecinos();
  }
  return coste_;
}

/**
 * @brief Muestra el coste del camino
 * 
 */
void TSP::mostrarCoste() {
  std::cout << "Coste del camino mínimo:\n";
  std::cout << "------------------------\n";
  std::cout << coste_ << std::endl;
}