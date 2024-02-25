#pragma once

#include "../framework/algoritmoDyV.h"
#include <algorithm> // Para std::copy
#include <iterator>  // Para std::back_inserter

class MergeSort: public AlgoritmoDyV {
  virtual bool Small(const Instancia&) const override;
  virtual const Instancia SolveSmall(const Instancia&) const override;
  virtual const std::vector<Instancia> Divide(const Instancia&, const int) const override;
  virtual void Combine(Instancia&, const std::vector<Instancia>&) const override;
};