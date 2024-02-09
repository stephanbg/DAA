#pragma once

#include <regex>

#include "../memoria_datos/memoria_datos.h"

class Operando {
 public:
  virtual const long double get_valor(const MemoriaDatos&, const long double) const = 0;
  virtual const int get_registro(const MemoriaDatos&, const int) const = 0;
  virtual bool compruebaPatron(const std::string&) const = 0;
  virtual ~Operando() {} /// Destructor virtual
};