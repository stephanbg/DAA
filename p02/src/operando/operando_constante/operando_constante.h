#pragma once

#include "../operando.h"

class OperandoConstante : public Operando {
 public:
  virtual bool compruebaPatron(const std::string&) const override;
  virtual const long double get_valor(const Instruccion&, const MemoriaDatos&, const long double) const override;
};