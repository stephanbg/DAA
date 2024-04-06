#pragma once

#include "../algoritmo_GRASP_TCT.h"

class MovimientoReInsercionIntraGRASP : public AlgoritmoGRASP {
 private:
  virtual const std::vector<Solucion> busquedaLocal(const std::vector<Solucion>&, const Nodo*) const override;
  const std::pair<int, int> calcularTCTParcial(
    const Nodo*, const int, const int, Solucion&, Solucion&
  ) const;
};