#pragma once
#include "matriz.h"

class MatrizPorFilas : public Matriz {
public:
  MatrizPorFilas() : Matriz() {}
  void ejecutarAlgoritmo() override {
    std::cout << "Ejecutando algoritmo de MatrizPorFilas\n";
  }
};