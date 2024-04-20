/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 19 de Abril de 2024
 * @file matriz.h
 * @brief Implementación de la clase que representa una matriz
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p08/src}
 */

#pragma once

#include <iostream>
#include <iomanip>
#include <vector>

#include "../funciones/funciones.h"

/**
 * @brief Clase que representa una matriz y operaciones en ella
 */
class Matriz {
 public:
  Matriz() {};
  Matriz(const int kFilas, const int kColumnas) :
      matriz_(kFilas, std::vector<double>(kColumnas, 0.0)) {};
  const int size() const { return matriz_.size(); }
  void eliminarElemento(const int);   
  const std::vector<std::vector<double>>& getMatriz() const { return matriz_; }
  std::vector<std::vector<double>>& setMatriz() { return matriz_; }
  const std::vector<double>& operator[](const int kFila) const { return matriz_[kFila]; }
  std::vector<double>& operator[](const int kFila) { return matriz_[kFila]; }
  friend std::ostream& operator<<(std::ostream&, const Matriz&);
 private:
  std::vector<std::vector<double>> matriz_;
};