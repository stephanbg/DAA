/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file operando_constante.cc
 * @brief Implementación de la clase OperandoConstante derivada de Operando, que representa cuando un
 *        operando es constante.
 * 
 * @see {@link https://docs.google.com/document/d/1n6iua2wSG2UVns-mTA4YdMBVKfKIazkJi4HRzKVKS78/edit}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p02}
 */


#include "operando_constante.h"

/**
 * @brief Comprueba si una cadena de texto cumple con el patrón de una constante.
 * 
 * @param kOperando La cadena de texto a comprobar.
 * @return true si la cadena cumple con el patrón de una constante, false en caso contrario.
 */
bool OperandoConstante::compruebaPatron(const std::string& kOperando) const {
  // Empieza por '=', y permite números flotantes
  const std::regex kPatronConstante{"^=[-+]?\\d+([,.]?\\d+|\\d*)$"}; 
  if (std::regex_match(kOperando, kPatronConstante)) return true;
  return false;
}

/**
 * @brief Obtiene el valor de una constante.
 * 
 * @param kInstruccion La instrucción actual.
 * @param kMemoriaDatos La memoria de datos del sistema.
 * @param kValor El valor de la constante.
 * @return El valor de la constante.
 */
const long double OperandoConstante::get_valor(const Instruccion& kInstruccion, const MemoriaDatos& kMemoriaDatos,
                                               const long double kValor) const {
  return kValor;
}