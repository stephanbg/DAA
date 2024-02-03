/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 *
 * @author Stephan Brommer Gutiérrez
 * Correo: alu0101493497@ull.edu.es
 * @date 30/01/2024
 * @file multiplicar_matriz.h
 * @brief Contiene la definición de la clase MultiplicarMatriz, la cuál
 *        es una clase abstracta que se encarga de realizar la operación multiplicar
 *        que será sobreescrita por todas sus clases derivadas para realizar cualquier
 *        variante del algoritmo de multiplicación
 * @see {@link https://github.com/stephanbg/DAA}
 *
 */

#pragma once

#include "matriz.h"

/**
 * @brief Clase MultiplicarMatriz
 *        Clase base (abstracta) que contiene un método virtual puro para ser
 *        sobreescrito por las clases derivadas
 */
class MultiplicarMatriz {
 public:
  virtual Matriz Multiplicar(const Matriz&, const Matriz&) const = 0;
  virtual ~MultiplicarMatriz() {} /// Destructor virtual
};