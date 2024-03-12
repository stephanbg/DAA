/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 6 de marzo de 2024
 * @file solucion-integer.h
 * @brief Definición e implementación de la clase SolucionInteger, que representa
 * la solución a cualquier problema de enteros
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p05/src}
 * @see {@link https://docs.google.com/document/d/1pwPk5iI5dRHo8M-raauPP5mgCUHy9m9j_au3UDkn_Rc/edit}
 */

#pragma once

#include "problema.h"

/**
 * @brief clase SolucionInteger que hereda de Solucion
 */
class ProblemaInteger: public Problema<int> {
 public:
  ProblemaInteger() {}
  ProblemaInteger(const bool kRandom) {
    problema_ = rand() % 10 + 1;
  }
  // Getters y setters
  virtual const int& getProblema() const override { return problema_; }
  virtual int& setProblema() override { return problema_; }
  const int size() { return problema_; }
  // Muestra la solución
  virtual void mostrarProblema() const override { std::cout << problema_; }
 private:
  int problema_;
};