#pragma once

#include "../../algoritmosDiversidadMaxima/algoritmosDiversidadMaxima.h"

class Voraz : public AlgoritmosDiversidadMaxima {
 public:
  virtual Solucion ejecutar(const Problema&, const int) override;
 private:
  void faseConstructiva(const Problema&, const int);
  void busquedaLocal(const Matriz&);
};