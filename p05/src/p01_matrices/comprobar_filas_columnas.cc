/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 *
 * @author Stephan Brommer Gutiérrez
 * Correo: alu0101493497@ull.edu.es
 * @date 30/01/2024
 * @file comprobar_filas_columnas.cc
 * @brief Contiene la implementación de la clase ComprobarFilasYColumnas, la cuál
 *        se encargará de comprobar la compatibilidad entre dos matrices para
 *        sus posteriores operaciones 
 * @see {@link https://github.com/stephanbg/DAA}
 *
 */

#include "comprobar_filas_columnas.h"

/**
 * @brief Comprueba si dos matrices son compatibles para poder multiplicarlas entre si,
 *        es decir, la cantidad de columnas de la primera deben ser igual a la cantidad de filas
 *        de la segunda
 * @param[in] kMatriz1 referencia (constante) de la primera matriz
 * @param[in] kMatriz2 referencia (constante) de la segunda matriz
 * @returns EXIT_SUCCESS si coincide la cantidad de columnas de la primera matriz y
 *          la cantidad de filas de la segunda, EXIT_FAILURE en caso contrario.
 */
bool ComprobarFilasYColumnas::ComprobarErrorEnSize(const Matriz& kMatriz1, const Matriz& kMatriz2) {
  if (kMatriz1.get_matriz()[0].size() == kMatriz2.get_matriz().size()) return EXIT_SUCCESS;
  return EXIT_FAILURE;
}