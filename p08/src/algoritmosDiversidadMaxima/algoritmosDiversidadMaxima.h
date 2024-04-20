#pragma once

#include "../problema/problema.h"
#include "../solucion/solucion.h"
#include "../matriz/matriz.h"

class AlgoritmosDiversidadMaxima {
 public:
  virtual Solucion ejecutar(const Problema&, const int) = 0;
 protected:
  Solucion solucion_;
  const double calcularFuncionObjetivo(const Matriz&);
  const double calcularFuncionObjetivoParcial(const Solucion&, const int, const Matriz&);
  const std::vector<double> calcularCentroGravedad(const Matriz&) const;
  const std::pair<std::vector<double>, int> obtenerElementoEIndiceRealMasAlejadoDeCentroGravedad(
    const std::vector<double>&,
    const Matriz&
  ) const;
};