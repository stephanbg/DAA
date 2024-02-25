#pragma once

#include "../instancia/instancia.h"

class AlgoritmoDyV {
 public:
  const Instancia Solve(Instancia&, const int); 
  virtual ~AlgoritmoDyV() {};
 protected:
  virtual bool Small(const Instancia&) const = 0;
  virtual const Instancia SolveSmall(const Instancia&) const = 0;
  virtual const std::vector<Instancia> Divide(const Instancia&, const int) const = 0;
  virtual void Combine(Instancia&, const std::vector<Instancia>&) const = 0;
};