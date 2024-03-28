#pragma once

#include <algorithm>
#include <numeric>   // Para std::iota

#include "../algoritmos_min_TCT.h"
#include "../../funciones/funciones.h"

struct TareaMaquinaPosicion {
  const Nodo* tarea;
  int indice_maquina;
  int posicion;
};

class AlgoritmoConstructivoVoraz : public AlgoritmoMinimizarTCT {
 public:
  virtual const std::vector<Maquina> ejecutar(const int, const GrafoDirigidoCompleto&) override;
 private:
  void seleccionarTareasInciales(
    std::vector<Maquina>&, const GrafoDirigidoCompleto&, std::vector<int>&
  ) const;
  const TareaMaquinaPosicion obtenerTareaMaquinaPosicion(
    const int, std::vector<Maquina>&,
    const std::vector<int>&, const GrafoDirigidoCompleto&
  ) const;
};