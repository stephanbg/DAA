/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 *
 * @author Stephan Brommer Gutiérrez
 * Correo: alu0101493497@ull.edu.es
 * @date 30/01/2024
 * @file comprobar_filas_columnas.h
 * @brief Contiene la definición de la clase ComprobarFilasYColumnas, la cuál
 *        se encargará de comprobar la compatibilidad entre dos matrices para
 *        sus posteriores operaciones 
 * @see {@link https://github.com/stephanbg/DAA}
 *
 */

#pragma once

#include <cstdlib>

#include "matriz.h"

/**
 * @brief Clase ComprobarFilasYColumnas
 *        Se encarga de comprobar si la las dos matrices son compatibles para su posterior
 *        multiplicación
 */
class ComprobarFilasYColumnas {
 public:
  bool ComprobarErrorEnSize(const Matriz&, const Matriz&);
};