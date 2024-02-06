#pragma once

#include <iostream>
#include <vector>
#include <regex>

class Instruccion {
 public:
  const std::string& TipoOperador() const;
  const std::string TipoInstruccion() const;
  const std::vector<std::string>& get_instruccion() const { return instruccion_; }
  std::vector<std::string>& set_instruccion() { return instruccion_; }
  friend std::ostream& operator<<(std::ostream&, const Instruccion&);
 private:
  std::vector<std::string> instruccion_;
};