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
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p05/src}
 * @see {@link https://docs.google.com/document/d/1pwPk5iI5dRHo8M-raauPP5mgCUHy9m9j_au3UDkn_Rc/edit}
 */

#include "fibonacci.h"

/**
 * @brief Verifica si el problema dado es lo suficientemente pequeño
 * como para aplicar MergeSort.
 * @param kProblema Problema a evaluar.
 * @return true Si el problema es pequeño y MergeSort puede aplicarse,
 *    false en caso contrario.
 */
bool Fibonacci::Small(const Problema<int>* kProblema) const {
  return (kProblema->getProblema() <= 1) ? true : false;
}

/**
 * @brief Resuelve un problema pequeño utilizando MergeSort.
 * @param kProblema Problema pequeño a resolver.
 * @return Solución al problema.
 */
Solucion<int>* Fibonacci::SolveSmall(const Problema<int>* kProblema) const {
  Solucion<int>* solucion = new SolucionInteger();
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
const std::vector<Problema<int>*> Fibonacci::Divide(
    const Problema<int>* kProblema,
    const int kSize) const {
  std::vector<Problema<int>*> resultado(2);
  resultado[0] = new ProblemaInteger();
  resultado[1] = new ProblemaInteger();  
  resultado[0]->setProblema() = kProblema->getProblema() - 1;
  resultado[1]->setProblema() = kProblema->getProblema() - 2;
  return resultado;
}

Solucion<int>* Fibonacci::Combine(const std::vector<const Solucion<int>*>& kSolucion) const {
  Solucion<int>* solucion = new SolucionInteger();
  solucion->setSolucion() = kSolucion[0]->getSolucion() + kSolucion[1]->getSolucion();
  return solucion;
}