#pragma once

#include "../../algoritmosDiversidadMaxima/algoritmosDiversidadMaxima.h"
#include "../GRASP/GRASP.h"
#include "../voraz/voraz.h"

class RamificacionYPodaProfundidad : public AlgoritmosDiversidadMaxima {
 public:
  virtual Solucion ejecutar(const Problema&, const int, const int) override;
 private:
  void ramificacionYPoda(
    const Matriz&, const std::pair<Matriz, std::vector<int>>&, const int, Solucion&, double&, const int
  );
};