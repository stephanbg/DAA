/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 6 de Marzo de 2024
 * @file problema-vector-pilas.h
 * @brief Definición de la clase ProblemaVectorPilas, que representa
 * cualquier problema vectorial con pilas, clase hija de la clase abstracta Problema
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p05/src}
 * @see {@link https://docs.google.com/document/d/1pwPk5iI5dRHo8M-raauPP5mgCUHy9m9j_au3UDkn_Rc/edit}
 */

#pragma once

#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

#include "problema.h"
#include "../funcionesNecesarias/funcionesNecesarias.h"

/**
 * @brief La clase ProblemaVectorPilas representa un problema vectorial de pilas.
 * Hereda de la clase Problema y proporciona funcionalidades
 * específicas para manipular vectores de pilas de enteros.
 */
class ProblemaVectorPilas: public Problema<std::vector<std::stack<int>>> {
 public:
  // Constructores
  ProblemaVectorPilas() {}
  ProblemaVectorPilas(const int, const bool kRandomDatosPila0 = false);
  ProblemaVectorPilas(const int, const int, const bool kRandomDatosPila0 = false);
  // Getters y Setters
  virtual const std::vector<std::stack<int>>& getProblema() const override { return pilas_; }
  virtual std::vector<std::stack<int>>& setProblema() override { return pilas_; }
  virtual void mostrarProblema() const override;
  // Peticiones
  void meterValores(const int, const std::vector<int>&);
  static const int cantidadPilas();
 private:
  void generadorInstanciaAleatoria();
  void generadorInstanciaAleatoriaSizeFijo(const int);
  std::vector<std::stack<int>> pilas_;
};