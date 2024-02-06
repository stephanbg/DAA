#pragma once

#include "../operacion.h"

class JUMP : public Operacion {
 public:
  void EjecutarInstruccion(MemoriaDatos&, const CintaIn&, CintaOut&, int&) const override;
  bool ValidarInstruccion(const Instruccion&) const override;
};