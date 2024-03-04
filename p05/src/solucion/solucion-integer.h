#pragma once

#include "solucion.h"

class SolucionInteger: public Solucion<int> {
 public:
  virtual const int& getSolucion() const override { return solucion_; }
  virtual int& setSolucion() override { return solucion_; }
  virtual void mostrarSolucion() const override { std::cout << solucion_; }
 private:
  int solucion_;
};