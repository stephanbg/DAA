#pragma once

#include "../algoritmo_GRASP_TCT.h"

class MovimientoSwapInterGRASP : public AlgoritmoGRASP {
 private:
  virtual const std::vector<Solucion> busquedaLocal(const std::vector<Solucion>&, const Nodo*) const override;
  virtual const int calcularTCTParcial(const Nodo*, const int, const Solucion&, Solucion&) const override;
};