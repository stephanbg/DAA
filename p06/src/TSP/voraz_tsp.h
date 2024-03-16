#pragma once

#include "tsp.h"
#include "../funciones/funciones.h"

class VorazTSP: public TSP {
 public:
  virtual void ejecutar(const GrafoNoDirigidoCompleto&) override;
  virtual void mostrarCaminoMinimo() const override;
  virtual void mostrarTiempoEjecución() const override;
};