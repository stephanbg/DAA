/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 20 de Marzo de 2024
 * @file peticionesUsuario.cc
 * @brief Implementación de funciones que hacen peticiones al usuario
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07_parcial_1/src}
 */

#include "peticionesUsuario.h"

/**
 * @brief Pregunta al usuario si desea mostrar las tablas por pantalla o por fichero.
 * 
 * @return La respuesta del usuario (P para pantalla, F para fichero).
 */
const std::string peticionUsuarioTablaPantallaOFichero() {
  std::cout << "Quieres mostrar las tablas por pantalla o por fichero [P|F]: ";
  std::string opcion = "";
  while (std::cin >> opcion && opcion != "P" && opcion != "F") {
    std::cout << "Tiene que escribir [P|F]: ";
  }
  return opcion;
}