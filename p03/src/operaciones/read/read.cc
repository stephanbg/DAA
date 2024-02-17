/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file read.cc
 * @brief Implementación de la clase Read derivada de la clase abstracta Operacion, que se
 *        encargará de ejecutar la instrucción Read.
 * 
 * @see {@link https://docs.google.com/document/d/1zf_w2HtS4zJX3iqr9yPm6f7rRNsrBxL7afCsMapujMQ/edit#heading=h.5bq8rsdy1ujx}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p03}
 */

#include "read.h"

/**
 * @brief Ejecuta la instrucción "Read".
 * 
 * La instrucción "Read" lee un valor de la cinta de entrada y lo almacena en
 * el registro indicado por el operando. Cabe destacar que no está permitido
 * ni almacenar en R0 ni en una constante.
 * 
 * @param kInstruccion La instrucción a ejecutar.
 * @param memoria_datos La memoria de datos en la que se realizará la operación.
 * @param cinta_entrada La cinta de entrada utilizada durante la ejecución.
 * @param cinta_salida La cinta de salida utilizada durante la ejecución.
 * @param pc El contador de programa, que se incrementará después de ejecutar la instrucción.
 * @throw Lanza un error si tiene que acceder fuera de memoria o si no quedan elementos
 *        en la cinta de entrada o si se está intentando almacenar en R0.
 */
void Read::EjecutarInstruccion(const Instruccion& kInstruccion, MemoriaDatos& memoria_datos, CintaIn& cinta_entrada,
                               CintaOut& cinta_salida, int& pc) const {
  try {
    const std::string kErrorAccesoFueraDeCinta = "No quedan elementos en la cinta de entrada";
    const int kPuntero = cinta_entrada.get_puntero();
    if (kPuntero >= cinta_entrada.get_cinta().size()) throw (kErrorAccesoFueraDeCinta);
    const long double kValorCintaEntrada = cinta_entrada.get_cinta()[kPuntero];
    const int kRegistro = kInstruccion.get_tipo_operando()->get_registro_o_valor(kInstruccion, memoria_datos);
    int columna = 0;
    if (const OperandoDirectoVectorial* op_vectorial = dynamic_cast<const OperandoDirectoVectorial*>(kInstruccion.get_tipo_operando())) {
      columna = op_vectorial->get_columna_registro_o_valor(kInstruccion, memoria_datos);
    }    
    memoria_datos.almacenarDato(kValorCintaEntrada, kRegistro, columna);
    cinta_entrada.set_puntero() = cinta_entrada.get_puntero() + 1;
    pc++;
  } catch (const std::string& kError) {
    throw (kError);
  }
}