#pragma once

#include <list>

#include "../../algoritmosDiversidadMaxima/algoritmosDiversidadMaxima.h"
#include "../GRASP/GRASP.h"
#include "../../funciones/funciones.h"

class BusquedaTabu : public AlgoritmosDiversidadMaxima {
 public:
  virtual Solucion ejecutar(const Problema&, const int, const int) override;
 private:
  void busquedaTabu(const Solucion&, std::pair<Matriz, std::vector<int>>&, const Matriz&, const int, const int);
  std::pair<Matriz, std::vector<int>> obtenerElementosFueraDeSolucion(const Problema&, const Solucion&) const;
};