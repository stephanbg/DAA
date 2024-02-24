#pragma once

#include "../framework/algoritmoDyV.h"

class MergeSort: public AlgoritmoDyV {
  virtual bool Small(const Instancia&) const override;
  virtual const Instancia SolveSmall(const Instancia&) const override;
  virtual const std::vector<Instancia> Divide(const Instancia&, const int) const override;
  virtual const Instancia Combine(const Instancia&, const Instancia&) const override;
};