/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file load.cc
 * @brief Implementación de la clase Load derivada de la clase abstracta Operacion, que se
 *        encargará de validar si la instrucción Load es válida y la ejecutará.
 * 
 * @see {@link https://docs.google.com/document/d/1n6iua2wSG2UVns-mTA4YdMBVKfKIazkJi4HRzKVKS78/edit}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p02}
 */

#include "load.h"

void Load::EjecutarInstruccion(const Instruccion& kInstruccion, MemoriaDatos& memoria_datos, CintaIn& cinta_entrada,
                               CintaOut& cinta_salida, int& pc) const {
  try {
    const long double kValor = kInstruccion.ObtenerConstante();
    const long double kResultado = kInstruccion.get_tipo_operando()->get_valor(kInstruccion, memoria_datos, kValor);
    memoria_datos.almacenarDato(kResultado, 0);
    pc++;
  } catch (const std::string& kErrorAccesoFueraDeMemoria) {
    throw (kErrorAccesoFueraDeMemoria);
  }
}