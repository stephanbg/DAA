/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file cinta_out.h
 * @brief Definición de la clase CintaOut para representar la cinta de salida de la Máquina RAM.
 *        La cinta de salida es utilizada para almacenar los datos que se han obtenido al ejecutar el programa.
 * 
 * @see {@link https://docs.google.com/document/d/1n6iua2wSG2UVns-mTA4YdMBVKfKIazkJi4HRzKVKS78/edit}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p02}
 */

#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

#include "../funciones/funciones_necesarias.h"

/**
 * @brief Clase CintaOut que representa la cinta de salida de la Máquina RAM.
 */
class CintaOut {
 public:
  CintaOut() : puntero_(-1) {} // Constructor, el puntero de la cinta al inicio es -1, porque no hay elementos
  const int get_puntero() const { return puntero_; }
  int& set_puntero() { return puntero_; } 
  const std::vector<long double>& get_cinta() const { return cinta_; }
  std::vector<long double>& set_cinta() { return cinta_; }
  void MeterEnFichero(const std::string&);
  friend std::ostream& operator<<(std::ostream&, const CintaOut&);
 private:
  std::vector<long double> cinta_; // Cinta de salida
  int puntero_; // puntero al último elemento
};