#pragma once

#include "../operando.h"

class OperandoIndirecto : public Operando {
 public:
  virtual const long double get_valor(const MemoriaDatos&, const long double) const override;
  virtual bool compruebaPatron(const std::string&) const override;
  virtual const int get_registro(const MemoriaDatos&, const int) const override;
};