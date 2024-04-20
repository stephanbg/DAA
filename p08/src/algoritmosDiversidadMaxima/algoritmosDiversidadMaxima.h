/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 19 de Abril de 2024
 * @file algoritmosDiversidadMaxima.h
 * @brief Definición de la clase abstracta AlgoritmosDiversidadMaxima
 * para resolver el problema de Maximum diversity problem.
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p08/src}
 */

#pragma once

#include "../problema/problema.h"
#include "../solucion/solucion.h"
#include "../matriz/matriz.h"

/**
 * @brief Clase abstracta que define la interfaz común para los algoritmos
 *        utilizados en la resolución del problema de Maximum Diversity Problem.
 * 
 * Esta clase proporciona una interfaz común para todos los algoritmos utilizados
 * en la resolución del problema de Maximum Diversity Problem. Los algoritmos
 * concretos deben heredar de esta clase y proporcionar una implementación
 * para el método virtual puro `ejecutar`, que ejecuta el algoritmo específico
 * para resolver el problema.
 */
class AlgoritmosDiversidadMaxima {
 public:
  virtual Solucion ejecutar(const Problema&, const int) = 0;
 protected:
  Solucion solucion_;
  const double calcularFuncionObjetivo(const Matriz&);
  const double calcularFuncionObjetivoParcial(const Solucion&, const int, const Matriz&);
  const std::vector<double> calcularCentroGravedad(const Matriz&) const;
  const std::pair<std::vector<double>, int> obtenerElementoEIndiceFicticioMasAlejadoDeCentroGravedad(
    const std::vector<double>&,
    const Matriz&
  ) const;
};