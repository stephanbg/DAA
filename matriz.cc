#include <iostream>
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time()
#include <chrono> // Añadir esta línea para incluir la cabecera chrono

#include "matriz.h"

Matriz::Matriz() {
  // Inicializar la semilla con el tiempo actual
  auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
  srand(static_cast<unsigned>(seed));
  // Generar un número pseudoaleatorio entre 1 y 10
  int filasAleatorias = (rand() % 10) + 1;
  int columnasAleatorias = (rand() % 10) + 1;
  // Rellenar la matriz
  for (int i = 0; i < filasAleatorias; ++i) {
    std::vector<int> cadaFila;
    for (int j = 0; j < columnasAleatorias; ++j) {
      cadaFila.push_back(rand() % 100);
    }
    matriz_.push_back(cadaFila);
  }
}

void Matriz::imprimirMatriz() const {
  std::cout << "Matriz: " << std::endl;
  for (int i = 0; i < matriz_.size(); ++i) {
    for (int j = 0; j < matriz_[i].size(); ++j) {
      std::cout << matriz_[i][j] << " ";
    }
    std::cout << std::endl;
  }
}