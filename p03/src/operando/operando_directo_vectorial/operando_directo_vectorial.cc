/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file operando_directo_vectorial.cc
 * @brief Implementación de la clase OperandoDirectoVectorial derivada de Operando, que representa cuando un
 *        operando es directo, es decir, cuando se accede a un registro, ese es el valor, pero en este caso
 *        un registro es un vector dinámico.
 * 
 * @see {@link https://docs.google.com/document/d/1zf_w2HtS4zJX3iqr9yPm6f7rRNsrBxL7afCsMapujMQ/edit#heading=h.5bq8rsdy1ujx}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p03}
 */

#include "operando_directo_vectorial.h"

/**
 * @brief Comprueba si una cadena de texto cumple con el patrón de un operando directo vectorial.
 * 
 * @param kOperando La cadena de texto a comprobar.
 * @return true si la cadena cumple con el patrón de un operando directo vectorial, false en caso contrario.
 */
bool OperandoDirectoVectorial::compruebaPatron(const std::string& kOperando) const {
  // Permite cualquier (excepto 0 dígitos) número de dígitos sin signo 
  const std::regex kPatronDirecto{"^\\d+\\[\\d+\\]$"};
  if (std::regex_match(kOperando, kPatronDirecto)) return true;
  return false;
}

/**
 * @brief Obtiene el valor de un operando directo vectorial. Siempre
 *        devuelve el registro al que hay que ir a mirar sus columnas
 * 
 * @param kInstruccion La instrucción actual.
 * @param kMemoriaDatos La memoria de datos del sistema.
 * @param kNumRegistro El número de registro asociado al operando directo vectorial.
 * @throw Lanza una excepción si se accede fuera de la memoria, o si la
 *        instrucción es WRITE y el registro es 0, o si la operación no es
 *        ni de escritura ni de lectura.
 * @return El registro que es vectorial.
 */
const long double OperandoDirectoVectorial::get_registro_o_valor(const Instruccion& kInstruccion,
                                                                 const MemoriaDatos& kMemoriaDatos) const {
  const long double kNumRegistro = kInstruccion.ObtenerConstante();
  const std::string kOperador = kInstruccion.get_instruccion()[0];
  const std::string kErrorAccesoFueraDeMemoria = "Accediendo fuera de rango.";
  if (kNumRegistro < 0 || kNumRegistro >= kMemoriaDatos.get_registros().size()) throw (kErrorAccesoFueraDeMemoria);
  const std::string kErrorReadEnCero = "No se puede guardar un elemento en R0 mediante READ";
  const std::string kErrorWriteEnCero = "No se puede escribir en la cinta de salida con WRITE desde R0";
  if (kOperador == "WRITE" && kNumRegistro == 0) throw (kErrorWriteEnCero);
  if (kOperador == "READ" && kNumRegistro == 0) throw (kErrorReadEnCero);
  return kNumRegistro;
}

/**
 * @brief Si la operación es de lectura te da el contenido de la columna del registro vectorial,
 *        si es de escritura de ta la columna del registro vectorial.
 * 
 * @param kInstruccion La instrucción actual.
 * @param kMemoriaDatos La memoria de datos del sistema.
 * @return Devuelve el contenido de la columna o la columna del registro vectorial. 
 */
const long double OperandoDirectoVectorial::get_columna_registro_o_valor(const Instruccion& kInstruccion,
                                                                         const MemoriaDatos& kMemoriaDatos) const {
  const int kRegistroOriginal = kInstruccion.ObtenerConstante();
  const size_t primerParentesis = kInstruccion.get_instruccion()[1].find("[");
  const size_t segundoParentesis = kInstruccion.get_instruccion()[1].find("]");
  const int kRegistroAux = stoi(kInstruccion.get_instruccion()[1].substr(primerParentesis + 1, segundoParentesis));
  const std::string kErrorAccesoFueraDeMemoria = "Accediendo fuera de rango.";
  const std::string kErrorLecturaEscritura = "Este operador no es de escritura, ni de lectura.";
  if (kRegistroAux < 0 || kRegistroAux >= kMemoriaDatos.get_registros().size()) throw (kErrorAccesoFueraDeMemoria);
  const int kColumna = kMemoriaDatos.obtenerDato(kRegistroAux);
  if (kInstruccion.get_lectura_escritura() == "Lectura") return kMemoriaDatos.obtenerDato(kRegistroOriginal, kColumna);
  if (kInstruccion.get_lectura_escritura() == "Escritura") return kColumna;
  throw (kErrorLecturaEscritura);
  return EXIT_FAILURE; // Por si no es escritura ni lectura
}