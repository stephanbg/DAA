/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 *
 * @author Stephan Brommer Gutiérrez
 * Correo: alu0101493497@ull.edu.es
 * @date 30/01/2024
 * @file matriz.h
 * @brief Contiene la definición de la clase Matriz, la cuál
 *        se encargará de crear cualquier instancia de una matriz
 *        de manera random, o a través de un vector de vectores que
 *        contenga los datos
 * @see {@link https://github.com/stephanbg/DAA}
 *
 */

#pragma once

#include <iostream>
#include <vector>

/**
 * @brief Clase Matriz
 *        Se encarga de crear instancias de matrices random o pasandole vector de vectores
 */
class Matriz {
  public:
    Matriz();
    Matriz(const std::vector<std::vector<long int>>& kMatriz) : matriz_(kMatriz) {}
    const std::vector<std::vector<long int>>& get_matriz() const { return matriz_; }
    friend std::ostream& operator<<(std::ostream&, const Matriz&);
  private:
    std::vector<std::vector<long int>> matriz_{};
};