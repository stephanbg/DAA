/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 27 de Febrero de 2024
 * @file solucion-vectorial.cc
 * @brief Implementación de la clase SolucionVectorial, que representa
 * la solución vectorial a cualquier problema de DyV, clase hija de
 * la clase abstracta Solucion
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p04/src}
 * @see {@link https://docs.google.com/document/d/1CcrG-85_oTdAkTo-zgXkudKT8C8z7T7m2hUHVLGUReQ/edit#heading=h.5bq8rsdy1ujx}
 */

#include "solucion-vectorial.h"

/**
 * @brief Muestra la solución a un problema vectorial
 */
void SolucionVectorial::mostrarSolucion() const {
  std::cout << "{ ";
  const int kSize = size();
  for (int i = 0; i < kSize; ++i) {
    std::cout << getSolucion()[i];
    if (i < kSize - 1) std::cout << ", ";
  }
  std::cout << " }";
}