/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 6 de Marzo de 2024
 * @file busqueda_binaria.cc
 * @brief Implementación de la clase BusquedaBinaria, que se encarga de
 * realizar dicho algoritmo
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p05/src}
 * @see {@link https://docs.google.com/document/d/1pwPk5iI5dRHo8M-raauPP5mgCUHy9m9j_au3UDkn_Rc/edit}
 */

#include "busqueda_binaria.h"

/**
 * @brief Verifica si el problema dado es lo suficientemente pequeño
 * como para aplicar BusquedaBinaria.
 * @param kProblema Problema a evaluar.
 * @return true Si el problema es pequeño y BusquedaBinaria puede aplicarse,
 *    false en caso contrario.
 */
bool BusquedaBinaria::Small(const Problema<std::vector<int>>* kProblema) const {
  return (ini_ >= fin_) ? true : false;
}

/**
 * @brief Resuelve un problema pequeño utilizando BusquedaBinaria.
 * @param kProblema Problema pequeño a resolver.
 * @return Solución al problema.
 */
Solucion<int>* BusquedaBinaria::SolveSmall(const Problema<std::vector<int>>* kProblema) const {
  if (kProblema->getProblema()[fin_] == valor_) solucion_integer->setSolucion() = fin_;
  else solucion_integer->setSolucion() = -1;
  return solucion_integer;
}

/**
 * @brief Mueve los indices de inicio y fin, a las
 * posiciones necesarias para la siguiente recursividad.
 * Dependiendo de donde esté el valor a buscar
 * @param kProblema Problema.
 * @param kSize Tamaño del problema.
 * @return El mismo problema.
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
 * @brief No realiza nada, solamente tiene que estar porque se hereda del framework
 * @param kSoluciones Vector de soluciones de los subproblemas.
 * @return la misma solución.
 */
Solucion<int>* BusquedaBinaria::Combine(const std::vector<const Solucion<int>*>& kSoluciones) const {
  return solucion_integer;
}

/**
 * @brief Pregunta al usuario que número se desea buscar en el problema
 * @return Devuelve el número
 */
const int BusquedaBinaria::numeroABuscar() {
  std::cout << "\nQue número desea buscar: ";
  std::string numero;
  while (std::cin >> numero && !esNumero(numero)) {
    std::cout << "Tiene que buscar un valor numérico entero." << std::endl;
    std::cout << "Que número desea buscar: ";
  }
  return stoi(numero);
}