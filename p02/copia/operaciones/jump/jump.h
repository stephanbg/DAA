#pragma once

#include "../operacion.h"

class JUMP : public Operacion {
 public:
  bool ValidarInstruccion(const Instruccion&) const override;
  void EjecutarInstruccion(const Instruccion&, MemoriaDatos&, const CintaIn&, CintaOut&, int&) const override;
};