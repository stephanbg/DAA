#pragma once

#include "../operando.h"

class ErrorOperando : public Operando {
 public:
  virtual const long double get_valor(const MemoriaDatos&, const long double) const override {
    throw ("No existe este operando.");
    return EXIT_FAILURE;
  }
  virtual const int get_registro(const MemoriaDatos&, const int) const override {
    throw ("No existe este operando.");
    return EXIT_FAILURE;
  }  
  virtual bool compruebaPatron(const std::string&) const override { return false; }
};