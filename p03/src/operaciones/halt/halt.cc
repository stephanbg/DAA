/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file halt.cc
 * @brief Implementación de la clase Halt derivada de la clase abstracta Operacion, que se
 *        encargará de validar si la instrucción Halt es válida y la ejecutará.
 * 
 * @see {@link https://docs.google.com/document/d/1zf_w2HtS4zJX3iqr9yPm6f7rRNsrBxL7afCsMapujMQ/edit#heading=h.5bq8rsdy1ujx}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p03}
 */

#include "halt.h"

/**
 * @brief Valida si la instrucción es válida para la operación "Halt".
 * 
 * @param kInstruccion La instrucción a validar.
 * @return true si la instrucción es válida para la operación "Halt", false en caso contrario.
 */
bool Halt::ValidarInstruccion(const Instruccion& kInstruccion) const {
  // Si no tiene operandos es válida
  if (kInstruccion.get_instruccion().size() == 1) return true;
  return false;
}

/**
 * @brief Ejecuta la instrucción "Halt".
 * 
 * La instrucción "Halt" para la ejecución del programa.
 * 
 * @param kInstruccion La instrucción a ejecutar.
 * @param memoria_datos La memoria de datos en la que se realizará la operación.
 * @param cinta_entrada La cinta de entrada utilizada durante la ejecución.
 * @param cinta_salida La cinta de salida utilizada durante la ejecución.
 * @param pc El contador de programa, se sitúa en -1, para finalziar.
 */
void Halt::EjecutarInstruccion(const Instruccion& kInstruccion, MemoriaDatos& memoria_datos, CintaIn& cinta_entrada,
                               CintaOut& cinta_salida, int& pc) const {
  pc = -1;
}