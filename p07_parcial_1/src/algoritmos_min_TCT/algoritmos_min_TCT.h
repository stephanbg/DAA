/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 20 de Marzo de 2024
 * @file algoritmos_min_TCT.h
 * @brief Clase abstracta AlgoritmoMinimizarTCT para minimizar los TCT
 * y por ende las funciones objetivos para el problema Parallel Machine Scheduling Problem
 * with Dependent Setup Times, con diferentes algoritmos
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07_parcial_1/src}
 */

#pragma once

#include <vector>

#include "../problema/problema.h"
#include "../solucion/solucion.h"

/**
 * @brief Clase base abstracta para algoritmos que minimizan el tiempo de completado total (TCT).
 */
class AlgoritmoMinimizarTCT {
 public:
  virtual const std::vector<Solucion> ejecutar(const int, const Problema&) = 0;
};