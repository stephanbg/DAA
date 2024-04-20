/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 19 de Abril de 2024
 * @file sintaxis_fichero.h
 * @brief Definición de la clase SintaxisFichero
 * que comprueba la sintaxis de los ficheros que contienen descripciones para
 * el Maximum Diversity Problem
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p08/src}
 */

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <regex>
#include <filesystem>

#include "../funciones/funciones.h"

namespace fs = std::filesystem;

/**
 * @brief Analiza la sintaxis de un fichero que contiene
 * la descripción del número de puntos en el espacio, las dimensiones y
 * las coordenadas de los elementos para la posterior construcción del problema
 */
class SintaxisFichero {
 public:
  static void comprobarSintaxisFichero(const std::string&);
 private:
  static bool numeroPuntosValidos(const std::string&, int&);
  static bool numeroDimensionesValidas(const std::string&, int&);
  static bool coordenadasValidas(const std::string&, const int);
};