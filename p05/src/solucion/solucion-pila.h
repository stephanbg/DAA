/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 6 de marzo de 2024
 * @file solucion-pila.h
 * @brief Definición de la clase SolucionPila, que representa
 * la solución a cualquier problema de Pilas
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p05/src}
 * @see {@link https://docs.google.com/document/d/1pwPk5iI5dRHo8M-raauPP5mgCUHy9m9j_au3UDkn_Rc/edit}
 */

#pragma once

#include <stack>

#include "solucion.h"

/**
 * @brief La clase SolucionPila representa la solución
 * a cualquier problema pilas. Hereda de la clase base Solucion
 * @tparam TipoSolucion Tipo de la solución generada por el algoritmo.
 */
class SolucionPila: public Solucion<std::stack<int>> {
 public:
  virtual const std::stack<int>& getSolucion() const override { return pila_; }
  virtual std::stack<int>& setSolucion() override { return pila_; }
  virtual void mostrarSolucion() const override;
 private:
  std::stack<int> pila_;
};