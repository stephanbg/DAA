/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file div.cc
 * @brief Implementación de la clase Div derivada de la clase abstracta Operacion, que se
 *        encargará de ejecutar la instrucción Div.
 * 
 * @see {@link https://docs.google.com/document/d/1zf_w2HtS4zJX3iqr9yPm6f7rRNsrBxL7afCsMapujMQ/edit#heading=h.5bq8rsdy1ujx}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p03}
 */

#include "div.h"

/**
 * @brief Ejecuta la instrucción "Div".
 * 
 * La instrucción "Div" divide el valor contenido en el registro R0 de la memoria de datos con
 * un valor obtenido del operando de la instrucción, y almacena el resultado de la división en el registro R0.
 * 
 * @param kInstruccion La instrucción a ejecutar.
 * @param memoria_datos La memoria de datos en la que se realizará la operación.
 * @param cinta_entrada La cinta de entrada utilizada durante la ejecución.
 * @param cinta_salida La cinta de salida utilizada durante la ejecución.
 * @param pc El contador de programa, que se incrementará después de ejecutar la instrucción.
 * @throw Lanza una excepción si el valor del divisor es 0 o si accede fuera de memoria.
 */
void Div::EjecutarInstruccion(const Instruccion& kInstruccion, MemoriaDatos& memoria_datos, CintaIn& cinta_entrada,
                               CintaOut& cinta_salida, int& pc) const {
  try {
    const std::string& kErrorDivisionPor0 = "No se puede dividir por 0";
    long double resultado = kInstruccion.get_tipo_operando()->get_registro_o_valor(kInstruccion, memoria_datos); 
    if (const OperandoDirectoVectorial* op_vectorial = dynamic_cast<const OperandoDirectoVectorial*>(kInstruccion.get_tipo_operando())) {
      resultado = op_vectorial->get_columna_registro_o_valor(kInstruccion, memoria_datos);
    }
    if (resultado == 0) throw (kErrorDivisionPor0);
    const long double R0 = (double) (memoria_datos.obtenerDato(0) / resultado);
    memoria_datos.almacenarDato(R0, 0);
    pc++;
  } catch (const std::string& kError) {
    throw (kError);
  }
}