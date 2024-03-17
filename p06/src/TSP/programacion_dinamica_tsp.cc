/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Marzo de 2024
 * @file programacion_dinamica_tsp.cc
 * @brief Implementación de la clase ProgramacionDinamicaTSP que hereda de la clase TSP
 * para resolver dicho problema
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p06/src}
 * @see {@link https://docs.google.com/document/d/1a691HPtHQL4qBtI2qaTMTp23wxZvU8-CCIbGOyNJRQo/edit}
 */

#include "programacion_dinamica_tsp.h"

/**
 * @brief Inicializa la tabla de costos con infinito para todas las combinaciones de nodos.
 * 
 * @param kNodos Vector de punteros a nodos del grafo.
 * @return Tabla de costos inicializada.
 */
std::vector<std::vector<long double>> ProgramacionDinamicaTSP::inicializarTablaCostos(
  const std::vector<Nodo*>& kNodos
) {
  // Inicializamos la tabla de programación dinámica para almacenar los índices de los nodos
  return std::vector<std::vector<long double>>(
    (1 << kNodos.size()),
    std::vector<long double>(kNodos.size(), std::numeric_limits<long double>::infinity())
  );
}

/**
 * @brief Inicializa la tabla de nodos previos con -1 para todas las combinaciones de nodos.
 * 
 * @param kNodos Vector de punteros a nodos del grafo.
 * @return Tabla de nodos previos inicializada.
 */
std::vector<std::vector<int>> ProgramacionDinamicaTSP::inicializarTablaNodos(
  const std::vector<Nodo*>& kNodos
) {
  // Inicializamos la tabla de programación dinámica para almacenar los costos
  return std::vector<std::vector<int>>(
    (1 << kNodos.size()),
    std::vector<int>(kNodos.size(), -1)
  );
}

/**
 * @brief Ejecuta el algoritmo de programación dinámica para resolver el Problema del Viajante de Comercio.
 * 
 * @param grafo Grafo no dirigido completo que representa el problema del viajante de comercio.
 */
void ProgramacionDinamicaTSP::ejecutar(const GrafoNoDirigidoCompleto& grafo) {
  auto ini = Clock::now();
  const std::vector<Nodo*>& kNodos = grafo.getGrafo(); 
  std::vector<std::vector<long double>> tabla_costes = inicializarTablaCostos(kNodos);
  std::vector<std::vector<int>> tabla_nodos = inicializarTablaNodos(kNodos);
  rellenarTablas(kNodos, tabla_costes, tabla_nodos, ini);
  reconstruirCaminoMinimo(tabla_nodos, grafo);
  calcularCoste();
  auto fin = Clock::now();
  tiempoEjecucion_ = std::chrono::duration_cast<std::chrono::microseconds>(fin - ini).count();
}

/**
 * @brief Rellena las tablas de costos y nodos previos necesarias para el algoritmo de programación dinámica.
 * 
 * @param kNodos Vector de punteros a nodos del grafo.
 * @param tabla_costes Tabla de costos a llenar.
 * @param tabla_nodos Tabla de nodos previos a llenar.
 * @param kIni Marca de tiempo de inicio de la ejecución.
 */
void ProgramacionDinamicaTSP::rellenarTablas(
  const std::vector<Nodo*>& kNodos, 
  std::vector<std::vector<long double>>& tabla_costes,
  std::vector<std::vector<int>>& tabla_nodos,
  const std::chrono::high_resolution_clock::time_point& kIni
) {
  // Paso base: inicializar los costos para subconjuntos de una sola ciudad
  for (int i = 0; i < kNodos.size(); ++i) {
    tabla_costes[1 << i][i] = 0.0; // El costo de ir de una ciudad a sí misma es 0
  }
  // Calcular los costos e índices previos utilizando la matriz de adyacencia del grafo
  for (int mask = 1; mask < tabla_nodos.size(); ++mask) {
    for (int j = 0; j < kNodos.size(); ++j) {
      if (mask & (1 << j)) { // Saltarse coste de ir de una ciudad a sí misma
        for (int k = 0; k < kNodos.size(); ++k) {
          if ((k != j) && (mask & (1 << k))) {
            long double costo = tabla_costes[mask ^ (1 << j)][k] + kNodos[k]->getCoste(kNodos[j]);
            // Si se actualiza el costo, actualiza también el nodo anterior
            if (costo < tabla_costes[mask][j]) {
              tabla_costes[mask][j] = costo;
              tabla_nodos[mask][j] = k;
            }
            if (ControlTiempo::tiempoTranscurrido(kIni, Clock::now())) {
              tiempoEjecucion_ = -1;
              return;
            }
          }
        }
      }
    }
  }
  for (auto a : tabla_costes) {
    for (auto b : a) {
      std::cout << b << " ";
    }
    std::cout << std::endl;
  }
  for (auto a : tabla_nodos) {
    for (auto b : a) {
      std::cout << b << " ";
    }
    std::cout << std::endl;
  }
}

/**
 * @brief Reconstruye el camino mínimo a partir de la tabla de nodos previos.
 * 
 * @param kTablaNodos Tabla de nodos previos generada durante la ejecución del algoritmo.
 * @param kGrafo Grafo no dirigido completo que representa el problema del viajante de comercio.
 */
void ProgramacionDinamicaTSP::reconstruirCaminoMinimo(
  const std::vector<std::vector<int>>& kTablaNodos,
  const GrafoNoDirigidoCompleto& kGrafo
) {
  std::vector<const Nodo*> recorrido;
  const int kNumNodos = kGrafo.getGrafo().size();
  int nodo_actual = 0;
  int mascara = (1 << kNumNodos) - 1;
  // Recorremos la tabla de nodos previos para reconstruir el camino
  // Mientras queden nodos sin visitar
  while (mascara != 0) {
    recorrido.push_back(kGrafo.getGrafo()[nodo_actual]); // Agregamos el nodo actual al camino
    int nodo_anterior = kTablaNodos[mascara][nodo_actual]; // Obtenemos el siguiente nodo previo
    mascara ^= (1 << nodo_actual);
    nodo_actual = nodo_anterior;
  }
  recorrido.push_back(kGrafo.getGrafo()[0]);
  reverse(recorrido.begin(), recorrido.end());  
  caminoMinimo_ = recorrido;
}

/**
 * @brief Muestra el camino mínimo
 * 
 */
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

/**
 * @brief Muestra el tiempo de ejecución
 * 
 */
void ProgramacionDinamicaTSP::mostrarTiempoEjecución() const {
  std::cout << "Tiempo de ejecución para algoritmo Programacion Dinamica\n";
  std::cout << "--------------------------------------------------------" << std::endl;
  std::cout << tiempoEjecucion_ << " µs" << std::endl;
}