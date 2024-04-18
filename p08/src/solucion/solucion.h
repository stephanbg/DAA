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
  void añadirElemento(const std::vector<double> kElemento) { coordenadas_.setMatriz().push_back(kElemento); }
  void setIndicesElementosIntroducidos(const int kIndiceElemento) { 
    indices_elementos_introducidos_.push_back(kIndiceElemento); 
  }
  const std::vector<int>& getIndicesElementosIntroducidos() const { return indices_elementos_introducidos_; }
  const Matriz& getCoordenadas() const { return coordenadas_; }
  friend std::ostream& operator<<(std::ostream&, const Solucion&);
 private:
  Matriz coordenadas_;
  std::vector<int> indices_elementos_introducidos_;
};