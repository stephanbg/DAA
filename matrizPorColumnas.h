#pragma once
#include "matriz.h"

class MatrizPorColumnas : public Matriz {
public:
  MatrizPorColumnas() : Matriz() {}
  void ejecutarAlgoritmo() override {
    std::cout << "Ejecutando algoritmo de MatrizPorColumnas\n";
  }
};