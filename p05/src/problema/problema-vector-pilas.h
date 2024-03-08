#pragma once

#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

#include "problema.h"

/**
 * @brief La clase ProblemaVectorial representa un problema vectorial.
 * Hereda de la clase Problema y proporciona funcionalidades
 * específicas para manipular vectores de enteros.
 */
class ProblemaVectorPilas: public Problema<std::vector<std::stack<int>>> {
 public:
  ProblemaVectorPilas() {}
  ProblemaVectorPilas(const int kCantidadPilas, const bool randomDatosPila0 = false) {
    pilas_.resize(kCantidadPilas);
    if (randomDatosPila0) generadorInstanciaAleatoria();
  }
  // Getters y Setters
  virtual const std::vector<std::stack<int>>& getProblema() const override { return pilas_; }
  virtual std::vector<std::stack<int>>& setProblema() override { return pilas_; }
  virtual void mostrarProblema() const override;
  void meterValores(const int, const std::vector<int>&);
 private:
  void generadorInstanciaAleatoria();
  std::vector<std::stack<int>> pilas_;
};