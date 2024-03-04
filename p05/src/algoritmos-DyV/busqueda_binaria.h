#pragma once

#include "../framework/algoritmoDyV.h"
#include "../problema/problema-vectorial.h"
#include "../solucion/solucion-integer.h"

class BusquedaBinaria: public AlgoritmoDyV<std::vector<int>, int> {
 public:
  BusquedaBinaria(const Problema<std::vector<int>>* kProblema, const int kValor) {
    valor_ = kValor;
    ini_ = 0;
    fin_ = kProblema->getProblema().size() - 1;
    solucion_integer = new SolucionInteger;
  }
 private:
  virtual bool Small(const Problema<std::vector<int>>*) const override;
  virtual Solucion<int>* SolveSmall(const Problema<std::vector<int>>*) const override;
  virtual const std::vector<Problema<std::vector<int>>*> Divide(
      const Problema<std::vector<int>>*, const int) const override;
  virtual Solucion<int>* Combine(const std::vector<const Solucion<int>*>&) const override;
  virtual const std::string getA() const override { return "2"; }
  virtual const std::string getB() const override { return "n/2"; }
  virtual const std::string getC() const override { return "n"; }
  int valor_;
  mutable int ini_;
  mutable int fin_;
  mutable Solucion<int>* solucion_integer;
};