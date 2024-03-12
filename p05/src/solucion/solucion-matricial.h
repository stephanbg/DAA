/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 6 de marzo de 2024
 * @file solucion-matricial.h
 * @brief Definición de la clase SolucionMatricial, que representa
 * la solución a cualquier problema de Matrices
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p05/src}
 * @see {@link https://docs.google.com/document/d/1pwPk5iI5dRHo8M-raauPP5mgCUHy9m9j_au3UDkn_Rc/edit}
 */

#pragma once

#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "solucion.h"

/**
 * @brief La clase SolucionMatricial representa una solución de matrices.
 * Hereda de la clase Solucion.
 */
class SolucionMatricial: public Solucion<std::vector<std::vector<int>>> {
 public:
  SolucionMatricial() {}
  SolucionMatricial(const int, const int);
  // Getters y Setters
  virtual const std::vector<std::vector<int>>& getSolucion() const override { return solucion_; }
  virtual std::vector<std::vector<int>>& setSolucion() override { return solucion_; }
  virtual void mostrarSolucion() const override;
 private:
  std::vector<std::vector<int>> solucion_{};
};