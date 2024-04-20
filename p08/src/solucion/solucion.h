/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 19 de Abril de 2024
 * @file solucion.h
 * @brief Definición de la clase Solucion para representar una solución
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
 * @brief Clase que representa una solución para el problema.
 * 
 * Esta clase almacena la solución encontrada, que consiste en un conjunto de puntos representados
 * por coordenadas, junto con su función objetivo. También mantiene un registro de los índices de
 * los elementos introducidos en la solución.
 */
class Solucion {
 public:
  Solucion(): funcion_objetivo_(0) {};
  void añadirNuevoElementoEIndice(const std::vector<double>, const int);
  void insertarNuevoPuntoEIndice(const int, const std::vector<double>&, const int);
  const int size() const { return coordenadas_.size(); }
  const double getFuncionObjetivo() const { return funcion_objetivo_; }
  double& setFuncionObjetivo() { return funcion_objetivo_; }
  const std::vector<int>& getIndicesElementosIntroducidos() const { return indices_elementos_introducidos_; } 
  const Matriz& getCoordenadas() const { return coordenadas_; }
  Matriz& setCoordenadas() { return coordenadas_; }
  const std::vector<double>& operator[](const int kFila) const { return coordenadas_[kFila]; }
  friend std::ostream& operator<<(std::ostream&, const Solucion&);
 private:
  double funcion_objetivo_;
  Matriz coordenadas_;
  std::vector<int> indices_elementos_introducidos_;
};