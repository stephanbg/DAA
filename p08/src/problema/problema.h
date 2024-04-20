#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

#include "../matriz/matriz.h"
#include "../funciones/funciones.h"

class Problema {
 public:
  Problema() {}
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