#pragma once

#include <iostream>

#include "operacion.h"

class OperacionConstante : public Operacion {
 public:
  void EjecutarInstruccion(MemoriaDatos&, const Instruccion&, const CintaIn&, CintaOut&, int&) const override;
 private:
  /// Cada Operacion
};