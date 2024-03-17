/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Marzo de 2024
 * @file voraz_tsp.h
 * @brief Definición de la clase VorazTSP que hereda de la clase TSP
 * para resolver dicho problema
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p06/src}
 * @see {@link https://docs.google.com/document/d/1a691HPtHQL4qBtI2qaTMTp23wxZvU8-CCIbGOyNJRQo/edit}
 */

#pragma once

#include <algorithm>

#include "tsp.h"
#include "../funciones/funciones.h"

/**
 * @brief Clase que implementa el algoritmo del Viajante de Comercio Voraz.
 * 
 * Esta clase hereda de la clase base TSP e implementa el algoritmo del Viajante de Comercio Voraz.
 * El algoritmo construye el camino mínimo de forma incremental, seleccionando en cada paso el vecino más cercano.
 */
class VorazTSP: public TSP {
 public:
  virtual void ejecutar(const GrafoNoDirigidoCompleto&) override;
  virtual void mostrarCaminoMinimo() const override;
  virtual void mostrarTiempoEjecución() const override;
};