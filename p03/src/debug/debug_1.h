#pragma once

#include "debug.h"

class Debug1 : public Debug {
 public:  
  virtual void InfoDuranteEjecucion(const Instruccion&, const MemoriaDatos&,
                                    const CintaIn&, const CintaOut&) const override {}
};