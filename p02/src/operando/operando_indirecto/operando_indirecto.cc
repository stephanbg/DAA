/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file operando_indirecto.cc
 * @brief Implementación de la clase OperandoIndirecto derivada de Operando, que representa cuando un
 *        operando es indirecto, es decir, cuando se accede a un registro, contiene otro registro,
 *        y ahí se encuentra el valor.
 * 
 * @see {@link https://docs.google.com/document/d/1n6iua2wSG2UVns-mTA4YdMBVKfKIazkJi4HRzKVKS78/edit}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p02}
 */

#include "operando_indirecto.h"

/**
 * @brief Comprueba si una cadena de texto cumple con el patrón de un operando indirecto.
 * 
 * @param kOperando La cadena de texto a comprobar.
 * @return true si la cadena cumple con el patrón de unoperando indirecto, false en caso contrario.
 */
bool OperandoIndirecto::compruebaPatron(const std::string& kOperando) const {
  // Permite cualquier número de dígitos sin signo empieza por '*'  
  const std::regex kPatronIndirecto{"^\\*\\d+$"};
  if (std::regex_match(kOperando, kPatronIndirecto)) return true;
  return false;
}

/**
 * @brief Obtiene el valor de un operando indirecto. (Si la operación es
 *        de lectura te da el contenido del registro y si es de 
 *        escritura te da el registro)
 * 
 * @param kInstruccion La instrucción actual.
 * @param kMemoriaDatos La memoria de datos del sistema.
 * @param kNumRegistro El número de registro asociado al operando directo.
 * @throw Lanza una excepción si se accede fuera de la memoria en cualquiera
 *        de los dos saltos, o si la instrucción es WRITE y el registro es 0,
 *        o si la operación no es ni de escritura ni de lectura.
 * @return El valor del operando indirecto.
 */
const long double OperandoIndirecto::get_registro_o_valor(const Instruccion& kInstruccion,
                                                          const MemoriaDatos& kMemoriaDatos) const {
  long double registro = kInstruccion.ObtenerConstante();
  const std::string kOperador = kInstruccion.get_instruccion()[0];
  const std::string kErrorAccesoFueraDeMemoria = "Accediendo fuera de rango.";
  const std::string kErrorLecturaEscritura = "Este operador no es de escritura, ni de lectura.";
  const std::string kErrorReadEnCero = "No se puede guardar un elemento en R0 mediante READ";
  const std::string kErrorWriteEnCero = "No se puede escribir en la cinta de salida con WRITE desde R0";
  if (registro < 0 || registro >= kMemoriaDatos.get_registros().size()) throw (kErrorAccesoFueraDeMemoria);
  registro = kMemoriaDatos.obtenerDato(registro);
  if (registro < 0 || registro >= kMemoriaDatos.get_registros().size()) throw (kErrorAccesoFueraDeMemoria);
  if (kInstruccion.get_lectura_escritura() == "Lectura") {
    if (kOperador == "WRITE" && registro == 0) throw (kErrorWriteEnCero);
    return kMemoriaDatos.obtenerDato(registro);
  } else if (kInstruccion.get_lectura_escritura() == "Escritura") {
    if (kOperador == "READ" && registro == 0) throw (kErrorReadEnCero);
    return registro;
  }
  throw (kErrorLecturaEscritura);
  return EXIT_FAILURE; // Por si no es escritura ni lectura
}