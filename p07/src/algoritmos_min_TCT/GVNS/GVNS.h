/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 10 de Abril de 2024
 * @file GVNS.h
 * @brief Definición de la clase GVNS que hereda de
 * la clase AlgoritmoMinimizarTCT, para realizar dicho algoritmo,
 * junto a sus dos fases de perturbación y VND para minimizar el TCT
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07/src}
 */

#pragma once

#include "../algoritmos_min_TCT.h"
#include "../GRASP/algoritmo_GRASP_TCT.h"
#include "../GRASP/busquedaLocal/movimientoReInsercionInterGRASP.h"
#include "../GRASP/busquedaLocal/movimientoReInsercionIntraGRASP.h"
#include "../GRASP/busquedaLocal/movimientoSwapInterGRASP.h"
#include "../GRASP/busquedaLocal/movimientoSwapIntraGRASP.h"

/**
 * @brief Clase que implementa el algoritmo GVNS para minimizar TCT.
 * 
 * Esta clase proporciona una implementación del algoritmo Generalized Variable Neighborhood Search
 * (GVNS) para resolver el problema de minimización de TCT (Tiempo de Ciclo Total).
 */
class GVNS: public AlgoritmoMinimizarTCT {
 public:
  virtual const std::vector<Solucion> ejecutar(const int, const Problema&, const int) override;
 private:
  void AlgoritmoGVNS(std::vector<Solucion>&, const Nodo*) const;
  void perturbacion(std::vector<Solucion>&, const int, const Nodo*) const;
  void VND(std::vector<Solucion>&, const Nodo*) const;
};