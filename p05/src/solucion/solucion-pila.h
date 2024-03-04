#pragma once

#include <stack>

#include "solucion.h"

class SolucionPila: public Solucion<std::stack<int>> {
 public:
  virtual const std::stack<int>& getSolucion() const override { return pila_; }
  virtual std::stack<int>& setSolucion() override { return pila_; }
  virtual void mostrarSolucion() const override;
 private:
  std::stack<int> pila_;
};