#pragma once

#include "../operando.h"

class ErrorOperando : public Operando {
 public:
  virtual bool compruebaPatron(const std::string&) const override { return false; }
  virtual const long double get_valor(const Instruccion&, const MemoriaDatos&, const long double) const { 
    const std::string kErrorLecturaEscritura = "Este operador no es de escritura, ni de lectura.";
    throw (kErrorLecturaEscritura);
    return EXIT_FAILURE; /// Por si no es escritura ni lectura
  }
};