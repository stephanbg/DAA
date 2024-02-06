#pragma once

#include "../operacion.h"

class SUB : public Operacion {
 public:
  void EjecutarInstruccion(MemoriaDatos&, const CintaIn&, CintaOut&, int&) const override;
  bool ValidarInstruccion(const Instruccion&) const override;
};