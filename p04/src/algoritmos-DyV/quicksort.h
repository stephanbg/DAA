#pragma once

#include "../framework/algoritmoDyV.h"

class QuickSort: public AlgoritmoDyV {
  virtual bool Small(const Instancia&) const override;
  virtual const Instancia SolveSmall(const Instancia&) const override;
  virtual const std::vector<Instancia> Divide(Instancia&, const int) const override;
  virtual void Combine(Instancia&, const std::vector<Instancia>&) const override {}
};