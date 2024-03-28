#pragma once

#include <vector>

#include "../grafo/grafoDirigidoCompleto.h"
#include "../maquina/maquina.h"

class AlgoritmoMinimizarTCT {
 public:
  virtual const std::vector<Maquina> ejecutar(const int, const GrafoDirigidoCompleto&) = 0;
  const long long int getFuncionObjetivo() { return funcion_objetivo_; }
 protected:
  long long int funcion_objetivo_;
  void calcularFuncionObjetivo(const std::vector<Maquina>&);
  const long long int calcularTCT(const Nodo*, const Maquina&) const;
};