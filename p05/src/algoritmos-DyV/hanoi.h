#pragma once

#include "../framework/algoritmoDyV.h"
#include "../problema/problema-pila.h"
#include "../solucion/solucion-pila.h"

/**
 * @brief Clase QuickSort, hereda de AlgoritmoDyV
 * Recibiendo como plantilla un problema vectorial de enteros y
 * devuelve una solución vectorial de enteros
 */
class Hanoi: public AlgoritmoDyV<std::stack<int>, std::stack<int>> {
 public:
  /*Hanoi(const int kNumeroDiscos) {
    int contador = 0;
    while (contador != kNumeroDiscos) {
      origen_->setProblema().push(++contador);
    }    
  }*/
 private:
  virtual bool Small(const Problema<std::stack<int>>*) const override;
  virtual Solucion<std::stack<int>>* SolveSmall(const Problema<std::stack<int>>*) const override;
  virtual const std::vector<Problema<std::stack<int>>*> Divide(
      const Problema<std::stack<int>>*, const int) const override;
  virtual Solucion<std::stack<int>>* Combine(
      const std::vector<const Solucion<std::stack<int>>*>&) const override;
  virtual const std::string getA() const override { return "2"; }
  virtual const std::string getB() const override { return "n/2"; }
  virtual const std::string getC() const override { return "n"; }
  //Problema<std::stack<int>>* origen_;
  //std::stack<int> auxiliar_;
  //Solucion<std::stack<int>>* destino_;

};