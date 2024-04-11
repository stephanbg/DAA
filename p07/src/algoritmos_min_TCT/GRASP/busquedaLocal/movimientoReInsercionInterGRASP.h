/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 1 de Abril de 2024
 * @file movimientoReInsercionInterGRASP.h
 * @brief Definición de la clase MovimientoReInsercionInterGRASP que hereda de
 * la clase GRASP, para realizar una búsqueda local de re-inserción inter-máquinas
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07/src}
 */

#pragma once

#include "../algoritmo_GRASP_TCT.h"

/**
 * @brief Clase MovimientoReInsercionInterGRASP que realiza la búsqueda local
 * re-inserción inter-máquinas de GRASP para mejorar resultados
 */
class MovimientoReInsercionInterGRASP : public AlgoritmoGRASP {
 public:
  virtual const std::vector<Solucion> busquedaLocal(
    const std::vector<Solucion>&, const Nodo*
  ) const override;
  const std::vector<Solucion> busquedaLocalPerturbandoEntorno(
    const std::vector<Solucion>&, const int, const Nodo*
  ) const;  
 private:  
  /// EVALUACIÓN DEL MOVIMIENTO
  const int calcularTCTParcialMaquina1(
    const Nodo*, const int, const Solucion&
  ) const; 
  /// EVALUACIÓN DEL MOVIMIENTO
  const int calcularTCTParcialMaquina2(
    const Nodo*, const int, const Solucion&
  ) const;
};