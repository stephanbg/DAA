/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 27 de Febrero de 2024
 * @file algoritmoDyV.cc
 * @brief Implementación de la clase AlgoritmoDyV, que representa
 * un framework para cualquier problema de DyV
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p05/src}
 * @see {@link https://docs.google.com/document/d/1pwPk5iI5dRHo8M-raauPP5mgCUHy9m9j_au3UDkn_Rc/edit}
 */

#ifndef ALGORITMO_DYV_CC
#define ALGORITMO_DYV_CC

#include "algoritmoDyV.h"

/**
 * @brief Resuelve el problema utilizando el enfoque de Dividir y Vencerás.
 * Sirve como esqueleto para todas las clases hijas
 * @tparam TipoProblema Tipo de datos del problema.
 * @tparam TipoSolucion Tipo de datos de la solución.
 * @param kProblema Problema a resolver.
 * @param kSize Tamaño del problema.
 * @return Puntero a la solución del problema.
 */
template<typename TipoProblema, typename TipoSolucion>
Solucion<TipoSolucion>* AlgoritmoDyV<TipoProblema, TipoSolucion>::Solve(
  const Problema<TipoProblema>* kProblema, const int kSize) const {
  if (Small(kProblema)) return SolveSmall(kProblema);
  else {
    const std::vector<Problema<TipoProblema>*> kProblemaDividido = Divide(kProblema, kSize);
    const int kSizeProblemaDividido = kProblemaDividido.size();
    std::vector<const Solucion<TipoSolucion>*>  soluciones;
    for (int n = 0; n < kSizeProblemaDividido; ++n) {
      soluciones.push_back(Solve(kProblemaDividido[n], kProblemaDividido[n]->getProblema().size()));
    }
    Solucion<TipoSolucion>* solucion = Combine(soluciones);
    return solucion;
  }
}

/**
 * @brief Devuelve la recurrencia del algoritmo.
 * Sirve como esqueleto para todas las clases hijas
 * @tparam TipoProblema Tipo de datos del problema.
 * @tparam TipoSolucion Tipo de datos de la solución.
 * @return Recurrencia del algoritmo.
 */
template<typename TipoProblema, typename TipoSolucion>
const std::string AlgoritmoDyV<TipoProblema, TipoSolucion>::Recurrence() const {
  return ("T(n) <= " + getA() + "T(" + getB() + ") + " + getC());
}

#endif