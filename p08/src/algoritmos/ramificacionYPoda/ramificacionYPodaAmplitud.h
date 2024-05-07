/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 2 de Abril de 2024
 * @file ramificacionYPodaAmplitud.h
 * @brief Definición de la clase RamificacionYPodaAmplitud que hereda de AlgoritmosDiversidadMaxima
 * para resolver el problema de Maximum diversity problem.
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p08/src}
 */

#pragma once

#include <queue>

#include "../../algoritmosDiversidadMaxima/algoritmosDiversidadMaxima.h"
#include "../GRASP/GRASP.h"
#include "../voraz/voraz.h"

/**
 * @brief Clase que implementa un algoritmo RamificacionYPodaAmplitud para resolver un problema de diversidad máxima.
 * 
 * Esta clase hereda de la clase abstracta AlgoritmosDiversidadMaxima e implementa el método ejecutar
 * para ejecutar el algoritmo RamificacionYPodaAmplitud sobre un problema dado.
 */
class RamificacionYPodaAmplitud : public AlgoritmosDiversidadMaxima {
 public:
  virtual Solucion ejecutar(const Problema&, const int, const int) override;
 private:
  void ramificacionYPoda(
    const Matriz&, const std::pair<Matriz, std::vector<int>>&, const int, Solucion&, double&
  );
  std::vector<std::tuple<double, double, int>> calcularDistanciasMinMax(const Matriz&, const int) const;
  bool nodoAPodar(
    const Solucion&, const int, const double, const double,
    const std::vector<std::tuple<double, double, int>>&
  );  
  std::pair<Matriz, std::vector<int>> obtenerElementosFueraDeSolucion(const Problema&, const Solucion&) const;
};