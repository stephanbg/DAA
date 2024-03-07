#pragma once

#include <vector>
#include <stack>
#include <iostream>

#include "problema.h"

/**
 * @brief La clase ProblemaVectorial representa un problema vectorial.
 * Hereda de la clase Problema y proporciona funcionalidades
 * específicas para manipular vectores de enteros.
 */
class ProblemaVectorPilas: public Problema<std::vector<std::stack<int>>> {
 public:
  ProblemaVectorPilas() {}
  ProblemaVectorPilas(const int kCantidadPilas) {
    pilas_.resize(kCantidadPilas);
  }
  // Getters y Setters
  virtual const std::vector<std::stack<int>>& getProblema() const override { return pilas_; }
  virtual std::vector<std::stack<int>>& setProblema() override { return pilas_; }
  virtual void mostrarProblema() const override;
  void meterValores(const int, const std::vector<int>&);
 private:
  std::vector<std::stack<int>> pilas_;
};