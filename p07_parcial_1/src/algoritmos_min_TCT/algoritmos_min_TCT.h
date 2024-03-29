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

#include "../grafo/grafoDirigidoCompleto.h"
#include "../maquina/maquina.h"

/**
 * @brief Clase base abstracta para algoritmos que minimizan el tiempo de completado total (TCT).
 */
class AlgoritmoMinimizarTCT {
 public:
  virtual const std::vector<Maquina> ejecutar(const int, const GrafoDirigidoCompleto&) = 0;
  int getFuncionObjetivo() { return funcion_objetivo_; }
 protected:
  int funcion_objetivo_;
  /**
   * @brief Calcula la función objetivo basada en las asignaciones de tareas a las máquinas.
   * 
   * @param kMaquinas Vector que contiene las asignaciones de tareas a las máquinas.
   */
  void calcularFuncionObjetivo(const std::vector<Maquina>& kMaquinas) {
    funcion_objetivo_ = 0;
    const int kNumMaquinas  = kMaquinas.size();
    for (int i = 0; i < kNumMaquinas; ++i) {
      funcion_objetivo_ += kMaquinas[i].getTCT();
    }
  }
};