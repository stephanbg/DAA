/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 *
 * @author Stephan Brommer Gutiérrez
 * Correo: alu0101493497@ull.edu.es
 * @date 30/01/2024
 * @file multiplicar_por_filas.cc
 * @brief Contiene la implementación de la clase MultiplicarPorFilas, es la clase derivada
 *        de la clase abstracta MultiplicarMatriz, esta sobreescribe el algoritmo de 
 *        multiplicar matrices, para multiplicar matrices por filas
 * @see {@link https://github.com/stephanbg/DAA}
 *
 */

#include "multiplicar_por_filas.h"

/**
 * @brief Este método realiza el algoritmo de multiplicar matrices por filas, es decir, se fija
 *        el puntero en una fila de la primera matriz, y dicha fila se va multiplicando por cada
 *        columna de la seguna matriz, cuando recorre todas las columna avanza a la siguiente fila.
 * @param[in] kMatriz1 referencia (constante) de la primera matriz
 * @param[in] kMatriz2 referencia (constante) de la segunda matriz
 * @returns Devuleve la matriz resultado
 */
Matriz MultiplicarPorFilas::Multiplicar(const Matriz& kMatriz1, const Matriz& kMatriz2) const {
  const size_t kFilas = kMatriz1.get_matriz().size();
  const size_t kColumnas = kMatriz2.get_matriz()[0].size();
  // Inicializa la matriz resultado con el tamaño adecuado y todos los elementos establecidos en 0
  std::vector<std::vector<int>> resultado(kFilas, std::vector<int>(kColumnas, 0));
  // Realizamos multiplicación por filas
  for (int i = 0; i < kMatriz1.get_matriz().size(); ++i) {
    for (int j = 0; j < kMatriz2.get_matriz()[0].size(); ++j) {
      for (int k = 0; k < kMatriz2.get_matriz().size(); ++k) {
        resultado[i][j] += kMatriz1.get_matriz()[i][k] * kMatriz2.get_matriz()[k][j];
      }
    }
  }
  return Matriz(resultado);
}