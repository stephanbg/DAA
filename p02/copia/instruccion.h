#pragma once

#include <iostream>
#include <vector>

class Instruccion {
 public:
  const std::vector<std::string>& get_instruccion() const { return instruccion_; }
  std::vector<std::string>& set_instruccion() { return instruccion_; }
  friend std::ostream& operator<<(std::ostream&, const Instruccion&);
 private:
  std::vector<std::string> instruccion_;
};