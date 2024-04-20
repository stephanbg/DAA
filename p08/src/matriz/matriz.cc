/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 19 de Abril de 2024
 * @file matriz.cc
 * @brief Implementación de la clase que representa una matriz
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p08/src}
 */

#include "matriz.h"

/**
 * @brief Elimina un elemento de la matriz en la posición especificada por el índice.
 * 
 * @param kIndice El índice del elemento que se desea eliminar.
 */
void Matriz::eliminarElemento(const int kIndice) {
  matriz_.erase(matriz_.begin() + kIndice);
}

/**
 * @brief Sobrecarga del operador de inserción para imprimir una matriz en formato legible.
 * 
 * @param salida El flujo de salida donde se imprimirá la matriz.
 * @param kMatriz La matriz que se desea imprimir.
 * @return El flujo de salida modificado después de imprimir la matriz.
 */
std::ostream& operator<<(std::ostream& salida, const Matriz& kMatriz) {
  const int kNumFilas = kMatriz.getMatriz().size();
  for (int i = 0; i < kNumFilas; ++i) {
    salida << "Elemento " << i + 1 << ": ";
    const std::vector<double> kCadaFila = kMatriz.getMatriz()[i];
    const int kNumColumnas = kCadaFila.size();
    for (int j = 0; j < kNumColumnas; ++j) {
      const int kNumDecimales = contarDecimales(kCadaFila[j], 5);
      salida << std::fixed << std::setprecision(kNumDecimales) << kCadaFila[j];
      if (j < (kNumColumnas - 1)) salida << ", ";
    }
    salida << std::endl;
  }
  return salida;
}