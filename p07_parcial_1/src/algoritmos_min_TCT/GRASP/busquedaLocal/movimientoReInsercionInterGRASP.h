#pragma once

#include "./busquedaLocal.h"

class MovimientoReInsercionInterGRASP : public BusquedaLocal {
 public:
  MovimientoReInsercionInterGRASP(const std::vector<Solucion>& kSolucionInicial) {
    solucion_inicial_ = kSolucionInicial;
  }
  virtual const std::vector<Solucion> busquedaLocal(const Nodo*) override;
};