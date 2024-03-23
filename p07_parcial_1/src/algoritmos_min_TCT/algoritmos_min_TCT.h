#pragma once

#include <vector>

#include "../grafo/grafoDirigidoCompleto.h"
#include "../maquina/maquina.h"

class AlgoritmoMinimizarTCT {
 public:
  virtual const std::vector<Maquina> ejecutar(const int, const GrafoDirigidoCompleto&) const = 0;
};