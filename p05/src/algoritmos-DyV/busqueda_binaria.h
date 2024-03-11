/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 6 de Marzo de 2024
 * @file busqueda_binaria.h
 * @brief Definición de la clase BusquedaBinaria, que se encarga de
 * realizar dicho algoritmo
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p05/src}
 * @see {@link https://docs.google.com/document/d/1pwPk5iI5dRHo8M-raauPP5mgCUHy9m9j_au3UDkn_Rc/edit}
 */

#pragma once

#include <iostream>

#include "../framework/algoritmoDyV.h"
#include "../problema/problema-vectorial.h"
#include "../solucion/solucion-integer.h"
#include "../funcionesNecesarias/funcionesNecesarias.h"

/**
 * @brief Clase BusquedaBinaria, hereda de AlgoritmoDyV
 * Recibiendo como plantilla un problema vectorial de enteros y
 * devuelve una solución de tipo entero
 */
class BusquedaBinaria: public AlgoritmoDyV<std::vector<int>, int> {
 public:
  /**
   * @brief Constructor que recibe el tamaño del problema y el valor a buscar
   * @param kSize Tamaño del problema
   * @param kValor Valor a buscar
   */
  BusquedaBinaria(const int kSize, const int kValor) {
    valor_ = kValor;
    ini_ = 0;
    fin_ = kSize - 1;
    solucion_integer = new SolucionInteger;
  }
  static const int numeroABuscar();
 private:
  virtual bool Small(const Problema<std::vector<int>>*) const override;
  virtual Solucion<int>* SolveSmall(const Problema<std::vector<int>>*) const override;
  virtual const std::vector<Problema<std::vector<int>>*> Divide(
      const Problema<std::vector<int>>*, const int) const override;
  virtual Solucion<int>* Combine(const std::vector<const Solucion<int>*>&) const override;
  virtual const std::string getA() const override { return "2"; }
  virtual const std::string getB() const override { return "n/2"; }
  virtual const std::string getC() const override { return "n"; }
  int valor_;
  mutable int ini_;
  mutable int fin_;
  mutable Solucion<int>* solucion_integer;
};