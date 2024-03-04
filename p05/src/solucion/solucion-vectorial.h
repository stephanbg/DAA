/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 27 de Febrero de 2024
 * @file solucion-vectorial.h
 * @brief Definición de la clase SolucionVectorial, que representa
 * la solución vectorial a cualquier problema de DyV, clase hija de
 * la clase abstracta Solucion
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p04/src}
 * @see {@link https://docs.google.com/document/d/1CcrG-85_oTdAkTo-zgXkudKT8C8z7T7m2hUHVLGUReQ/edit#heading=h.5bq8rsdy1ujx}
 */

#pragma once

#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "solucion.h"

/**
 * @brief La clase SolucionVectorial representa una solución vectorial.
 * Hereda de la clase Solucion y proporciona funcionalidades
 * específicas para manipular vectores de enteros.
 */
class SolucionVectorial: public Solucion<std::vector<int>> {
 public:
  SolucionVectorial() {}
  SolucionVectorial(const std::vector<int>& solucion): solucion_(solucion) {}
  virtual const std::vector<int>& getSolucion() const override { return solucion_; }
  virtual std::vector<int>& setSolucion() override { return solucion_; }
  const int size() const { return getSolucion().size(); }
  int& operator[](const size_t kIndice) { return solucion_[kIndice]; }
  const int operator[](const size_t kIndice) const { return solucion_[kIndice]; }
  virtual void mostrarSolucion() const override;
 private:
  std::vector<int> solucion_;
};