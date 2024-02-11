#pragma once

#include <regex>

#include "../memoria_datos/memoria_datos.h"
#include "../instruccion/instruccion.h"

class Operando {
 public:
  /*virtual const int get_registro(const MemoriaDatos&, const int) const {
    throw std::logic_error("Operando::get_registro no implementado");
  }*/
  void set_lecturaOEscritura(const std::string&);
  virtual bool compruebaPatron(const std::string&) const = 0;
  virtual const long double get_valor(const Instruccion&, const MemoriaDatos&, const long double) const = 0;
  virtual ~Operando() {} /// Destructor virtual
 protected:
  std::string lecturaOEscritura_{""}; 
};