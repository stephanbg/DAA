#pragma once

#include "../algoritmos_min_TCT.h"
#include "../../funciones/funciones.h"

class AlgoritmoGRASP : public AlgoritmoMinimizarTCT {
 public:
  virtual const std::vector<Maquina> ejecutar(const int, const GrafoDirigidoCompleto&) const override;
 private:
  void faseConstructiva(const int, std::vector<Maquina>&, const GrafoDirigidoCompleto&) const;
};