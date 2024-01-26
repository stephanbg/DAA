#include <iostream>

#include "matriz.h"
#include "funcionesNecesarias.h"

Matriz::Matriz() {
  generarSemillaRand();
  int filasAleatorias = generarNumerosAleatorias();
  int columnasAleatorias = generarNumerosAleatorias();
  // Rellenar la matriz
  for (int i = 0; i < filasAleatorias; ++i) {
    std::vector<long int> cadaFila;
    for (int j = 0; j < columnasAleatorias; ++j) {
      cadaFila.push_back(rand() % 100);
    }
    matriz_.push_back(cadaFila);
  }
}

std::ostream& operator<<(std::ostream& salida, const Matriz& matriz) {
  for (int i = 0; i < matriz.matriz_.size(); ++i) {
    for (int j = 0; j < matriz.matriz_[i].size(); ++j) {
      salida << matriz.matriz_[i][j] << " ";
    }
    salida << std::endl;
  }
  return salida;
}