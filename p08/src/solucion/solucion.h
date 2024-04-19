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
  void añadirElemento(const std::vector<double> kElemento) { coordenadas_.setMatriz().push_back(kElemento); }
  void añadirIndiceElemento(const int kIndiceElemento) { 
    indices_elementos_introducidos_.push_back(kIndiceElemento); 
  }  
  void swapPuntosDelEspacio(const int, const int);
  const double getFuncionObjetivo() const { return funcion_objetivo_; }
  double& setFuncionObjetivo() { return funcion_objetivo_; }
  const std::vector<int>& getIndicesElementosIntroducidos() const { return indices_elementos_introducidos_; } 
  const Matriz& getCoordenadas() const { return coordenadas_; }
  Matriz& setCoordenadas() { return coordenadas_; }
  friend std::ostream& operator<<(std::ostream&, const Solucion&);
 private:
  Matriz coordenadas_;
  double funcion_objetivo_;
  std::vector<int> indices_elementos_introducidos_;
};