#include "programacion_dinamica_tsp.h"

void ProgramacionDinamicaTSP::ejecutar(const GrafoNoDirigidoCompleto& grafo) {
  auto ini = Clock::now();
  const std::vector<Nodo*>& nodos = grafo.getGrafo(); 
  // Inicializamos la tabla de programación dinámica para almacenar los costos
  std::vector<std::vector<long double>> tablaCostes(
    pow(2, nodos.size()),
    std::vector<long double>(nodos.size(), std::numeric_limits<long double>::infinity())
  );
  // Inicializamos la tabla de programación dinámica para almacenar los índices de los nodos
  std::vector<std::vector<int>> tablaNodos(1 << nodos.size(), std::vector<int>(nodos.size(), -1));
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
            long double costo = tablaCostes[mask ^ (1 << j)][k] + nodos[k]->getCoste(nodos[j]);
            // Si se actualiza el costo, actualiza también el nodo anterior
            if (costo < tablaCostes[mask][j]) {
              tablaCostes[mask][j] = costo; // Almacena el nodo anterior que lleva al nodo actual j
              tablaNodos[mask][j] = k;
            }
          }
        }
      }
    }
  }
  for (auto a : tablaCostes) {
    for (auto b : a ) {
      std::cout << b << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  for (auto a : tablaNodos) {
    for (auto b : a ) {
      std::cout << b << " ";
    }
    std::cout << std::endl;
  }  
  reconstruirCaminoMinimo(tablaNodos, grafo);
  calcularCoste();
  // Implementar el algoritmo de Programación Dinámica para calcular los costos mínimos
  auto fin = Clock::now();
  tiempoEjecucion_ = std::chrono::duration_cast<std::chrono::milliseconds>(fin - ini).count();
}

void ProgramacionDinamicaTSP::reconstruirCaminoMinimo(
  const std::vector<std::vector<int>>& kTablaNodos,
  const GrafoNoDirigidoCompleto& kGrafo
) {
  std::vector<const Nodo*> recorrido;
  const int kNumNodos = kGrafo.getGrafo().size();
  int nodoActual = 0; // Empezamos desde el nodo 0 (índice 0)
  int mascara = (1 << kNumNodos) - 1; // Máscara que representa todos los nodos visitados
  // Recorremos la tabla de nodos previos para reconstruir el camino
  while (true) {
    recorrido.push_back(kGrafo.getGrafo()[nodoActual]); // Agregamos el nodo actual al camino
    int siguienteNodo = kTablaNodos[mascara][nodoActual]; // Obtenemos el siguiente nodo previo
    if (siguienteNodo == -1 || siguienteNodo == 0) break;
    mascara ^= (1 << siguienteNodo);
    nodoActual = siguienteNodo;
  }
  recorrido.push_back(kGrafo.getGrafo()[0]);
  reverse(recorrido.begin(), recorrido.end());  
  caminoMinimo_ = recorrido;
  mostrarCaminoMinimo();
  exit(EXIT_FAILURE);
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