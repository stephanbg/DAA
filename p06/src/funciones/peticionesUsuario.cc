/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Marzo de 2024
 * @file peticionesUsuario.cc
 * @brief Implementación de funciones que hacen peticiones al usuario
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p06/src}
 * @see {@link https://docs.google.com/document/d/1a691HPtHQL4qBtI2qaTMTp23wxZvU8-CCIbGOyNJRQo/edit}
 */

#include "peticionesUsuario.h"

/**
 * @brief Solicita al usuario la cantidad de nodos para las instancias aleatorias.
 * 
 * @return La cantidad de nodos especificada por el usuario.
 */
const int peticionUsuarioCantidadNodos() {
  std::cout << "¿Cuántos nodos quieres para las instancias aleatorias?: ";
  std::string num_nodos = "";
  while (std::cin >> num_nodos && !SintaxisFicheroGrafo::numeroNodosValido(num_nodos)) {
    std::cout << "El número de nodos no es válido, tiene que ser > 1: ";
  }
  return stoi(num_nodos);
}

/**
 * @brief Pregunta al usuario si desea eliminar los ficheros aleatorios.
 * 
 * @return La respuesta del usuario (S para sí, N para no).
 */
const std::string peticionUsuarioEliminarFicherosRand() {
  std::cout << "Quieres eliminar los ficheros aleatorios? [S|N]: ";
  std::string opcion = "";
  while (std::cin >> opcion && (opcion != "S") && (opcion != "N")) {
    std::cout << "Tiene que elegir las opciones [S|N]: ";
  }
  return opcion;
}

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