/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 27 de Febrero de 2024
 * @file quicksort.cc
 * @brief Implementación de la clase QuickSort, que se encarga de
 * realizar dicho algoritmo
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p05/src}
 * @see {@link https://docs.google.com/document/d/1pwPk5iI5dRHo8M-raauPP5mgCUHy9m9j_au3UDkn_Rc/edit}
 */

#include "quicksort.h"

/**
 * @brief Verifica si el problema dado es lo suficientemente pequeño
 * como para aplicar QuickSort.
 * @param kProblema Problema a evaluar.
 * @return true Si el problema es pequeño y QuickSort puede aplicarse,
 *    false en caso contrario.
 */
bool QuickSort::Small(const Problema<std::vector<int>>* kProblema) const {
  return (kProblema->getProblema().size() <= 1) ? true : false;
}

/**
 * @brief Resuelve un problema pequeño utilizando QuickSort.
 * @param kProblema Problema pequeño a resolver.
 * @return Solución al problema.
 */
Solucion<std::vector<int>>* QuickSort::SolveSmall(const Problema<std::vector<int>>* kProblema) const {
  Solucion<std::vector<int>>* solucion = new SolucionVectorial();
  solucion->setSolucion() = kProblema->getProblema();
  return solucion;
}

/**
 * @brief Divide el problema en dos subproblemas separados por
 * un pivote para aplicar QuickSort recursivamente.
 * @param kProblema Problema a dividir.
 * @param kSize Tamaño del problema.
 * @return Vector con los dos subproblemas resultantes
 *     de la división por el pivote.
 */
const std::vector<Problema<std::vector<int>>*> QuickSort::Divide(
    const Problema<std::vector<int>>* kProblema,
    const int kSize) const {
  Problema<std::vector<int>>* menores = new ProblemaVectorial;
  Problema<std::vector<int>>* mayores = new ProblemaVectorial;
  const int kPivote = kProblema->getProblema()[kProblema->getProblema().size() - 1];
  mayores->setProblema().push_back(kPivote);
  for (int i = 0; i < kProblema->getProblema().size() - 1; i++) {
    if (kProblema->getProblema()[i] <= kPivote) {
      menores->setProblema().push_back(kProblema->getProblema()[i]);
    } else mayores->setProblema().push_back(kProblema->getProblema()[i]);
  }
  std::vector<Problema<std::vector<int>>*> resultado;
  resultado.push_back(menores);
  resultado.push_back(mayores);
  return resultado;
}

/**
 * @brief Combina las soluciones de los subproblemas resultantes de la división.
 * @param kSoluciones Vector de soluciones de los subproblemas.
 * @return Solución combinada.
 */
Solucion<std::vector<int>>* QuickSort::Combine(
    const std::vector<const Solucion<std::vector<int>>*>& kSoluciones) const {
  Solucion<std::vector<int>>* solucion = new SolucionVectorial();
  for (const Solucion<std::vector<int>>* subproblema : kSoluciones) {
    for (int elemento : subproblema->getSolucion()) {
      solucion->setSolucion().push_back(elemento);
    }
  }
  return solucion;
}