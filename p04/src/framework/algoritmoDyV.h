#pragma once

#include "../instancia/instancia.h"

class AlgoritmoDyV {
 public:
  const Instancia Solve(const Instancia&, const int) const;
  const std::string Recurrence() const;
  virtual ~AlgoritmoDyV() {};
 protected:
  virtual bool Small(const Instancia&) const = 0;
  virtual const Instancia SolveSmall(const Instancia&) const = 0;
  virtual const std::vector<Instancia> Divide(const Instancia&, const int) const = 0;
  virtual const Instancia Combine(const Instancia&, const std::vector<Instancia>&) const = 0;
  virtual const std::string getA() const = 0;
  virtual const std::string getB() const = 0;
  virtual const std::string getC() const = 0;
};