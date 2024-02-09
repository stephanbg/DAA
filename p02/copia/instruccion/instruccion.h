#pragma once

#include <iostream>
#include <vector>
#include <regex>

#include "../funciones/funciones_necesarias.h"

class Operacion;
class Operando;

class Instruccion {
 public:
  Instruccion() {}
  Instruccion(const std::string&);

  const std::string& TipoOperador() const;
  const std::string& TipoOperando() const;
  const long double ObtenerConstante() const;
  
  const Operacion* get_tipo_operacion() const { return tipo_operacion_; }
  const Operando* get_tipo_operando() const { return tipo_operando_; }
  const std::vector<std::string>& get_instruccion() const { return instruccion_; }
  std::vector<std::string>& set_instruccion() { return instruccion_; }
  
  friend std::ostream& operator<<(std::ostream&, const Instruccion&);
 private:
  std::vector<std::string> instruccion_;
  Operacion* tipo_operacion_;
  Operando* tipo_operando_;
  void SepararInstruccionEnPalabras(const std::string&);
  bool ConstruirOperador(const std::string&);
  bool ConstruirOperando(const std::string&, const std::string&);
};