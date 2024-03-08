#include "problema-vector-pilas.h"

void ProblemaVectorPilas::mostrarProblema() const {
  const int kSize = pilas_.size();
  std::stack<int> cada_pila;
  for (int i = 0; i < kSize; ++i) {
    if (!pilas_[i].empty()) std::cout << "PILA " << i + 1 << ":\n";
    cada_pila = pilas_[i];
    while (!cada_pila.empty()) {
      int pila_top = cada_pila.top();
      std::cout << pila_top << std::endl;
      cada_pila.pop();
    }
    if (!pilas_[i].empty()) std::cout << std::endl;
  }
}

void ProblemaVectorPilas::meterValores(const int kPosPila, const std::vector<int>& kValores) {
  const int kSize = kValores.size();
  for (int i = 0; i < kSize; ++i) {
    pilas_[kPosPila].push(kValores[i]);
  }
}

void ProblemaVectorPilas::generadorInstanciaAleatoria() {
  const int kSizeInstancia = rand() % 5 + 1;
  std::vector<int> pilaOrigen;
  for (int pos = 0; pos < kSizeInstancia; ++pos) {
    pilaOrigen.push_back(rand() % 1000 + 1);
  }
  std::sort(pilaOrigen.begin(), pilaOrigen.end());
  for (const auto& elemento : pilaOrigen) {
    pilas_[0].push(elemento);
  }
}