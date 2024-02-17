/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file operando_directo.cc
 * @brief Implementación de la clase OperandoDirecto derivada de Operando, que representa cuando un
 *        operando es directo, es decir, cuando se accede a un registro ese es el valor.
 * 
 * @see {@link https://docs.google.com/document/d/1zf_w2HtS4zJX3iqr9yPm6f7rRNsrBxL7afCsMapujMQ/edit#heading=h.5bq8rsdy1ujx}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p03}
 */

#include "operando_directo.h"

/**
 * @brief Comprueba si una cadena de texto cumple con el patrón de un operando directo.
 * 
 * @param kOperando La cadena de texto a comprobar.
 * @return true si la cadena cumple con el patrón de un operando directo, false en caso contrario.
 */
bool OperandoDirecto::compruebaPatron(const std::string& kOperando) const {
  // Permite cualquier (excepto 0 dígitos) número de dígitos sin signo 
  const std::regex kPatronDirecto{"^\\d+$"};
  if (std::regex_match(kOperando, kPatronDirecto)) return true;
  return false;
}

/**
 * @brief Obtiene el valor de un operando directo. (Si la operación es
 *        de lectura te da el contenido del registro y si es de 
 *        escritura te da el registro)
 * 
 * @param kInstruccion La instrucción actual.
 * @param kMemoriaDatos La memoria de datos del sistema.
 * @param kNumRegistro El número de registro asociado al operando directo.
 * @throw Lanza una excepción si se accede fuera de la memoria, o si la
 *        instrucción es WRITE y el registro es 0, o si la operación no es
 *        ni de escritura ni de lectura.
 * @return El valor del operando directo.
 */
const long double OperandoDirecto::get_registro_o_valor(const Instruccion& kInstruccion, const MemoriaDatos& kMemoriaDatos) const {
  const long double kNumRegistro = kInstruccion.ObtenerConstante();
  const std::string kOperador = kInstruccion.get_instruccion()[0];
  const std::string kErrorAccesoFueraDeMemoria = "Accediendo fuera de rango.";
  const std::string kErrorLecturaEscritura = "Este operador no es de escritura, ni de lectura.";
  const std::string kErrorReadEnCero = "No se puede guardar un elemento en R0 mediante READ";
  const std::string kErrorWriteEnCero = "No se puede escribir en la cinta de salida con WRITE desde R0";
  if (kNumRegistro < 0 || kNumRegistro >= kMemoriaDatos.get_registros().size()) throw (kErrorAccesoFueraDeMemoria);
  if (kInstruccion.get_lectura_escritura() == "Lectura") {
    if (kOperador == "WRITE" && kNumRegistro == 0) throw (kErrorWriteEnCero);
    return kMemoriaDatos.obtenerDato(kNumRegistro);
  }
  else if (kInstruccion.get_lectura_escritura() == "Escritura") {
    if (kOperador == "READ" && kNumRegistro == 0) throw (kErrorReadEnCero);
    return kNumRegistro;
  }
  throw (kErrorLecturaEscritura);
  return EXIT_FAILURE; // Por si no es escritura ni lectura
}