#pragma once

#include <algorithm> // Para std::next_permutation
#include <numeric>   // Para std::iota

#include "tsp.h"

class FuerzaBrutaTSP: public TSP {
 public:
  virtual void ejecutar(const GrafoNoDirigidoCompleto&) override;
  virtual void mostrarCaminoMinimo() const override;
  virtual void mostrarTiempoEjecución() const override;  
};