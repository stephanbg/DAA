/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file cinta_in.h
 * @brief Definición de la clase CintaIn para representar la cinta de entrada de la Máquina RAM.
 *        La cinta de entrada es utilizada para proporcionar datos de entrada al programa en ejecución.
 * 
 * @see {@link https://docs.google.com/document/d/1zf_w2HtS4zJX3iqr9yPm6f7rRNsrBxL7afCsMapujMQ/edit#heading=h.5bq8rsdy1ujx}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p03}
 */

#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

#include "../funciones/funciones_necesarias.h"

/**
 * @brief Clase CintaIn que representa la cinta de entrada de la Máquina RAM.
 */
class CintaIn {
 public:
  CintaIn(const std::string&); // Constructor
  const int get_puntero() const { return puntero_; }
  int& set_puntero() { return puntero_; }
  const std::vector<long double>& get_cinta() const { return cinta_; }
  friend std::ostream& operator<<(std::ostream&, const CintaIn&);
 private:
  std::vector<long double> cinta_; // Cinta de entrada
  int puntero_; // puntero al elemento de la cinta de entrada que se puede leer
  void RellenarCinta(const std::string&);
};