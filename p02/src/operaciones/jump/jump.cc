/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file jump.cc
 * @brief Implementación de la clase Jump derivada de la clase abstracta Operacion, que se
 *        encargará de validar si la instrucción Jump es válida y la ejecutará.
 * 
 * @see {@link https://docs.google.com/document/d/1n6iua2wSG2UVns-mTA4YdMBVKfKIazkJi4HRzKVKS78/edit}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p02}
 */

#include "jump.h"

/**
 * @brief Ejecuta la instrucción "Jump".
 * 
 * La instrucción "Jump" salta a la posición de memoria especificada por el operando
 * sin ningún tipo de condición (salto incondicional).
 * 
 * @param kInstruccion La instrucción a ejecutar.
 * @param memoria_datos La memoria de datos en la que se realizará la operación.
 * @param cinta_entrada La cinta de entrada utilizada durante la ejecución.
 * @param cinta_salida La cinta de salida utilizada durante la ejecución.
 * @param pc El contador de programa, se sitúa donde diga el operando (pos etiqueta).
 * @throw Lanza un error si tiene que saltar a etiqueta inexistente.
 */
void Jump::EjecutarInstruccion(const Instruccion& kInstruccion, MemoriaDatos& memoria_datos, CintaIn& cinta_entrada,
                               CintaOut& cinta_salida, int& pc) const {
  const std::string kErrorSalto = "Salto a etiqueta inexistente.";
  const int kSalto = kInstruccion.ObtenerConstante();
  if (kSalto == -1) throw (kErrorSalto);
  pc = kSalto;
}