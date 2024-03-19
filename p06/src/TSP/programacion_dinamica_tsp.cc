/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Marzo de 2024
 * @file floyd_warshall_tsp.cc
 * @brief Implementación de la clase FloydWarshallTSP que hereda de la clase TSP
 * para resolver dicho problema utilizando el algoritmo de Floyd-Warshall
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p06/src}
 * @see {@link https://docs.google.com/document/d/1a691HPtHQL4qBtI2qaTMTp23wxZvU8-CCIbGOyNJRQo/edit}
 */

#include "programacion_dinamica_tsp.h"

/**
 * @brief Inicializa la matriz de distancias entre nodos del grafo.
 * 
 * @param kGrafo El grafo completo.
 * @param kNumNodos El número de nodos en el grafo.
 * @return La matriz de distancias entre nodos.
 */
std::vector<std::vector<int>> ProgramacionDinamicaTSP::inicializarDistanciasVecinos(
  const std::vector<Nodo*>& kGrafo,
  const int kNumNodos
) {
  std::vector<std::vector<int>> distancias_vecinos(kNumNodos, std::vector<int>(kNumNodos));
  for (int i = 0; i < kNumNodos; ++i) {
    for (int j = 0; j < kNumNodos; ++j) {
      if (i != j) distancias_vecinos[i][j] = kGrafo[i]->getCoste(kGrafo[j]);
    }
  }
  return distancias_vecinos;
}

/**
 * @brief Inicializa un vector de vectores con el tamaño correcto y con valores iniciales.
 * 
 * @param kNumNodos El número de nodos.
 * @return El vector de vectores inicializado.
 */
std::vector<std::vector<int>> ProgramacionDinamicaTSP::inicializarVectores(const int kNumNodos) {
  return std::vector<std::vector<int>>(1 << kNumNodos, std::vector<int>(kNumNodos, -1));
}

/**
 * @brief Reconstruye el camino mínimo a partir de los nodos intermedios calculados.
 * 
 * @param kGrafo El grafo completo.
 * @param kNodosIntermedios Los nodos intermedios calculados por el algoritmo de Held-Karp.
 * @param kIni El momento en que comenzó la ejecución del algoritmo.
 */
void ProgramacionDinamicaTSP::reconstruirCaminoMinimo(
  const std::vector<Nodo*> kGrafo,
  const std::vector<std::vector<int>>& kNodosIntermedios,
  const std::chrono::high_resolution_clock::time_point& kIni
) {
  int mascara = 1;
  int nodo_actual = 0;
  while (true) {
    caminoMinimo_.push_back(kGrafo[nodo_actual]);
    if (ControlTiempo::tiempoTranscurrido(kIni, Clock::now())) {
      tiempoEjecucion_ = -1;
      calcularCoste();
      return;
    }    
    int siguiente_nodo = kNodosIntermedios[mascara][nodo_actual];
    if (siguiente_nodo == -1) break;
    mascara |= 1 << siguiente_nodo;
    nodo_actual = siguiente_nodo;
  }
  caminoMinimo_.push_back(kGrafo[0]);
}

/**
 * @brief Calcula el costo mínimo del recorrido utilizando el algoritmo de Held-Karp.
 * 
 * @param distancias_vecinos La matriz de distancias entre nodos.
 * @param kPos La posición actual en el recorrido.
 * @param kMascara La máscara que representa los nodos visitados.
 * @param costos_minimos El vector de vectores que almacena los costos mínimos.
 * @param nodos_intermedios El vector de vectores que almacena los nodos intermedios.
 * @param kIni El momento en que comenzó la ejecución del algoritmo.
 * @return El costo mínimo del recorrido.
 */
int ProgramacionDinamicaTSP::HeldKarp(
  const std::vector<std::vector<int>>& distancias_vecinos,
  const int kPos, const int kMascara,
  std::vector<std::vector<int>>& costos_minimos,
  std::vector<std::vector<int>>& nodos_intermedios,
  const std::chrono::high_resolution_clock::time_point& kIni
) {
  const int kSizeDistancias = distancias_vecinos.size();
  // Caso base: Se han visitado todos los nodos (volver inicio)
  if (kMascara == (1 << kSizeDistancias) - 1) return distancias_vecinos[kPos][0];
  // Si este estado ya ha sido calculado, regresar el resultado almacenado
  if (costos_minimos[kMascara][kPos] != -1) return costos_minimos[kMascara][kPos];
  int coste_minimo = std::numeric_limits<int>::max();
  int mejor_siguiente_nodo = -1;
  // Intentar ir a cada nodo que aún no ha sido visitado
  for (int siguiente_nodo = 0; siguiente_nodo < kSizeDistancias; ++siguiente_nodo) {
    if (ControlTiempo::tiempoTranscurrido(kIni, Clock::now())) {
      tiempoEjecucion_ = -1;
      coste_ = coste_minimo;
      return coste_minimo;
    }
    if ((kMascara & (1 << siguiente_nodo)) == 0) {
      int nueva_mascara = kMascara | (1 << siguiente_nodo);
      // Calcula coste para un nuevo camino
      int nuevo_costo = distancias_vecinos[kPos][siguiente_nodo]
          + HeldKarp(
              distancias_vecinos, siguiente_nodo,
              nueva_mascara, costos_minimos, nodos_intermedios, kIni
            );
      if (nuevo_costo < coste_minimo) { // Se actualiza si es mejor
        coste_minimo = nuevo_costo;
        mejor_siguiente_nodo = siguiente_nodo;
      }
    }
  }
  costos_minimos[kMascara][kPos] = coste_minimo;
  nodos_intermedios[kMascara][kPos] = mejor_siguiente_nodo;
  return coste_minimo;
}

/**
 * @brief Ejecuta el algoritmo para resolver el problema del TSP utilizando programación dinámica.
 * 
 * @param grafo El grafo completo.
 */
void ProgramacionDinamicaTSP::ejecutar(const GrafoNoDirigidoCompleto& grafo) {
  auto ini = Clock::now();
  const std::vector<Nodo*> kGrafo = grafo.getGrafo();
  const int kNumNodos = kGrafo.size();
  std::vector<std::vector<int>> distancias_vecinos = inicializarDistanciasVecinos(kGrafo, kNumNodos);
  std::vector<std::vector<int>> costos_minimos = inicializarVectores(kNumNodos); 
  std::vector<std::vector<int>> nodos_intermedios = inicializarVectores(kNumNodos);
  HeldKarp(distancias_vecinos, 0, 1, costos_minimos, nodos_intermedios, ini);
  reconstruirCaminoMinimo(kGrafo, nodos_intermedios, ini);
  auto fin = Clock::now();
  calcularCoste();
  tiempoEjecucion_ = std::chrono::duration_cast<std::chrono::microseconds>(fin - ini).count();
}

/**
 * @brief Muestra el camino mínimo.
 * 
 */
void ProgramacionDinamicaTSP::mostrarCaminoMinimo() const {
  std::cout << "Camino mínimo para algoritmo Programación Dinámica\n";
  std::cout << "--------------------------------------------" << std::endl;
  const int kSizeCaminoMinimo = caminoMinimo_.size();
  for (int i = 0; i < kSizeCaminoMinimo; ++i) {
    std::cout << caminoMinimo_[i]->getId();
    if (i < kSizeCaminoMinimo - 1) std::cout << " -> ";
  }
  std::cout << std::endl;
}

/**
 * @brief Muestra el tiempo de ejecución.
 * 
 */
void ProgramacionDinamicaTSP::mostrarTiempoEjecución() const {
  std::cout << "Tiempo de ejecución para algoritmo Floyd-Warshall\n";
  std::cout << "--------------------------------------------------" << std::endl;
  std::cout << tiempoEjecucion_ << " µs" << std::endl;
}