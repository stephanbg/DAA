/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 1 de Abril de 2024
 * @file movimientoSwapIntraGRASP.h
 * @brief Definición de la clase MovimientoSwapIntraGRASP que hereda de
 * la clase GRASP, para realizar una búsqueda local de intercambio intra-máquinas
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07/src}
 */

#pragma once

#include "../algoritmo_GRASP_TCT.h"

/**
 * @brief Clase MovimientoSwapIntraGRASP que realiza la búsqueda local
 * intercambio intra-máquinas de GRASP para mejorar resultados
 */
class MovimientoSwapIntraGRASP : public AlgoritmoGRASP {
 private:
  virtual const std::vector<Solucion> busquedaLocal(
    const std::vector<Solucion>&, const Nodo*
  ) const override;
  const std::pair<int, int> calcularTCTParcial(
    const Nodo*, const int, const int, Solucion&, Solucion&
  ) const;
};