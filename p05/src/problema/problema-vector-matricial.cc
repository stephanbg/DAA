#include "problema-vector-matricial.h"

void ProblemaVectorMatricial::mostrarProblema() const {
  const int kSize = problema_.size();
  // Recorrer el vector de matrices
  for (int i = 0; i < kSize; ++i) {
    std::cout << "Matriz " << i + 1 << ":" << std::endl;
    // Obtener la matriz actual
    const auto& matriz = problema_[i];
    // Recorrer la matriz actual
    for (const auto& fila : matriz) {
      for (const auto& elemento : fila) {
        std::cout << elemento << " ";
      }
      std::cout << std::endl; // Nueva línea para separar filas
    }
    std::cout << std::endl; // Nueva línea para separar matrices
  }
}

void ProblemaVectorMatricial::meterValores(const std::vector<std::vector<std::vector<int>>>& kMatrices) {
  const int kSize = kMatrices.size();
  const int kSizeProblema = problema_.size();
  if (kSizeProblema == kSize) {
    // Si los tamaños son iguales, simplemente copiamos las matrices
    for (int i = 0; i < kSize; ++i) {
      problema_[i] = kMatrices[i];
    }
  } else if (kSizeProblema < kSize) {
    // Si problema_ es más pequeño que kMatrices, copiamos las primeras matrices y agregamos las restantes
    for (int i = 0; i < kSizeProblema; ++i) {
      problema_[i] = kMatrices[i];
    }
    for (int i = kSizeProblema; i < kSize; ++i) {
      problema_.push_back(kMatrices[i]);
    }
  } else {
    // Si problema_ es más grande que kMatrices, truncamos problema_ y copiamos las matrices
    for (int i = 0; i < kSize; ++i) {
      problema_[i] = kMatrices[i];
    }
    problema_.resize(kSize);
  }
}