#pragma once

#include "../algoritmo_GRASP_TCT.h"

class MovimientoSwapIntraGRASP : public AlgoritmoGRASP {
 private:
  virtual const std::vector<Solucion> busquedaLocal(const std::vector<Solucion>&, const Nodo*) const override;
  const int calcularTCTParcial(const Nodo*, const int, const int, const Solucion&, Solucion&) const;
};