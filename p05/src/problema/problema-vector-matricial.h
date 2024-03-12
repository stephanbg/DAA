/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 6 de Marzo de 2024
 * @file problema-vector-matricial.h
 * @brief Definición de la clase ProblemaVectorMatricial, que representa
 * cualquier problema vectorial de matrices, clase hija de la clase abstracta Problema
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p05/src}
 * @see {@link https://docs.google.com/document/d/1pwPk5iI5dRHo8M-raauPP5mgCUHy9m9j_au3UDkn_Rc/edit}
 */

#pragma once

#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "problema.h"
#include "../funcionesNecesarias/funcionesNecesarias.h"

/**
 * @brief La clase ProblemaVectorMatricial representa un problema vectorial de matrices.
 * Hereda de la clase Problema y proporciona funcionalidades
 * específicas para manipular vectores de matrices de enteros.
 */
class ProblemaVectorMatricial: public Problema<std::vector<std::vector<std::vector<int>>>> {
 public:
  // Constructores
  ProblemaVectorMatricial() {}
  ProblemaVectorMatricial(const int);
  ProblemaVectorMatricial(const int, const std::vector<std::pair<int, int>>,
      const bool kGeneradorInstanciaAleatoria = false);     
  // Getters y Setters
  virtual const std::vector<std::vector<std::vector<int>>>& getProblema() const override { return problema_; }
  virtual std::vector<std::vector<std::vector<int>>>& setProblema() override { return problema_; }
  virtual void mostrarProblema() const override;
  static const int cantidadMatrices();
  static const int cantidadFilas();
  static const int cantidadColumnas();
  // Meter datos
  void meterValores(const std::vector<std::vector<std::vector<int>>>&);
 private:
  void generadorInstanciaAleatoriaSizeFijo(); 
  std::vector<std::vector<std::vector<int>>> problema_{};
};