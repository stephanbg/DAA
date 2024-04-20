/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 19 de Abril de 2024
 * @file comprobar_parametros.h
 * @brief Definición de la clase ComprobarParametros, que comprueba la línea de comandos
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p08/src}
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
  static bool existeDirectorio(const std::string&);
};