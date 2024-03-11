/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 6 de Marzo de 2024
 * @file funcionesNecesarias.cc
 * @brief Implementación de funciones necesarias para el programa
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p05/src}
 * @see {@link https://docs.google.com/document/d/1pwPk5iI5dRHo8M-raauPP5mgCUHy9m9j_au3UDkn_Rc/edit}
 */

#include "funcionesNecesarias.h"

/**
 * @brief Verifica si una cadena representa un número válido.
 * @param str Cadena a verificar.
 * @return true Si la cadena representa un número válido, false en caso contrario.
 */
bool esNumero(const std::string& str) {
  return std::regex_match(str, std::regex("[+-]?\\d+"));
}

/**
 * @brief Verifica si una cadena contiene solo dígitos.
 * @param str Cadena a verificar.
 * @return true Si la cadena contiene solo dígitos, false en caso contrario.
 */
bool contieneSoloDigitos(const std::string& str) {
  return std::regex_match(str, std::regex("\\d+"));
}