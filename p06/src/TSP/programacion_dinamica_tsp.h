#pragma once

#include <cmath>
#include <algorithm>

#include "tsp.h"

class ProgramacionDinamicaTSP: public TSP {
 public:
  virtual void ejecutar(const GrafoNoDirigidoCompleto&) override;
  virtual void mostrarCaminoMinimo() const override;
  virtual void mostrarTiempoEjecución() const override;
 protected:
  void reconstruirCaminoMinimo(
    const std::vector<std::vector<long double>>&,
    const GrafoNoDirigidoCompleto&
  );
};