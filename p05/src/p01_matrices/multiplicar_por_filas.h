/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 *
 * @author Stephan Brommer Gutiérrez
 * Correo: alu0101493497@ull.edu.es
 * @date 30/01/2024
 * @file multiplicar_por_filas.h
 * @brief Contiene la definición de la clase MultiplicarPorFilas, es la clase derivada
 *        de la clase abstracta MultiplicarMatriz, esta sobreescribe el algoritmo de 
 *        multiplicar matrices, para multiplicar matrices por filas
 * @see {@link https://github.com/stephanbg/DAA}
 *
 */

#pragma once

#include "multiplicar_matriz.h"

/**
 * @brief Clase MultiplicarPorFilas
 *        Clase derivada de la clase abstracta MultiplicarMatriz,
 *        sobreescribe el algoritmo de multiplicar matrices, y realiza
 *        la multiplicación por filas
 */
class MultiplicarPorFilas : public MultiplicarMatriz {
 public:
  Matriz Multiplicar(const Matriz&, const Matriz&) const override;
};