#pragma once

#include "debug.h"

class Debug0 : public Debug {
 public:
  virtual void MostrarNumeroInstruccionesEjecutadas(const int) const override {}
  virtual void InfoDuranteEjecucion(const Instruccion&, const MemoriaDatos&,
                                    const CintaIn&, const CintaOut&) const override {}
};