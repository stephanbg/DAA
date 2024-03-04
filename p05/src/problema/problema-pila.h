#pragma once

#include <vector>
#include <array>
#include <stack>
#include <iostream>

#include "problema.h"

/**
 * @brief La clase ProblemaVectorial representa un problema vectorial.
 * Hereda de la clase Problema y proporciona funcionalidades
 * específicas para manipular vectores de enteros.
 */
class ProblemaPila: public Problema<std::stack<int>> {
 public:
  ProblemaPila(const int kNumeroDiscos) { 
    int contador = 0;
    while (contador != kNumeroDiscos) {
      pila_.push(++contador);
    }
  }
  // Getters y Setters
  virtual const std::stack<int>& getProblema() const override { return pila_; }
  virtual std::stack<int>& setProblema() override { return pila_; }
  virtual void mostrarProblema() const override;
 private:
  std::stack<int> pila_;
};