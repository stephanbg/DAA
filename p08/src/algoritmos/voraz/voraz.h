/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 19 de Abril de 2024
 * @file voraz.h
 * @brief Definición de la clase Voraz que hereda de AlgoritmosDiversidadMaxima
 * para resolver el problema de Maximum diversity problem.
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p08/src}
 */

#pragma once

#include "../../algoritmosDiversidadMaxima/algoritmosDiversidadMaxima.h"

/**
 * @brief Clase que implementa un algoritmo voraz para resolver un problema de diversidad máxima.
 * 
 * Esta clase hereda de la clase abstracta AlgoritmosDiversidadMaxima e implementa el método ejecutar
 * para ejecutar el algoritmo voraz sobre un problema dado.
 */
class Voraz : public AlgoritmosDiversidadMaxima {
 public:
  virtual Solucion ejecutar(const Problema&, const int) override;
 private:
  void faseConstructiva(const Problema&, std::pair<Matriz, std::vector<int>>&, const int);
  void busquedaLocal(const Problema& ,const std::pair<Matriz, std::vector<int>>&);
};