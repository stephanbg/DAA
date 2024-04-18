#pragma once

#include <iostream>
#include <iomanip>
#include <vector>

#include "../funciones/funciones.h"

class Matriz {
 public:
  Matriz() {};
  Matriz(const int kFilas, const int kColumnas) :
      matriz_(kFilas, std::vector<double>(kColumnas, 0.0)) {};
  bool empty() { return matriz_.empty(); }
  void eliminarElemento(const std::vector<double>&);   
  const std::vector<std::vector<double>>& getMatriz() const { return matriz_; }
  std::vector<std::vector<double>>& setMatriz() { return matriz_; }
  const std::vector<double>& operator[](const int kFila) const { return matriz_[kFila]; }
  std::vector<double>& operator[](const int kFila) { return matriz_[kFila]; }
  friend std::ostream& operator<<(std::ostream&, const Matriz&);
 private:
  std::vector<std::vector<double>> matriz_;
};