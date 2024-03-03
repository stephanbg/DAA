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

#include "mergesort.h"

/**
 * @brief Verifica si el problema dado es lo suficientemente pequeño
 * como para aplicar MergeSort.
 * @param kProblema Problema a evaluar.
 * @return true Si el problema es pequeño y MergeSort puede aplicarse,
 *    false en caso contrario.
 */
bool MergeSort::Small(const Problema<std::vector<int>>* kProblema) const {
  return (kProblema->getProblema().size() <= 1) ? true : false;
}

/**
 * @brief Resuelve un problema pequeño utilizando MergeSort.
 * @param kProblema Problema pequeño a resolver.
 * @return Solución al problema.
 */
Solucion<std::vector<int>>* MergeSort::SolveSmall(const Problema<std::vector<int>>* kProblema) const {
  Solucion<std::vector<int>>* solucion = new SolucionVectorial();
  solucion->setSolucion() = kProblema->getProblema();
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
const std::vector<Problema<std::vector<int>>*> MergeSort::Divide(
    const Problema<std::vector<int>>* kProblema,
    const int kSize) const {
  const size_t kMitad = kSize / 2;
  std::vector<Problema<std::vector<int>>*> resultado(2);
  resultado[0] = new ProblemaVectorial();
  resultado[1] = new ProblemaVectorial();  
  for (int i = 0; i < kSize; ++i) {
    const int kElemento = kProblema->getProblema()[i];
    if (i < kMitad) resultado[0]->setProblema().push_back(kElemento);
    else resultado[1]->setProblema().push_back(kElemento);
  }
  return resultado;
}

/**
 * @brief Combina las soluciones de los subproblemas resultantes de la división.
 * @param kSoluciones Vector de soluciones de los subproblemas.
 * @return Solución combinada.
 */
Solucion<std::vector<int>>* MergeSort::Combine(
    const std::vector<const Solucion<std::vector<int>>*>& kSoluciones) const {
  Solucion<std::vector<int>>* solucion = new SolucionVectorial();
  const Solucion<std::vector<int>>* kSolucionIzq = kSoluciones[0];
  const Solucion<std::vector<int>>* kSolucionDerech = kSoluciones[1];
  const int kSizeSolucionIzq = kSolucionIzq->getSolucion().size();
  const int kSizeSolucionDerech = kSolucionDerech->getSolucion().size();
  size_t indice_izquierda = 0;
  size_t indice_derecha = 0;
  while (indice_izquierda < kSizeSolucionIzq && indice_derecha < kSizeSolucionDerech) {
    const int kElementoIzq = kSolucionIzq->getSolucion()[indice_izquierda];
    const int kElementoDerech = kSolucionDerech->getSolucion()[indice_derecha]; 
    if (kElementoIzq <= kElementoDerech) {
      solucion->setSolucion().push_back(kElementoIzq);
      indice_izquierda++;
    } else {
      solucion->setSolucion().push_back(kElementoDerech);
      indice_derecha++;
    }
  }
  // Agregar los elementos restantes de izquierda a resultado
  while (indice_izquierda < kSizeSolucionIzq) {
    solucion->setSolucion().push_back(kSolucionIzq->getSolucion()[indice_izquierda++]);
  }
  // Agregar los elementos restantes de derecha a resultado
  while (indice_derecha < kSizeSolucionDerech) {
    solucion->setSolucion().push_back(kSolucionDerech->getSolucion()[indice_derecha++]);
  }
  return solucion;
}