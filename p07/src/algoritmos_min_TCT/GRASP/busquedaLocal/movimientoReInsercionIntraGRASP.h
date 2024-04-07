#pragma once

#include "../algoritmo_GRASP_TCT.h"

class MovimientoReInsercionIntraGRASP : public AlgoritmoGRASP {
 private:
  virtual const std::vector<Solucion> busquedaLocal(const std::vector<Solucion>&, const Nodo*) const override;
  const int calcularTCTParcialMaquina1(
    const Nodo*, const int, const Solucion&
  ) const; 
  const int calcularTCTParcialMaquina2(
    const Nodo*, const int, const Solucion&
  ) const;
};