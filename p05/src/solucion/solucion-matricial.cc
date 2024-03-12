/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 6 de marzo de 2024
 * @file solucion-matricial.cc
 * @brief Implementación de la clase SolucionMatricial, que representa
 * la solución a cualquier problema de Matrices
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p05/src}
 * @see {@link https://docs.google.com/document/d/1pwPk5iI5dRHo8M-raauPP5mgCUHy9m9j_au3UDkn_Rc/edit}
 */

#include "solucion-matricial.h"

/**
 * @brief Construye una solucion vacía con tamaño fila columnas
 * @param kFilas filas de la solución
 * @param kColumnas columnas de la solución
 */
SolucionMatricial::SolucionMatricial(const int kFilas, const int kColumnas) {
  solucion_.resize(kFilas, std::vector<int>(kColumnas, 0));
}

/**
 * @brief Muetsra la solución matricial
 */
void SolucionMatricial::mostrarSolucion() const {
  std::cout << "MATRIZ SOLUCIÓN: " << std::endl;
  for (const auto& fila : solucion_) {
    for (const auto& elemento : fila) {
      std::cout << elemento << " ";
    }
    std::cout << std::endl;
  }
}