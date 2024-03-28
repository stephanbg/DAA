#pragma once

#include <vector>
#include <algorithm>
#include <random>

#include "../algoritmos_min_TCT.h"
#include "../../funciones/funciones.h"

class AlgoritmoGRASP : public AlgoritmoMinimizarTCT {
 public:
  virtual const std::vector<Maquina> ejecutar(const int, const GrafoDirigidoCompleto&) override;
 private:
  const std::vector<const Nodo*> faseConstructiva(
    const GrafoDirigidoCompleto&
  ) const;
  const double calcularHeurística(const std::vector<Nodo*>&) const;
  const std::vector<const Nodo*> calcularNodosQueSuperanHeuristica(
    const std::vector<Nodo*>&, const double
  ) const;
};