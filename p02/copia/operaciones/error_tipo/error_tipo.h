#pragma once

#include "../operacion.h"

class ErrorTipo : public Operacion {
 public:
  bool ValidarInstruccion(const Instruccion&) const override { return false; }
  void EjecutarInstruccion(const Instruccion&, MemoriaDatos&, const CintaIn&, CintaOut&, int&) const override {}
};