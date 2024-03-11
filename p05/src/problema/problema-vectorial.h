/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 27 de Febrero de 2024
 * @file problema-vectorial.h
 * @brief Definición de la clase ProblemaVectorial, que representa
 * cualquier problema vectorial de DyV, clase hija de la clase abstracta Problema
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p05/src}
 * @see {@link https://docs.google.com/document/d/1pwPk5iI5dRHo8M-raauPP5mgCUHy9m9j_au3UDkn_Rc/edit}
 */

#pragma once

#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "problema.h"

/**
 * @brief La clase ProblemaVectorial representa un problema vectorial.
 * Hereda de la clase Problema y proporciona funcionalidades
 * específicas para manipular vectores de enteros.
 */
class ProblemaVectorial: public Problema<std::vector<int>> {
 public:
  // Constructores
  ProblemaVectorial(const bool kGenerarAleatorio = false); 
  ProblemaVectorial(const int, const bool kGenerarAleatorio = false);
  ProblemaVectorial(const std::vector<int>&);
  // Getters y Setters
  virtual const std::vector<int>& getProblema() const override { return problema_; }
  virtual std::vector<int>& setProblema() override { return problema_; }
  virtual void mostrarProblema() const override;
  const int size() const { return getProblema().size(); }
  // Operadores []
  int& operator[](const size_t kIndice) { return problema_[kIndice]; }
  const int operator[](const size_t kIndice) const { return problema_[kIndice]; }
 private:
  void generadorInstanciaAleatoria();
  void generadorInstanciaAleatoriaSizeFijo();
  std::vector<int> problema_;
};