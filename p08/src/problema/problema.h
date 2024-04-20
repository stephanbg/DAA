/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 19 de Abril de 2024
 * @file problema.h
 * @brief Definición de la clase Problema para representar un problema
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p08/src}
 */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

#include "../matriz/matriz.h"
#include "../funciones/funciones.h"

/**
 * @brief Representa el problema a resolver.
 * 
 * Esta clase encapsula los datos y funcionalidades relacionadas con el problema a resolver.
 */
class Problema {
 public:
  Problema(const std::string&);
  const std::vector<int> getIndicesProblema() const;
  const Matriz& getCoordenadas() const { return coordenadas_; }
  const Matriz& getDistancias() const { return distancias_; }
  friend std::ostream& operator<<(std::ostream&, const Problema&);
 private:
  Matriz coordenadas_;
  Matriz distancias_;
  void construirMatrices(std::ifstream&);
  void rellenarDatosCoordenadas(std::ifstream&);
  void rellenarDatosDistancias();
};