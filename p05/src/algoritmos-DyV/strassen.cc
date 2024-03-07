/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 27 de Febrero de 2024
 * @file mergesort.cc
 * @brief Implementación de la clase MergeSort, que se encarga de
 * realizar dicho algoritmo
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p04/src}
 * @see {@link https://docs.google.com/document/d/1CcrG-85_oTdAkTo-zgXkudKT8C8z7T7m2hUHVLGUReQ/edit#heading=h.5bq8rsdy1ujx}
 */

#include "strassen.h"

/**
 * @brief Verifica si el problema dado es lo suficientemente pequeño
 * como para aplicar MergeSort.
 * @param kProblema Problema a evaluar.
 * @return true Si el problema es pequeño y MergeSort puede aplicarse,
 *    false en caso contrario.
 */
bool Strassen::Small(const Problema<std::vector<std::vector<std::vector<int>>>>* kProblema) const {
  // Verificar si la matriz es lo suficientemente pequeña para usar el algoritmo de Strassen
  return (kProblema->getProblema().size() <= 2);
}

/**
 * @brief Resuelve un problema pequeño utilizando MergeSort.
 * @param kProblema Problema pequeño a resolver.
 * @return Solución al problema.
 */
Solucion<std::vector<std::vector<int>>>* Strassen::SolveSmall(const Problema<std::vector<std::vector<std::vector<int>>>>* kProblema) const {
  // Resolver el problema pequeño directamente
  Solucion<std::vector<std::vector<int>>>* solucion = new SolucionMatricial();
  //solucion->setSolucion() = StrassenAlgorithm(kProblema->getProblema()[0], kProblema->getProblema()[1]);
  return solucion;
}

/**
 * @brief Divide el problema en dos subproblemas separados por
 * la mitad para aplicar MergeSort recursivamente.
 * @param kProblema Problema a dividir.
 * @param kSize Tamaño del problema.
 * @return Vector con los dos subproblemas resultantes
 *     de la división por la mitad.
 */
const std::vector<Problema<std::vector<std::vector<std::vector<int>>>>*> Strassen::Divide(
    const Problema<std::vector<std::vector<std::vector<int>>>>* kProblema,
    const int kSize) const {

}

/**
 * @brief Combina las soluciones de los subproblemas resultantes de la división.
 * @param kSoluciones Vector de soluciones de los subproblemas.
 * @return Solución combinada.
 */
Solucion<std::vector<std::vector<int>>>* Strassen::Combine(
    const std::vector<const Solucion<std::vector<std::vector<int>>>*>& kSoluciones) const {
  // Combinar las soluciones de los subproblemas
  Solucion<std::vector<std::vector<int>>>* solucion = new SolucionMatricial();
  const std::vector<std::vector<int>>& solucionA = kSoluciones[0]->getSolucion();
  const std::vector<std::vector<int>>& solucionB = kSoluciones[1]->getSolucion();
  // Combinar las soluciones en una sola matriz
  for (int i = 0; i < solucionA.size(); ++i) {
    std::vector<int> fila;
    for (int j = 0; j < solucionA[i].size(); ++j) {
      fila.push_back(solucionA[i][j]);
    }
    for (int j = 0; j < solucionB[i].size(); ++j) {
      fila.push_back(solucionB[i][j]);
    }
    solucion->setSolucion().push_back(fila);
  }
  return solucion;
}