#include "voraz_tsp.h"

void VorazTSP::ejecutar(const GrafoNoDirigidoCompleto& grafo) {
  auto ini = Clock::now();
  std::vector<bool> visitados(grafo.getGrafo().size(), false);
  int indice_nodo_actual = 0, indice_vecino;
  const Nodo* cada_nodo_ini = grafo.getGrafo()[indice_nodo_actual];
  const Nodo* nodoDestino;
  long double mejor_peso_destino;
  caminoMinimo_.push_back(cada_nodo_ini);
  visitados[indice_nodo_actual] = true;
  do {
    if (ControlTiempo::tiempoTranscurrido(ini, Clock::now())) {
      tiempoEjecucion_ = -1;
      calcularCoste();
      return;  
    }
    mejor_peso_destino = -1;
    // Recorro todos los vecinos buscando el mejor no visitado
    for (const auto& vecino : cada_nodo_ini->getNodosVecinos()) {
      indice_vecino = grafo.getIndiceNodo(vecino.getNodoDestino()->getId());
      if (!(visitados[indice_vecino]) &&
           (mejor_peso_destino == -1 || vecino.getPeso() < mejor_peso_destino)) {
        nodoDestino = vecino.getNodoDestino();
        mejor_peso_destino = vecino.getPeso();
      }
    }
    // El nuevo nodo es el vecino
    cada_nodo_ini = nodoDestino;
    caminoMinimo_.push_back(cada_nodo_ini); // Lo añado al camino mínimo
    indice_nodo_actual = grafo.getIndiceNodo(cada_nodo_ini->getId());
    visitados[indice_nodo_actual] = true; // Lo marco ha visitado (vecino)
  } while (contieneFalso(visitados));
  caminoMinimo_.push_back(grafo.getGrafo()[0]);
  auto fin = Clock::now();
  tiempoEjecucion_ = (std::chrono::duration_cast<std::chrono::milliseconds>(fin - ini)).count();
  calcularCoste();
}

void VorazTSP::mostrarCaminoMinimo() const {
  std::cout << "Camino mínimo para algoritmo Voraz\n";
  std::cout << "----------------------------------" << std::endl;
  const int kSizeCaminoMinimo = caminoMinimo_.size();
  for (int i = 0; i < kSizeCaminoMinimo; ++i) {
    std::cout << caminoMinimo_[i]->getId();
    if (i < kSizeCaminoMinimo - 1) std::cout << " -> ";
  }
  std::cout << std::endl;
}

void VorazTSP::mostrarTiempoEjecución() const {
  std::cout << "Tiempo de ejecución para algoritmo Voraz\n";
  std::cout << "----------------------------------------" << std::endl;
  std::cout << tiempoEjecucion_ << " ms" << std::endl;
}