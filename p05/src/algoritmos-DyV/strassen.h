#pragma once

#include "../framework/algoritmoDyV.h"
#include "../problema/problema-vector-matricial.h"
#include "../solucion/solucion-matricial.h"

class Strassen: public AlgoritmoDyV<std::vector<std::vector<std::vector<int>>>, std::vector<std::vector<int>>> {
 private:
  virtual bool Small(const Problema<std::vector<std::vector<std::vector<int>>>>*) const override;
  virtual Solucion<std::vector<std::vector<int>>>* SolveSmall(const Problema<std::vector<std::vector<std::vector<int>>>>*) const override;
  virtual const std::vector<Problema<std::vector<std::vector<std::vector<int>>>>*> Divide(
      const Problema<std::vector<std::vector<std::vector<int>>>>*, const int) const override;
  virtual Solucion<std::vector<std::vector<int>>>* Combine(
      const std::vector<const Solucion<std::vector<std::vector<int>>>*>&) const override;
  virtual const std::string getA() const override { return "7"; }
  virtual const std::string getB() const override { return "n/2"; }
  virtual const std::string getC() const override { return "n^2"; }  
};