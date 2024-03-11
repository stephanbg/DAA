/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 6 de Marzo de 2024
 * @file hanoi.h
 * @brief Definición de la clase Hanoi, que se encarga de
 * realizar dicho algoritmo
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p05/src}
 * @see {@link https://docs.google.com/document/d/1pwPk5iI5dRHo8M-raauPP5mgCUHy9m9j_au3UDkn_Rc/edit}
 */

#pragma once

#include "../framework/algoritmoDyVAccion.h"
#include "../problema/problema-vector-pilas.h"
#include "../solucion/solucion-pila.h"

/**
 * @brief Clase Hanoi, hereda de AlgoritmoDyVAccion
 * Recibiendo como plantilla un problema vectorial de pilas y
 * devuelve una solución de tipo pila de enteros
 */
class Hanoi: public AlgoritmoDyVAccion<std::vector<std::stack<int>>, std::stack<int>> {
 private:
  virtual bool Small(const int) const override;
  virtual void Action(std::stack<int>&, std::stack<int>&) const override;
  virtual void SolveSmall(std::stack<int>&, std::stack<int>&) const override;
  virtual const std::string getA() const override { return "2"; }
  virtual const std::string getB() const override { return "n-1"; }
  virtual const std::string getC() const override { return "1"; }
};