/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file jgtz.cc
 * @brief Implementación de la clase Jgtz derivada de la clase abstracta Operacion, que se
 *        encargará de ejecutar la instrucción Jgtz.
 * 
 * @see {@link https://docs.google.com/document/d/1zf_w2HtS4zJX3iqr9yPm6f7rRNsrBxL7afCsMapujMQ/edit#heading=h.5bq8rsdy1ujx}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p03}
 */

#include "jgtz.h"

/**
 * @brief Ejecuta la instrucción "Jgtz".
 * 
 * La instrucción "Jgtz" salta a la posición de memoria especificada por el operando
 * si R0 > 0.
 * 
 * @param kInstruccion La instrucción a ejecutar.
 * @param memoria_datos La memoria de datos en la que se realizará la operación.
 * @param cinta_entrada La cinta de entrada utilizada durante la ejecución.
 * @param cinta_salida La cinta de salida utilizada durante la ejecución.
 * @param pc El contador de programa, se sitúa donde diga el operando (pos etiqueta) si se cumple
 *           la condición, si no solo aumenta 1.
 * @throw Lanza un error si tiene que saltar a etiqueta inexistente.
 */
void Jgtz::EjecutarInstruccion(const Instruccion& kInstruccion, MemoriaDatos& memoria_datos, CintaIn& cinta_entrada,
                               CintaOut& cinta_salida, int& pc) const {
  const std::string kErrorSalto = "Salto a etiqueta inexistente.";
  const int kSalto = kInstruccion.ObtenerConstante();
  if (kSalto == -1) throw (kErrorSalto);
  if (memoria_datos.obtenerDato(0) > 0) pc = kSalto;
  else pc++;
}