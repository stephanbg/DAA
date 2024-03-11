/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 6 de Marzo de 2024
 * @file algoritmoDyVAccion.cc
 * @brief Implementación de la clase AlgoritmoDyVAccion, que representa
 * un framework para los problemas de DyV que necesitan una acción entre llamadas recursivas
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p05/src}
 * @see {@link https://docs.google.com/document/d/1pwPk5iI5dRHo8M-raauPP5mgCUHy9m9j_au3UDkn_Rc/edit}
 */

#ifndef ALGORITMO_DYV_ACCION_CC
#define ALGORITMO_DYV_ACCION_CC

#include "algoritmoDyVAccion.h"
#include "../problema/problema-vector-pilas.h"

/**
 * @brief Resuelve el problema utilizando el algoritmo de Divide y Vencerás con acción.
 * @tparam TipoProblema Tipo de dato del problema.
 * @tparam TipoSolucion Tipo de dato de la solución.
 * @param kProblema Puntero al problema a resolver.
 * @param kSize Tamaño del problema.
 * @return Puntero a la solución obtenida.
 */
template<typename TipoProblema, typename TipoSolucion>
Solucion<TipoSolucion>* AlgoritmoDyVAccion<TipoProblema, TipoSolucion>::Solve(
    const Problema<TipoProblema>* kProblema, const int kSize) const {
  TipoSolucion origen, destino, auxiliar;
  origen = kProblema->getProblema()[0];
  destino = kProblema->getProblema()[1];
  auxiliar = kProblema->getProblema()[2];
  this->SolveOculto(origen, destino, auxiliar, kSize);
  Solucion<TipoSolucion>* solucion = new SolucionPila();
  solucion->setSolucion() = destino;
  return solucion;
}

/**
 * @brief Método privado que resuelve recursivamente el problema.
 * @tparam TipoProblema Tipo de dato del problema.
 * @tparam TipoSolucion Tipo de dato de la solución.
 * @param origen Solucion origen.
 * @param destino Solucion destino.
 * @param auxiliar Solucion auxiliar.
 * @param kSize Tamaño del problema.
 */
template<typename TipoProblema, typename TipoSolucion>
void AlgoritmoDyVAccion<TipoProblema, TipoSolucion>::SolveOculto(
    TipoSolucion& origen,
    TipoSolucion& destino,
    TipoSolucion& auxiliar,
    const int kSize) const {
  if (Small(kSize)) SolveSmall(origen, destino);
  else {
    SolveOculto(origen, auxiliar, destino, kSize - 1);
    Action(origen, destino);
    SolveOculto(auxiliar, destino, origen, kSize - 1);
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
const std::string AlgoritmoDyVAccion<TipoProblema, TipoSolucion>::Recurrence() const {
  return ("T(n) <= " + getA() + "T(" + getB() + ") + " + getC());
}

#endif