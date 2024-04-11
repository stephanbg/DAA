#pragma once

#include "../algoritmos_min_TCT.h"
#include "../GRASP/algoritmo_GRASP_TCT.h"
#include "../GRASP/busquedaLocal/movimientoReInsercionInterGRASP.h"
#include "../GRASP/busquedaLocal/movimientoReInsercionIntraGRASP.h"
#include "../GRASP/busquedaLocal/movimientoSwapInterGRASP.h"
#include "../GRASP/busquedaLocal/movimientoSwapIntraGRASP.h"

class MultiArranqueGVNS: public AlgoritmoMinimizarTCT {
  public:
    virtual const std::vector<Solucion> ejecutar(const int, const Problema&, const int kIteraciones = 1) override;
  private:
   void GVNS(std::vector<Solucion>&, const Nodo*) const;
   const std::vector<Solucion> perturbacion(const std::vector<Solucion>&, const int, const Nodo*) const;
   void VND() const;
};