#pragma once

#include "../instancia/instancia.h"

class AlgoritmoDyV {
 public:
  const Instancia& Solve(const Instancia&, const int); 
 protected:
  virtual bool Small(const Instancia&) const = 0;
  virtual const Instancia& SolveSmall(const Instancia&) const = 0;
  virtual const Instancia& Divide(const Instancia&, const int) const = 0;
  virtual const Instancia& Combine(const Instancia&, const Instancia&) const = 0;
};