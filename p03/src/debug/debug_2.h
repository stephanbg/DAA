#pragma once

#include "debug.h"

class Debug2 : public Debug {
 public:  
  virtual void InfoDuranteEjecucion(const Instruccion&, const MemoriaDatos&,
                                    const CintaIn&, const CintaOut&) const override;
};