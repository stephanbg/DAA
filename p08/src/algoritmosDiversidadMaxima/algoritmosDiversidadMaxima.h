#pragma once

#include "../problema/problema.h"
#include "../solucion/solucion.h"
#include "../matriz/matriz.h"

class AlgoritmosDiversidadMaxima {
 public:
  virtual Solucion ejecutar(const Problema&) = 0;
  const double getFuncionObjetivo() const { return funcion_objetivo_; }
 protected:
  const std::vector<double> centroGravedad(const Matriz&) const;
  const std::vector<double> obtenerElementoMasAlejadoDeCentroGravedad(
    const std::vector<double>&,
    const Matriz&
  ) const;
  const double maximizarFuncionObjetivo(const Solucion&, const Matriz&, const int) const;
  double funcion_objetivo_ = 0;
};