/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 20 de Febrero de 2024
 * @file adv.cc
 * @brief Implementación de la clase Adv derivada de la clase abstracta Operacion, que se
 *        encargará de sumar todos los elementos de un registro y alamacenarlo en R0
 * 
 * @see {@link https://docs.google.com/document/d/1zf_w2HtS4zJX3iqr9yPm6f7rRNsrBxL7afCsMapujMQ/edit#heading=h.5bq8rsdy1ujx}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p03}
 */

#include "adv.h"

/**
 * @brief Ejecuta la instrucción "Adv".
 * 
 * La instrucción "Adv" suma el valor de todo un registro y lo almacena en el registro R0 de la memoria de datos.
 * 
 * @param kInstruccion La instrucción a ejecutar.
 * @param memoria_datos La memoria de datos en la que se realizará la operación.
 * @param cinta_entrada La cinta de entrada utilizada durante la ejecución.
 * @param cinta_salida La cinta de salida utilizada durante la ejecución.
 * @param pc El contador de programa, que se incrementará después de ejecutar la instrucción.
 * @throw Lanza una excepción si tiene que acceder fuera de memoria.
 */
void Adv::EjecutarInstruccion(const Instruccion& kInstruccion, MemoriaDatos& memoria_datos, CintaIn& cinta_entrada,
                              CintaOut& cinta_salida, int& pc) const {
  try {
    const long double kRegistro = kInstruccion.get_tipo_operando()->get_registro_o_valor(kInstruccion, memoria_datos); 
    long double suma = 0;
    int columna = 0;
    while (columna < memoria_datos.get_registros()[kRegistro].size()) {
      suma += memoria_datos.obtenerDato(kRegistro, columna);
      columna++;
    }
    memoria_datos.almacenarDato(suma, 0);
    pc++;
  } catch (const std::string& kErrorAccesoFueraDeMemoria) {
    throw (kErrorAccesoFueraDeMemoria);
  }
}