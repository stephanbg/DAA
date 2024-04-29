/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 19 de Abril de 2024
 * @file busquedaTabu.h
 * @brief Definición de la clase BusquedaTabu que hereda de AlgoritmosDiversidadMaxima
 * para resolver el problema de Maximum diversity problem.
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p08/src}
 */

#pragma once

#include <list>

#include "../../algoritmosDiversidadMaxima/algoritmosDiversidadMaxima.h"
#include "../GRASP/GRASP.h"
#include "../../funciones/funciones.h"

/**
 * @brief Clase que implementa un algoritmo BusquedaTabu para resolver un problema de diversidad máxima.
 * 
 * Esta clase hereda de la clase abstracta AlgoritmosDiversidadMaxima e implementa el método ejecutar
 * para ejecutar el algoritmo BusquedaTabu sobre un problema dado.
 */
class BusquedaTabu : public AlgoritmosDiversidadMaxima {
 public:
  virtual Solucion ejecutar(const Problema&, const int, const int) override;
 private:
  void busquedaTabu(const Solucion&, std::pair<Matriz, std::vector<int>>&, const Matriz&, const int, const int);
  std::pair<Matriz, std::vector<int>> obtenerElementosFueraDeSolucion(const Problema&, const Solucion&) const;
};