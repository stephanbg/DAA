#include "programacion_dinamica_tsp.h"

void ProgramacionDinamicaTSP::ejecutar(const GrafoNoDirigidoCompleto& grafo) {
  auto ini = Clock::now();
  // Obtenemos la lista de nodos del grafo
  const std::vector<Nodo*>& nodos = grafo.getGrafo(); 
  // Inicializamos la tabla de programación dinámica para almacenar los costos
  std::vector<std::vector<long double>> tablaCostes(
    pow(2, nodos.size()),
    std::vector<long double>(nodos.size(), std::numeric_limits<long double>::infinity())
  );
  std::vector<std::vector<long double>> tablaNodos(
    pow(2, nodos.size()),
    std::vector<long double>(nodos.size(), std::numeric_limits<long double>::infinity())
  );  
  // Paso base: inicializar los costos para subconjuntos de una sola ciudad
  for (int i = 0; i < nodos.size(); ++i) {
    tablaCostes[1 << i][i] = 0.0; // El costo de ir de una ciudad a sí misma es 0
  }
  // Calcular los costos iniciales utilizando la matriz de adyacencia del grafo
  for (int mask = 1; mask < (1 << nodos.size()); ++mask) {
    for (int j = 0; j < nodos.size(); ++j) {
      if (mask & (1 << j)) {
        for (int k = 0; k < nodos.size(); ++k) {
          if ((k != j) && (mask & (1 << k))) {
            long double costo = nodos[k]->getCoste(nodos[j]);
            tablaCostes[mask][j] = std::min(tablaCostes[mask][j], tablaCostes[mask - (1 << j)][k] + costo);
            // Si se actualiza el costo, actualiza también el nodo anterior
            if (tablaCostes[mask][j] != tablaCostes[mask - (1 << j)][k] + costo) {
              tablaNodos[mask][j] = k; // Almacena el nodo anterior que lleva al nodo actual j
              std::cout << k << std::endl;
              ///////////////////////////////////// ERROR POR AQUI;
            }
          }
        }
      }
    }
  }
  reconstruirCaminoMinimo(tablaNodos, grafo);
  coste_ = tablaCostes[pow(2, nodos.size()) - 1][0];
  // Implementar el algoritmo de Programación Dinámica para calcular los costos mínimos
  auto fin = Clock::now();
  tiempoEjecucion_ = std::chrono::duration_cast<std::chrono::milliseconds>(fin - ini).count();
}

void ProgramacionDinamicaTSP::reconstruirCaminoMinimo(
  const std::vector<std::vector<long double>>& kTablaNodos,
  const GrafoNoDirigidoCompleto& kGrafo
) {
  const int kNumNodos = kGrafo.getGrafo().size();
  std::vector<const Nodo*> recorrido;
  int mask = (1 << kNumNodos) - 1;
  int ultimo_nodo = 0;
  //std::cout << mask << std::endl;
  //std::cout << kNumNodos << std::endl;
  while (ultimo_nodo != -1) {
    std::cout << "ultimo_nodo: " << ultimo_nodo << std::endl;
    recorrido.push_back(kGrafo.getGrafo()[ultimo_nodo]);
    int siguiente_nodo = kTablaNodos[mask][ultimo_nodo];
    std::cout << "siguiente_nodo: " << siguiente_nodo << std::endl;
    mask ^= (1 << siguiente_nodo);
    ultimo_nodo = siguiente_nodo;
    std::cout << "ultimo_nodo: " << ultimo_nodo << std::endl;
    exit(EXIT_FAILURE);
  }
  recorrido.push_back(kGrafo.getGrafo()[0]);
  std::reverse(recorrido.begin(), recorrido.end());
  caminoMinimo_ = recorrido;
}

void ProgramacionDinamicaTSP::mostrarCaminoMinimo() const {
  std::cout << "Camino mínimo para algoritmo Programacion Dinamica\n";
  std::cout << "--------------------------------------------------" << std::endl;
  const int kSizeCaminoMinimo = caminoMinimo_.size();
  for (int i = 0; i < kSizeCaminoMinimo; ++i) {
    std::cout << caminoMinimo_[i]->getId();
    if (i < kSizeCaminoMinimo - 1) std::cout << " -> ";
  }
  std::cout << std::endl;
}

void ProgramacionDinamicaTSP::mostrarTiempoEjecución() const {
  std::cout << "Tiempo de ejecución para algoritmo Programacion Dinamica\n";
  std::cout << "--------------------------------------------------------" << std::endl;
  std::cout << tiempoEjecucion_ << " ms" << std::endl;
}