/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 2 de Abril de 2024
 * @file ramificacionYPodaProfundidad.h
 * @brief Definición de la clase RamificacionYPodaProfundidad que hereda de AlgoritmosDiversidadMaxima
 * para resolver el problema de Maximum diversity problem.
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p08/src}
 */

#pragma once

#include "../../algoritmosDiversidadMaxima/algoritmosDiversidadMaxima.h"
#include "../GRASP/GRASP.h"
#include "../voraz/voraz.h"

/**
 * @brief Clase que implementa un algoritmo RamificacionYPodaProfundidad para resolver un problema de diversidad máxima.
 * 
 * Esta clase hereda de la clase abstracta AlgoritmosDiversidadMaxima e implementa el método ejecutar
 * para ejecutar el algoritmo RamificacionYPodaProfundidad sobre un problema dado.
 */
class RamificacionYPodaProfundidad : public AlgoritmosDiversidadMaxima {
 public:
  virtual Solucion ejecutar(const Problema&, const int, const int) override;
 private:
  void ramificacionYPoda(
    const Matriz&, const std::pair<Matriz, std::vector<int>>&,
    const int, Solucion&, double&, const int, const std::vector<std::tuple<double, double, int>>&
  );
  bool nodoAPodar(const Solucion&, const int, const double, const double, const std::vector<std::tuple<double, double, int>>&);
  std::vector<std::tuple<double, double, int>> calcularDistanciasMinMax(const Matriz&, const int) const;  
};