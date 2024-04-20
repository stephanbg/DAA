#pragma once

#include "../../algoritmosDiversidadMaxima/algoritmosDiversidadMaxima.h"

class Voraz : public AlgoritmosDiversidadMaxima {
 public:
  virtual Solucion ejecutar(const Problema&, const int) override;
 private:
  void faseConstructiva(const Problema&, std::pair<Matriz, std::vector<int>>&, const int);
  void busquedaLocal(const Problema& ,const std::pair<Matriz, std::vector<int>>&);
};