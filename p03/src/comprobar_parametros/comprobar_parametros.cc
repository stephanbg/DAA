/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file comprobar_parametros.cc
 * @brief Implementación de la clase ComprobarParametros y sus métodos
 *        estáticos para la validación de los parámetros de entrada.
 * 
 * @see {@link https://docs.google.com/document/d/1n6iua2wSG2UVns-mTA4YdMBVKfKIazkJi4HRzKVKS78/edit}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p02}
 */

#include "comprobar_parametros.h"

/**
 * @brief Comprueba si hay errores en los parámetros de entrada.
 * 
 * @param kArgc Cantidad de argumentos pasados al programa.
 * @param argv Array de cadenas de caracteres que representan los argumentos pasados al programa.
 */
void ComprobarParametros::ComprobarErrores(const int kArgc,
                                           char* argv[]) {
  ComprobarCantidadParametros(kArgc);
  ComprobarFormatoDeNombreFicheroRam(argv[1]);
  ComprobarFormatoDeNombreCintaEntrada(argv[2]);
  ComprobarFormatoDeNombreCintaSalida(argv[3]);
  ComprobarValorDebug(argv[4]);
}

/**
 * @brief Comprueba si la cantidad de parámetros es válida.
 * 
 * @param kArgc Cantidad de argumentos pasados al programa.
 * @throw Lanza una excepción si no son 5 parámetros.
 */
void ComprobarParametros::ComprobarCantidadParametros(const int kArgc) {
  const std::string kError = "Cantidad de parámetros.";
  if (kArgc != 5) {
    throw kError;
  }
}

/**
 * @brief Comprueba el formato del nombre del archivo de la memoria RAM.
 * 
 * @param kRam Nombre del archivo de la memoria RAM.
 * @throw Lanza una excepción si la extensión no es ram.
 */
void ComprobarParametros::ComprobarFormatoDeNombreFicheroRam(const std::string& kRam) {
  const std::regex kPatron(".+\\.ram");
  const std::string kError = "Extensión del programa tiene que ser ram";
  if (!std::regex_match(kRam, kPatron)) throw kError;
}

/**
 * @brief Comprueba el formato del nombre del archivo de la cinta de entrada.
 * 
 * @param kCintaIn Nombre del archivo de la cinta de entrada.
 * @throw Lanza una excepción si el nombre de la cinta de entrada no se llama cintas/cinta_in.txt.
 */
void ComprobarParametros::ComprobarFormatoDeNombreCintaEntrada(const std::string& kCintaIn) {
  const std::string kNombreCintaIn = "cintas/cinta_in.txt";
  const std::string kError = "Nombre de la cinta de entrada";
  if (kCintaIn != kNombreCintaIn) throw kError;
}

/**
 * @brief Comprueba el formato del nombre del archivo de la cinta de salida.
 * 
 * @param kCintaOut Nombre del archivo de la cinta de salida.
 * @throw Lanza una excepción si el nombre de la cinta de salida no se llama cintas/cinta_out.txt.
 */
void ComprobarParametros::ComprobarFormatoDeNombreCintaSalida(const std::string& kCintaOut) {
  const std::string kNombreCintaOut = "cintas/cinta_out.txt";
  const std::string kError = "Nombre de la cinta de salida";
  if (kCintaOut != kNombreCintaOut) throw kError;
}

/**
 * @brief Comprueba el formato del valor del debug
 * 
 * @param kValorDebug Valor del debug
 * @throw Lanza una excepción si el valor del debug es distinto de 0, o de 1 o de 2
 */
void ComprobarParametros::ComprobarValorDebug(const std::string& kValorDebug) {
  const std::string kError = "El debug solo puede ser 0, 1 o 2";
  if (!(kValorDebug == "0" || kValorDebug == "1" || kValorDebug == "2")) throw kError;
}