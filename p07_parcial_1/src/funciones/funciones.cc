/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 20 de Marzo de 2024
 * @file funciones.cc
 * @brief Implementación de funciones necesarias
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07_parcial_1/src}
 */

#include "funciones.h"

/**
 * @brief Verifica si una cadena representa un número entero sin signo.
 * 
 * @param kNumeroEnCadena Cadena que representa el número.
 * @return true si la cadena representa un número entero sin signo, false en caso contrario.
 */
const bool esNumeroEnteroSinSigno(const std::string& kNumeroEnCadena) {
  if (kNumeroEnCadena[0] == '+' || kNumeroEnCadena[0] == '-') return false;
  const int kSizeNumero = kNumeroEnCadena.size();
  for (int i = 0; i < kSizeNumero; ++i) {
    if (kNumeroEnCadena[i] < '0' ||  kNumeroEnCadena[i] > '9') return false;
  }
  return true;
}