#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

#include "../matriz/matriz.h"
#include "../funciones/funciones.h"

class Solucion {
 public:
  Solucion(): funcion_objetivo_(0) {};
  void añadirNuevoElementoEIndice(const std::vector<double>, const int);
  void insertarNuevoPuntoEIndice(const int, const std::vector<double>&, const int);
  void insertarNuevoPunto(const int kIndice, const std::vector<double>&);
  const int size() const { return coordenadas_.size(); }
  const double getFuncionObjetivo() const { return funcion_objetivo_; }
  double& setFuncionObjetivo() { return funcion_objetivo_; }
  const std::vector<int>& getIndicesElementosIntroducidos() const { return indices_elementos_introducidos_; } 
  const Matriz& getCoordenadas() const { return coordenadas_; }
  Matriz& setCoordenadas() { return coordenadas_; }
  const std::vector<double>& operator[](const int kFila) const { return coordenadas_[kFila]; }
  friend std::ostream& operator<<(std::ostream&, const Solucion&);
 private:
  Matriz coordenadas_;
  double funcion_objetivo_;
  std::vector<int> indices_elementos_introducidos_;
};