#pragma once

#include <iostream>
#include <vector>
#include <regex>

#include "../funciones/funciones_necesarias.h"

class Operacion;

class Instruccion {
 public:
  Instruccion() {}
  Instruccion(const std::string&);
  const std::string& TipoOperador() const;
  const std::string TipoInstruccion() const;
  const Operacion* get_tipo_operacion() const { return tipo_operacion_; }
  const std::vector<std::string>& get_instruccion() const { return instruccion_; }
  std::vector<std::string>& set_instruccion() { return instruccion_; }
  friend std::ostream& operator<<(std::ostream&, const Instruccion&);
 private:
  std::vector<std::string> instruccion_;
  Operacion* tipo_operacion_;
  void SepararInstruccionEnPalabras(const std::string&);
};