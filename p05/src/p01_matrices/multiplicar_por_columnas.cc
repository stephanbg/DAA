/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 *
 * @author Stephan Brommer Gutiérrez
 * Correo: alu0101493497@ull.edu.es
 * @date 30/01/2024
 * @file multiplicar_por_columnas.cc
 * @brief Contiene la implementación de la clase MultiplicarPorColumnas, es la clase derivada
 *        de la clase abstracta MultiplicarMatriz, esta sobreescribe el algoritmo de 
 *        multiplicar matrices, para multiplicar matrices por columnas
 * @see {@link https://github.com/stephanbg/DAA}
 *
 */

#include "multiplicar_por_columnas.h"

/**
 * @brief Este método realiza el algoritmo de multiplicar matrices por columnas, es decir, se fija
 *        el puntero en una columna de la segunda matriz, y dicha columna se va multiplicando por cada
 *        fila de la primera matriz, cuando recorre todas las filas avanza a la siguiente columna.
 * @param[in] kMatriz1 referencia (constante) de la primera matriz
 * @param[in] kMatriz2 referencia (constante) de la segunda matriz
 * @returns Devuleve la matriz resultado
 */
Matriz MultiplicarPorColumnas::Multiplicar(const Matriz& kMatriz1, const Matriz& kMatriz2) const {
  const size_t kFilas = kMatriz1.get_matriz().size();
  const size_t kColumnas = kMatriz2.get_matriz()[0].size();
  // Inicializa la matriz resultado con el tamaño adecuado y todos los elementos establecidos en 0
  std::vector<std::vector<int>> resultado(kFilas, std::vector<int>(kColumnas, 0));
  // Realizamos multiplicación por columnas
  for (int i = 0; i < kMatriz2.get_matriz()[0].size(); ++i) {
    for (int j = 0; j < kMatriz1.get_matriz().size(); ++j) {
      for (int k = 0; k < kMatriz1.get_matriz()[j].size(); ++k) {
        resultado[j][i] += kMatriz1.get_matriz()[j][k] * kMatriz2.get_matriz()[k][i];
      }
    }
  }
  return Matriz(resultado);
}