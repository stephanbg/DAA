#pragma once

#include <iostream>

#include "../memoria_datos/memoria_datos.h"
#include "../cintas/cinta_in.h"
#include "../cintas/cinta_out.h"
#include "../instruccion/instruccion.h"

class Operacion {
 public:
  virtual bool ValidarInstruccion(const Instruccion&) const = 0;
  virtual void EjecutarInstruccion(MemoriaDatos&, const CintaIn&, CintaOut&, int&) const = 0;
  virtual ~Operacion() {} /// Destructor virtual
};