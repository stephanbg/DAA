#pragma once

#include "../../algoritmosDiversidadMaxima/algoritmosDiversidadMaxima.h"

class Voraz : public AlgoritmosDiversidadMaxima {
 public:
  virtual Solucion ejecutar(const Problema&) override;
};