/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file comprobar_parametros.h
 * @brief Definición de la clase ComprobarParametros y sus métodos
 *        estáticos para la validación de los parámetros de entrada.
 * 
 * @see {@link https://docs.google.com/document/d/1zf_w2HtS4zJX3iqr9yPm6f7rRNsrBxL7afCsMapujMQ/edit#heading=h.5bq8rsdy1ujx}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p03}
 */

#pragma once

#include <string>
#include <regex>

/**
 * @brief Clase ComprobarParametros estática que proporciona métodos
 *        para la validación de los parámetros de entrada del programa.
 */
class ComprobarParametros {
 public:
  static void ComprobarErrores(const int, char* []);
 private:
  static void ComprobarCantidadParametros(const int);
  static void ComprobarFormatoDeNombreFicheroRam(const std::string&);
  static void ComprobarFormatoDeNombreCintaEntrada(const std::string&);
  static void ComprobarFormatoDeNombreCintaSalida(const std::string&);
  static void ComprobarValorDebug(const std::string&);
};