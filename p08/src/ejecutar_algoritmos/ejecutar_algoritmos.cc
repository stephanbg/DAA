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
std::pair<Solucion, int> ejecutarAlgoritmo(
  AlgoritmosDiversidadMaxima* algoritmo,
  Problema& problema,
  int num_elementos_en_solucion
) {
  // Crear un objeto ControladorTiempo con una función lambda como argumento
  ControladorTiempo<Solucion, Problema&, int> tiempo(
    [&](Problema& problema, int num_elementos_en_solucion) { 
      return algoritmo->ejecutar(problema, num_elementos_en_solucion);
    }
  );
  Solucion solucion = tiempo.medirTiempoFuncion(problema, std::move(num_elementos_en_solucion));
  return std::make_pair(solucion, tiempo.getDuracion());
}