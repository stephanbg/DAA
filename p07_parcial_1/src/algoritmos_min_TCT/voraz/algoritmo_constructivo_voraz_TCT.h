#pragma once

#include <algorithm>

#include "../algoritmos_min_TCT.h"
#include "../../funciones/funciones.h"

class AlgoritmoConstructivoVoraz : public AlgoritmoMinimizarTCT {
 public:
  virtual const std::vector<Maquina> ejecutar(const int, const GrafoDirigidoCompleto&) const override;
 private:
  void seleccionarTareasInciales(
    std::vector<Maquina>&, const GrafoDirigidoCompleto&, std::vector<bool>&
  ) const;
  void minimizarIncrementoTCT(
    const int, const std::vector<Maquina>&, std::vector<Maquina>&,
    std::vector<bool>&, const GrafoDirigidoCompleto&
  ) const;
  const int calcularTCT(const std::vector<Maquina>&, const int, const int) const;
  const Nodo* encontrarMejorTarea(
    const GrafoDirigidoCompleto&,
    const std::vector<bool>&, const int
  ) const;
};