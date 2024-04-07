/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 20 de Marzo de 2024
 * @file sintaxis_fichero.h
 * @brief Definición de la clase SintaxisFichero
 * que comprueba la sintaxis de los ficheros que contienen descripciones para
 * el problema Parallel Machine Scheduling Problem with Dependent Setup Times
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07_parcial_1/src}
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
 * la descripción del número de nodos, máquinas, tiempos de procesamiento y tiempos de setup
 * para la posterior construcción del grafo
 * 
 */
class SintaxisFichero {
 public:
  static void comprobarSintaxisFichero(const std::string&);
 private:
  static const bool numeroNodosValido(const std::string&);
  static const bool numeroMaquinasValido(const std::string&);
  static const bool tiemposProcesamientoValidos(const std::string&);
  static void extraerRangosProcesamientos(const std::string&, std::pair<int, int>&);
  static void extraerRangosSetUp(const std::string&, std::pair<int, int>&);
  static const bool tiemposSetUpValidos(const std::string&, const std::pair<int, int>&, const int);
};