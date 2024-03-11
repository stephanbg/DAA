/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 27 de Febrero de 2024
 * @file algoritmoDyV.h
 * @brief Definición de la clase AlgoritmoDyV, que representa
 * un framework para cualquier problema de DyV
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p05/src}
 * @see {@link https://docs.google.com/document/d/1pwPk5iI5dRHo8M-raauPP5mgCUHy9m9j_au3UDkn_Rc/edit}
 */

#pragma once

#include <string>
#include <vector>

#include "../problema/problema.h"
#include "../solucion/solucion.h"

/**
 * @brief Clase AlgoritmoDyV, representa un framework (clase abstracta)
 * para cualquier algoritmo de DyV
 * @tparam TipoProblema el tipo de problema que se tiene que resolver
 * @tparam TipoSolucion el tipo de la solución que surge de ejecutar el
 *    algoritmo de DyV
 */
template<typename TipoProblema, typename TipoSolucion>
class AlgoritmoDyV {
 public:
  // Métodos que servirán de esqueleto para todas las clases hijas
  Solucion<TipoSolucion>* Solve(const Problema<TipoProblema>*, const int) const;
  const std::string Recurrence() const;
  ~AlgoritmoDyV() {}
 protected:
  // Todos los métodos virtuales que se implementarán para todos los algoritmos de DyV
  virtual bool Small(const Problema<TipoProblema>*) const = 0;
  virtual Solucion<TipoSolucion>* SolveSmall(const Problema<TipoProblema>*) const = 0;
  virtual const std::vector<Problema<TipoProblema>*> Divide(const Problema<TipoProblema>*, const int) const = 0;
  virtual Solucion<TipoSolucion>* Combine(const std::vector<const Solucion<TipoSolucion>*>&) const = 0;
  virtual const std::string getA() const = 0;
  virtual const std::string getB() const = 0;
  virtual const std::string getC() const = 0;
};

#include "algoritmoDyV.cc"