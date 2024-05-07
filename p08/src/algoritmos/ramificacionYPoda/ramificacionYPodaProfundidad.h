#pragma once

#include "../../algoritmosDiversidadMaxima/algoritmosDiversidadMaxima.h"
#include "../GRASP/GRASP.h"
#include "../voraz/voraz.h"

class RamificacionYPodaProfundidad : public AlgoritmosDiversidadMaxima {
 public:
  virtual Solucion ejecutar(const Problema&, const int, const int) override;
 private:
  void ramificacionYPoda(
    const Matriz&, const std::pair<Matriz, std::vector<int>>&,
    const int, Solucion&, double&, const int, const std::vector<std::tuple<double, double, int>>&
  );
  bool nodoAPodar(const Solucion&, const int, const double, const double, const std::vector<std::tuple<double, double, int>>&);
  std::vector<std::tuple<double, double, int>> calcularDistanciasMinMax(const Matriz&, const int) const;  
};