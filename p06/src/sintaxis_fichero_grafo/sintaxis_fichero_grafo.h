/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Marzo de 2024
 * @file sintaxis_fichero_grafo.h
 * @brief Definición de la clase SintaxisFicheroGrafo
 * que comrpueba la sintaxis de los ficheros que contienen descripciones de grafos
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p06/src}
 * @see {@link https://docs.google.com/document/d/1a691HPtHQL4qBtI2qaTMTp23wxZvU8-CCIbGOyNJRQo/edit}
 */

#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "../funciones/funciones.h"

/**
 * @brief Analiza la sintaxis de un fichero que contiene
 * la descripción de un Grafo
 * 
 */
class SintaxisFicheroGrafo {
 public:
  static const bool numeroNodosValido(const std::string&);
  static const bool tresElementosPorLineaNodo1Nodo2Coste(const std::vector<std::string>&);
};