/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 1 de Abril de 2024
 * @file ejecutar_algoritmos.cc
 * @brief Implementación de la función que se encarga de ejecutar cualquier algoritmo
 * para minimizar el TCT
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07/src}
 */

#include "./ejecutar_algoritmos.h"

/**
 * @brief Ejecuta un algoritmo para minimizar el tiempo de ciclo total (TCT) en un problema dado.
 * 
 * @param algoritmo Puntero al objeto del algoritmo a ejecutar.
 * @param numero_maquinas Número de máquinas en el problema.
 * @param grafo El problema que se resolverá.
 * @return Un par que contiene un vector de soluciones y el tiempo de ejecución del algoritmo.
 */
std::pair<std::vector<Solucion>, int> ejecutarAlgoritmo(
  AlgoritmoMinimizarTCT* algoritmo,
  int numero_maquinas,
  Problema& grafo
) {
  // Crear un objeto ControladorTiempo con una función lambda como argumento
  ControladorTiempo<std::vector<Solucion>, int, Problema&> tiempo(
    [&](int numeroMaquinas, Problema& grafo) { return algoritmo->ejecutar(numeroMaquinas, grafo, 100); }
  );
  // Medir el tiempo de ejecución y obtener las soluciones
  std::vector<Solucion> maquinas = tiempo.medirTiempoFuncion(std::move(numero_maquinas), grafo);
  // Devolver las soluciones y el tiempo de ejecución
  return std::make_pair(std::move(maquinas), tiempo.getDuracion());
}