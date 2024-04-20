/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 19 de Abril de 2024
 * @file ejecutar_algoritmos.cc
 * @brief Implementación de la función que se encarga de ejecutar cualquier algoritmo
 * para maximizar la diversidad
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p08/src}
 */

#include "./ejecutar_algoritmos.h"

/**
 * @brief Ejecuta un algoritmo de diversidad máxima dado un problema y el número de elementos en la solución.
 * 
 * @param algoritmo Puntero al objeto que implementa el algoritmo a ejecutar.
 * @param problema El problema sobre el cual se ejecutará el algoritmo.
 * @param num_elementos_en_solucion El número de elementos que se deben incluir en la solución.
 * @return Un par que contiene la solución obtenida y el tiempo de ejecución del algoritmo.
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