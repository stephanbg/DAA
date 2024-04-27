#pragma once

#include <random>
#include <numeric>

#include "../../algoritmosDiversidadMaxima/algoritmosDiversidadMaxima.h"

class GRASP : public AlgoritmosDiversidadMaxima {
 public:
  virtual Solucion ejecutar(const Problema&, const int) override;
 private:
  void faseConstructiva(const Problema&, std::pair<Matriz, std::vector<int>>&, const int, const std::vector<double>&);
  std::vector<int> calcularLRC(const std::pair<Matriz, std::vector<int>>&, const Matriz&, const std::vector<double>&) const;
  std::vector<double> calcularMedidaCalidad(const std::pair<Matriz, std::vector<int>>&, const Matriz&) const;
  const int seleccionarAleatoriamenteElementoDeLRC(const std::vector<int>&) const;
};