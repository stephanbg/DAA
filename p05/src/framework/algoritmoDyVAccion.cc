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
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p04/src}
 * @see {@link https://docs.google.com/document/d/1CcrG-85_oTdAkTo-zgXkudKT8C8z7T7m2hUHVLGUReQ/edit#heading=h.5bq8rsdy1ujx}
 */

#ifndef ALGORITMO_DYV_ACCION_CC
#define ALGORITMO_DYV_ACCION_CC

#include "algoritmoDyVAccion.h"
#include "../problema/problema-vector-pilas.h"

template<typename TipoProblema, typename TipoSolucion>
Solucion<TipoSolucion>* AlgoritmoDyVAccion<TipoProblema, TipoSolucion>::Solve(
    const Problema<TipoProblema>* problema, const int kSize) const {
  TipoSolucion origen, destino, auxiliar;
  origen = problema->getProblema()[0];
  destino = problema->getProblema()[1];
  auxiliar = problema->getProblema()[2];
  this->SolveOculto(origen, destino, auxiliar, kSize);
  Solucion<TipoSolucion>* solucion = new SolucionPila();
  solucion->setSolucion() = destino;
  return solucion;
}

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
void AlgoritmoDyVAccion<TipoProblema, TipoSolucion>::SolveOculto(
    TipoSolucion& origen,
    TipoSolucion& destino,
    TipoSolucion& auxiliar,
    const int kSize) const {
  if (Small(kSize)) SolveSmall(origen, destino);
  else {
    SolveOculto(origen, auxiliar, destino, kSize - 1);
    SolveSmall(origen, destino);
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