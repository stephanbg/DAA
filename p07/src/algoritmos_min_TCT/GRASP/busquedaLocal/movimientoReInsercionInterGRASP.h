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
 * la clase GRASP, para realizar una búsqueda local de re-inserción inter-máquina
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07/src}
 */

#pragma once

#include "../algoritmo_GRASP_TCT.h"

/**
 * @brief Clase MovimientoReInsercionInterGRASP que realiza la búsqueda local
 * re-inserción inter-máquina de GRASP para mejorar resultados
 */
class MovimientoReInsercionInterGRASP : public AlgoritmoGRASP {
 private:
  virtual const std::vector<Solucion> busquedaLocal(
    const std::vector<Solucion>&, const Nodo*
  ) const override;
  const int calcularTCTParcial(const Nodo*, const int, const int, const Solucion&, Solucion&) const;
};