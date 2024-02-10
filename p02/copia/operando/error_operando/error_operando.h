#pragma once

#include "../operando.h"

class ErrorOperando : public Operando {
 public:
  virtual bool compruebaPatron(const std::string&) const override { return false; }
  virtual const long double get_valor(const Instruccion&, const MemoriaDatos&, const long double) const { return EXIT_FAILURE; }
};