/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file store.cc
 * @brief Implementación de la clase Store derivada de la clase abstracta Operacion, que se
 *        encargará de ejecutar la instrucción Store.
 * 
 * @see {@link https://docs.google.com/document/d/1n6iua2wSG2UVns-mTA4YdMBVKfKIazkJi4HRzKVKS78/edit}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p02}
 */

#include "store.h"

/**
 * @brief Ejecuta la instrucción "Store".
 * 
 * La instrucción "Store" almacena el valor del registro R0
 * en el registro especificado por el operando de la instrucción.
 * Cabe destacar que no se puede STORE =constante.
 * 
 * @param kInstruccion La instrucción a ejecutar.
 * @param memoria_datos La memoria de datos en la que se realizará la operación.
 * @param cinta_entrada La cinta de entrada utilizada durante la ejecución.
 * @param cinta_salida La cinta de salida utilizada durante la ejecución.
 * @param pc El contador de programa, que se incrementará después de ejecutar la instrucción.
 * @throw Lanza un error si tiene que acceder fuera de memoria
 */
void Store::EjecutarInstruccion(const Instruccion& kInstruccion, MemoriaDatos& memoria_datos, CintaIn& cinta_entrada,
                                CintaOut& cinta_salida, int& pc) const {
  try {
    const long double kValorR0 = memoria_datos.obtenerDato(0);
    const long double kValor = kInstruccion.ObtenerConstante();
    const int kRegistro = kInstruccion.get_tipo_operando()->get_valor(kInstruccion, memoria_datos, kValor);
    memoria_datos.almacenarDato(kValorR0, kRegistro);
    pc++;
  } catch (const std::string& kErrorAccesoFueraDeMemoria) {
    throw (kErrorAccesoFueraDeMemoria);
  }
}