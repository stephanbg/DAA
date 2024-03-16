#pragma once

#include <chrono>

#include "../grafo/grafoNoDirigidoCompleto.h"

using Clock = std::chrono::steady_clock;

class TSP {
 public:
  virtual void ejecutar(const GrafoNoDirigidoCompleto&) = 0;
  // Mostrar
  virtual void mostrarCaminoMinimo() const = 0;
  virtual void mostrarTiempoEjecución() const = 0;
  void mostrarCoste();
  // Getter
  const std::vector<const Nodo*>& getCaminoMinimo() const { return caminoMinimo_; }
  const long double getCoste() const { return coste_; }
  const long double getTiempoEjecución() const { return tiempoEjecucion_; }
 protected:
  std::vector<const Nodo*> caminoMinimo_;
  long double coste_;
  long double tiempoEjecucion_;
  const long double calcularCoste();
};