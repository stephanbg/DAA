/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Marzo de 2024
 * @file sintaxis_fichero_grafo.cc
 * @brief Implementación de la clase SintaxisFicheroGrafo
 * que comrpueba la sintaxis de los ficheros que contienen descripciones de grafos
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p06/src}
 * @see {@link https://docs.google.com/document/d/1a691HPtHQL4qBtI2qaTMTp23wxZvU8-CCIbGOyNJRQo/edit}
 */

#include "sintaxis_fichero_grafo.h"

/**
 * @brief Verifica si el número de nodos especificado en una cadena es válido.
 * 
 * @param kNumNodosDeFichero Cadena que representa el número de nodos.
 * @return true si el número de nodos es válido (mayor o igual a 2), false en caso contrario.
 */
const bool SintaxisFicheroGrafo::numeroNodosValido(const std::string& kNumNodosDeFichero) {
  if (kNumNodosDeFichero.empty()) return false;
  if (!esNumeroEnteroSinSigno(kNumNodosDeFichero)) return false;
  if (stoi(kNumNodosDeFichero) < 2) return false; // Con menos de 2 nodos no se puede formar 1 grafo 
  return true;
}

/**
 * @brief Verifica si una línea del archivo de grafo tiene tres elementos válidos: nodo1, nodo2 y peso de la arista.
 * 
 * @param cada_linea Vector de cadenas que contiene los elementos de la línea del archivo.
 * @return true si la línea tiene tres elementos válidos, false en caso contrario.
 */
const bool SintaxisFicheroGrafo::tresElementosPorLineaNodo1Nodo2Coste(
  const std::vector<std::string>& cada_linea
) {
  if (cada_linea.size() != 3) return false;
  if (!esNumeroSinSigno(cada_linea[2])) return false; // Coste numero positivo
  if (stold(cada_linea[2]) == 0) return false; // No puede ser 0
  return true;
}