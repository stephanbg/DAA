#include "solucion-pila.h"

void SolucionPila::mostrarSolucion() const {
  std::stack<int> destino = pila_;
  while (!destino.empty()) {
    int pila_top = destino.top();
    std::cout << pila_top << std::endl;
    destino.pop();
  }
}