#pragma once

#include <vector>

#include "../../../solucion/solucion.h"

class BusquedaLocal {
 public:
  virtual const std::vector<Solucion> busquedaLocal(const Nodo*) = 0;
 protected:
  std::vector<Solucion> solucion_inicial_;
};