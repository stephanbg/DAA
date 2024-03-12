/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 *
 * @author Stephan Brommer Gutiérrez
 * Correo: alu0101493497@ull.edu.es
 * @date 30/01/2024
 * @file matriz.cc
 * @brief Contiene la implementación de la clase Matriz, la cuál
 *        se encargará de crear cualquier instancia de una matriz
 *        de manera random, o a través de un vector de vectores que
 *        contenga los datos
 * @see {@link https://github.com/stephanbg/DAA}
 *
 */

#include "matriz.h"
#include "funciones_necesarias.h"

/**
 * @brief Constructor de la clase Matriz, genera matrices de filas y columnas aleatorias
 *        en el rango (1-100) y las casillas contendrán valores del (0-99)
 */
Matriz::Matriz() {
  const int kFilasAleatorias = GenerarNumerosAleatorias();
  const int kColumnasAleatorias = GenerarNumerosAleatorias();
  std::vector<int> cada_fila;
  // Rellenar la matriz
  for (int i = 0; i < kFilasAleatorias; ++i) {
    for (int j = 0; j < kColumnasAleatorias; ++j) {
      cada_fila.push_back(rand() % 100);
    }
    matriz_.push_back(cada_fila);
    cada_fila.erase(cada_fila.begin(), cada_fila.end());
  }
}

/**
 * @brief Sobrecarga del operador de inserción (<<) para mostrar una Matriz
 * @param[out] salida salida por pantalla
 * @param[in] kMatriz objeto de la clase Matriz, para poder mostrar la Matriz
 */
std::ostream& operator<<(std::ostream& salida, const Matriz& kMatriz) {
  for (int i = 0; i < kMatriz.matriz_.size(); ++i) {
    for (int j = 0; j < kMatriz.matriz_[i].size(); ++j) {
      salida << kMatriz.matriz_[i][j] << " ";
    }
    salida << std::endl;
  }
  return salida;
}