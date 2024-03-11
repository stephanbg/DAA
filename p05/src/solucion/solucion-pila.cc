/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 6 de marzo de 2024
 * @file solucion-pila.cc
 * @brief Implementación de la clase SolucionPila, que representa
 * la solución a cualquier problema de Pilas
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p05/src}
 * @see {@link https://docs.google.com/document/d/1pwPk5iI5dRHo8M-raauPP5mgCUHy9m9j_au3UDkn_Rc/edit}
 */

#include "solucion-pila.h"

/**
 * @brief Muetsra la solución al problema de pilas
 */
void SolucionPila::mostrarSolucion() const {
  std::stack<int> destino = pila_;
  std::cout << "PILA SOLUCION\n";
  while (!destino.empty()) {
    int pila_top = destino.top();
    std::cout << pila_top << std::endl;
    destino.pop();
  }
}