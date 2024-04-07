/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 1 de Abril de 2024
 * @file movimientoReInsercionIntraGRASP.h
 * @brief Definición de la clase MovimientoReInsercionIntraGRASP que hereda de
 * la clase GRASP, para realizar una búsqueda local de re-inserción intra-máquinas
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07/src}
 */

#pragma once

#include "../algoritmo_GRASP_TCT.h"

/**
 * @brief Clase MovimientoReInsercionIntraGRASP que realiza la búsqueda local
 * re-inserción intra-máquinas de GRASP para mejorar resultados
 */
class MovimientoReInsercionIntraGRASP : public AlgoritmoGRASP {
 private:
  virtual const std::vector<Solucion> busquedaLocal(
    const std::vector<Solucion>&, const Nodo*
  ) const override;
  const int calcularTCTParcialMaquina1(
    const Nodo*, const int, const Solucion&
  ) const; 
  const int calcularTCTParcialMaquina2(
    const Nodo*, const int, const Solucion&
  ) const;
};