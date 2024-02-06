#pragma once

#include "memoria_datos.h"
#include "cinta_in.h"
#include "cinta_out.h"
#include "instruccion.h"

class Operacion {
 public:
  virtual void EjecutarInstruccion(MemoriaDatos&, const Instruccion&, const CintaIn&, CintaOut&, int&) const = 0;
  virtual ~Operacion() {} /// Destructor virtual
};