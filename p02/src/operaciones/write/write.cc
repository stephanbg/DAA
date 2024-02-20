/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file write.cc
 * @brief Implementación de la clase Write derivada de la clase abstracta Operacion, que se
 *        encargará de ejecutar la instrucción Write.
 * 
 * @see {@link https://docs.google.com/document/d/1n6iua2wSG2UVns-mTA4YdMBVKfKIazkJi4HRzKVKS78/edit}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p02}
 */

#include "write.h"


/**
 * @brief Ejecuta la instrucción "Write".
 * 
 * La instrucción "Write" obtiene el valor de un registro, excepto de R0,
 * o de una constante y lo almacena en la cinta de salida.
 * 
 * @param kInstruccion La instrucción a ejecutar.
 * @param memoria_datos La memoria de datos en la que se realizará la operación.
 * @param cinta_entrada La cinta de entrada utilizada durante la ejecución.
 * @param cinta_salida La cinta de salida utilizada durante la ejecución.
 * @param pc El contador de programa, que se incrementará después de ejecutar la instrucción.
 * @throw Lanza un error si tiene que acceder fuera de memoria.
 */
void Write::EjecutarInstruccion(const Instruccion& kInstruccion, MemoriaDatos& memoria_datos, CintaIn& cinta_entrada,
                                CintaOut& cinta_salida, int& pc) const {
  try {
    long double resultado = kInstruccion.get_tipo_operando()->get_registro_o_valor(kInstruccion, memoria_datos);
    cinta_salida.set_cinta().push_back(resultado);
    cinta_salida.set_puntero() = cinta_salida.get_puntero() + 1;
    pc++;
  } catch (const std::string& kError) {
    throw (kError);
  }
}