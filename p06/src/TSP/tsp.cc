#include "tsp.h"

const long double TSP::calcularCoste() {
  coste_ = 0.0;
  for (int i = 0; i < caminoMinimo_.size() - 1; ++i) {
    const Nodo* nodo_actual = caminoMinimo_[i];
    const Nodo* nodo_siguiente = caminoMinimo_[i + 1];
    const auto& vecinos = nodo_actual->getNodosVecinos();
    for (const auto& vecino : vecinos) {
      if (vecino.getNodoDestino() == nodo_siguiente) {
        coste_ += vecino.getPeso();
        break;
      }
    }
  }
  return coste_;
}

void TSP::mostrarCoste() {
  std::cout << "Coste del camino mínimo:\n";
  std::cout << "------------------------\n";
  std::cout << coste_ << std::endl;
}