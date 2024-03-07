#pragma once

#include "../framework/algoritmoDyVAccion.h"
#include "../problema/problema-vector-pilas.h"
#include "../solucion/solucion-pila.h"

/**
 * @brief Clase QuickSort, hereda de AlgoritmoDyV
 * Recibiendo como plantilla un problema vectorial de enteros y
 * devuelve una solución vectorial de enteros
 */
class Hanoi: public AlgoritmoDyVAccion<std::vector<std::stack<int>>, std::stack<int>, std::stack<int>> {
 private:
  virtual bool Small(const int) const override;
  virtual void SolveSmall(std::stack<int>&, std::stack<int>&) const override;
  virtual const std::string getA() const override { return "2"; }
  virtual const std::string getB() const override { return "n-1"; }
  virtual const std::string getC() const override { return "1"; }
};