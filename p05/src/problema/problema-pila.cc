#include "problema-pila.h"

void ProblemaPila::mostrarProblema() const {
  std::stack<int> origen = pila_;
  while (!origen.empty()) {
    int pila_top = origen.top();
    std::cout << pila_top << std::endl;
    origen.pop();
  }
}