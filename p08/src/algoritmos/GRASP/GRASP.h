/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 19 de Abril de 2024
 * @file GRASP.h
 * @brief Definición de la clase GRASP que hereda de AlgoritmosDiversidadMaxima
 * para resolver el problema de Maximum diversity problem.
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p08/src}
 */

#pragma once

#include <random>
#include <numeric>

#include "../../algoritmosDiversidadMaxima/algoritmosDiversidadMaxima.h"

/**
 * @brief Clase que implementa un algoritmo GRASP para resolver un problema de diversidad máxima.
 * 
 * Esta clase hereda de la clase abstracta AlgoritmosDiversidadMaxima e implementa el método ejecutar
 * para ejecutar el algoritmo GRASP sobre un problema dado.
 */
class GRASP : public AlgoritmosDiversidadMaxima {
 public:
  virtual Solucion ejecutar(const Problema&, const int, const int) override;
 private:
  void faseConstructiva(const Problema&, std::pair<Matriz, std::vector<int>>&, const int, const std::vector<double>&);
  std::vector<int> calcularLRC(const std::pair<Matriz, std::vector<int>>&, const Matriz&, const std::vector<double>&) const;
  std::vector<double> calcularMedidaCalidad(const std::pair<Matriz, std::vector<int>>&, const Matriz&) const;
  const int seleccionarAleatoriamenteElementoDeLRC(const std::vector<int>&) const;
};