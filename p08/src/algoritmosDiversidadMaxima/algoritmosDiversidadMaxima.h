#pragma once

#include "../problema/problema.h"
#include "../solucion/solucion.h"
#include "../matriz/matriz.h"

class AlgoritmosDiversidadMaxima {
 public:
  virtual Solucion ejecutar(const Problema&, const int) = 0;
 protected:
  Solucion solucion_;
  const double calcularFuncionObjetivo(const Solucion&, const Matriz&);
  const std::vector<double> calcularCentroGravedad(const Matriz&) const;
  const std::vector<double> obtenerElementoMasAlejadoDeCentroGravedad(
    const std::vector<double>&,
    const Matriz&
  ) const;
};