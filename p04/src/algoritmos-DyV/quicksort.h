/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 27 de Febrero de 2024
 * @file quicksort.h
 * @brief Definición de la clase QuickSort, que se encarga de
 * realizar dicho algoritmo
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p04/src}
 * @see {@link https://docs.google.com/document/d/1CcrG-85_oTdAkTo-zgXkudKT8C8z7T7m2hUHVLGUReQ/edit#heading=h.5bq8rsdy1ujx}
 */

#pragma once

#include "../framework/algoritmoDyV.h"
#include "../problema/problema-vectorial.h"
#include "../solucion/solucion-vectorial.h"

/**
 * @brief Clase QuickSort, hereda de AlgoritmoDyV
 * Recibiendo como plantilla un problema vectorial de enteros y
 * devuelve una solución vectorial de enteros
 */
class QuickSort: public AlgoritmoDyV<std::vector<int>, std::vector<int>> {
 private:
  virtual bool Small(const Problema<std::vector<int>>*) const override;
  virtual Solucion<std::vector<int>>* SolveSmall(const Problema<std::vector<int>>*) const override;
  virtual const std::vector<Problema<std::vector<int>>*> Divide(
      const Problema<std::vector<int>>*, const int) const override;
  virtual Solucion<std::vector<int>>* Combine(
      const std::vector<const Solucion<std::vector<int>>*>&) const override;
  virtual const std::string getA() const override { return "2"; }
  virtual const std::string getB() const override { return "n/2"; }
  virtual const std::string getC() const override { return "n"; }  
};