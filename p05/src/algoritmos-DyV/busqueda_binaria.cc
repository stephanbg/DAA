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

#include "busqueda_binaria.h"

/**
 * @brief Verifica si el problema dado es lo suficientemente pequeño
 * como para aplicar MergeSort.
 * @param kProblema Problema a evaluar.
 * @return true Si el problema es pequeño y MergeSort puede aplicarse,
 *    false en caso contrario.
 */
bool BusquedaBinaria::Small(const Problema<std::vector<int>>* kProblema) const {
  return (ini_ >= fin_) ? true : false;
}

/**
 * @brief Resuelve un problema pequeño utilizando MergeSort.
 * @param kProblema Problema pequeño a resolver.
 * @return Solución al problema.
 */
Solucion<int>* BusquedaBinaria::SolveSmall(const Problema<std::vector<int>>* kProblema) const {
  if (kProblema->getProblema()[fin_] == valor_) solucion_integer->setSolucion() = fin_;
  else solucion_integer->setSolucion() = -1;
  return solucion_integer;
}

/**
 * @brief Divide el problema en dos subproblemas separados por
 * la mitad para aplicar MergeSort recursivamente.
 * @param kProblema Problema a dividir.
 * @param kSize Tamaño del problema.
 * @return Vector con los dos subproblemas resultantes
 *     de la división por la mitad.
 */
const std::vector<Problema<std::vector<int>>*> BusquedaBinaria::Divide(
    const Problema<std::vector<int>>* kProblema,
    const int kSize) const {
  const size_t kMitad = (ini_ + fin_) / 2;
  std::vector<Problema<std::vector<int>>*> resultado(1);
  resultado[0] = new ProblemaVectorial();
  resultado[0]->setProblema() = kProblema->getProblema();
  if (kProblema->getProblema()[kMitad] < valor_) ini_ = kMitad + 1;
  else if (kProblema->getProblema()[kMitad] > valor_) fin_ = kMitad - 1;
  else {
    fin_ = kMitad;
    ini_ = fin_ + 1;
  }
  return resultado;
}

/**
 * @brief Combina las soluciones de los subproblemas resultantes de la división.
 * @param kSoluciones Vector de soluciones de los subproblemas.
 * @return Solución combinada.
 */
Solucion<int>* BusquedaBinaria::Combine(const std::vector<const Solucion<int>*>& kSoluciones) const {
  return solucion_integer;
}

const int BusquedaBinaria::numeroABuscar() {
  std::cout << "\nQue número desea buscar: ";
  std::string numero;
  while (std::cin >> numero && !esNumero(numero)) {
    std::cout << "Tiene que buscar un valor numérico entero." << std::endl;
    std::cout << "Que número desea buscar: ";
  }
  return stoi(numero);
}