#include "solucion-matricial.h"

void SolucionMatricial::mostrarSolucion() const {
  std::cout << "Matriz Solución: " << std::endl;
  for (const auto& fila : solucion_) {
    for (const auto& elemento : fila) {
      std::cout << elemento << " ";
    }
    std::cout << std::endl; // Nueva línea para separar filas
  }
}