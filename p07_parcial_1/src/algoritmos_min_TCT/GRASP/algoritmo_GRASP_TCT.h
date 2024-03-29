/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 20 de Marzo de 2024
 * @file algoritmo_GRASP_TCT.h
 * @brief Definición de la clase AlgoritmoGRASP que hereda de
 * la clase abstracta AlgoritmoMinimizarTCT para minimizar el TCT mediante un algoritmo GRASP
 * solo haciendo la fase constructiva
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07_parcial_1/src}
 */

#pragma once

#include <vector>
#include <algorithm>
#include <random>

#include "../algoritmos_min_TCT.h"
#include "../../funciones/funciones.h"

/**
 * @brief Implementación del algoritmo GRASP (Greedy Randomized Adaptive Search Procedure)
 * para minimizar el tiempo de completación total (TCT).
 * 
 * Este algoritmo utiliza una fase constructiva para generar soluciones iniciales
 * y una fase de búsqueda local para mejorarlas (La búsqueda local no se ha implementado todavía).
 */
class AlgoritmoGRASP : public AlgoritmoMinimizarTCT {
 public:
  virtual const std::vector<Maquina> ejecutar(const int, const GrafoDirigidoCompleto&) override;
 private:
  const std::vector<const Nodo*> faseConstructiva(
    const GrafoDirigidoCompleto&
  ) const;
  const double calcularHeurística(const std::vector<Nodo*>&) const;
  const std::vector<const Nodo*> calcularNodosQueSuperanHeuristica(
    const std::vector<Nodo*>&, const double
  ) const;
};