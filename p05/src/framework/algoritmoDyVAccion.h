/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 6 de Marzo de 2024
 * @file algoritmoDyVAccion.h
 * @brief Definición de la clase AlgoritmoDyVAccion, que representa
 * un framework para los problemas de DyV que necesitan una acción entre llamadas recursivas
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p05/src}
 * @see {@link https://docs.google.com/document/d/1pwPk5iI5dRHo8M-raauPP5mgCUHy9m9j_au3UDkn_Rc/edit}
 */

#pragma once

#include <string>
#include <vector>

#include "../problema/problema.h"
#include "../solucion/solucion.h"
#include "../solucion/solucion-pila.h"

/**
 * @brief Clase AlgoritmoDyVAccion, representa un framework (clase abstracta)
 * para cualquier algoritmo de DyV que necesite una acción entre las llamadas recursivas
 * @tparam TipoProblema el tipo de problema que se tiene que resolver
 * @tparam TipoSolucion el tipo de la solución que surge de ejecutar el
 *    algoritmo de DyV
 */
template<typename TipoProblema, typename TipoSolucion>
class AlgoritmoDyVAccion {
 public:
  Solucion<TipoSolucion>* Solve(const Problema<TipoProblema>*, const int) const;
  const std::string Recurrence() const;
  ~AlgoritmoDyVAccion() {}
 protected:
  // Todos los métodos virtuales que se implementarán para todos los algoritmos de DyV
  virtual bool Small(const int) const = 0;
  virtual void Action(TipoSolucion&, TipoSolucion&) const = 0;
  virtual void SolveSmall(TipoSolucion&, TipoSolucion&) const = 0;
  virtual const std::string getA() const = 0;
  virtual const std::string getB() const = 0;
  virtual const std::string getC() const = 0;
 private:
  // Algoritmo de Solve Oculto
  void SolveOculto(TipoSolucion&, TipoSolucion&, TipoSolucion&, const int) const;
};

#include "algoritmoDyVAccion.cc"