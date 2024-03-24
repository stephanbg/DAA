/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Marzo de 2024
 * @file comprobar_aprametros.h
 * @brief Definición de la clase ComprobarParametros, que comprueba la línea de comandos
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p06/src}
 * @see {@link https://docs.google.com/document/d/1a691HPtHQL4qBtI2qaTMTp23wxZvU8-CCIbGOyNJRQo/edit}
 */

#pragma once

#include <iostream>
#include <filesystem>

#include "../funciones/funciones.h"

namespace fs = std::filesystem;

/**
 * @brief Clase para comprobar los parámetros de entrada del programa.
 */
class ComprobarParametros {
 public:
  static void comprobar(const int, char *[]);
  static void ayuda();
 private:
  static bool cantidadParametrosCorrecta(const int);
  static bool existeFichero(const std::string&);
};