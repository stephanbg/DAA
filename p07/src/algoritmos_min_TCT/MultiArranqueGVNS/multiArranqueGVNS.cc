#include "multiArranqueGVNS.h"

const std::vector<Solucion> MultiArranqueGVNS::ejecutar(
  const int kNumeroMaquinas,
  const Problema& kGrafo,
  const int kIteracionesGRASP
) {
  const Nodo* kNodoRaiz = kGrafo.getGrafo()[0];
  MovimientoReInsercionInterGRASP algoritmoGRASP;
  std::vector<Solucion> mejor_solucion =
      algoritmoGRASP.ejecutar(kNumeroMaquinas, kGrafo, 1), mejor_solucion_auxiliar;
  GVNS(mejor_solucion, kNodoRaiz);
  int iteraciones = 0, mejor_funcion_objetivo = Solucion::getFuncionObjetivo(), funcion_objetivo_actual;
  while (++iteraciones < 3) {
    mejor_solucion_auxiliar = algoritmoGRASP.ejecutar(kNumeroMaquinas, kGrafo, 1);
    GVNS(mejor_solucion_auxiliar, kNodoRaiz);
    funcion_objetivo_actual = Solucion::getFuncionObjetivo();
    if (funcion_objetivo_actual < mejor_funcion_objetivo) {
      mejor_solucion = mejor_solucion_auxiliar;
      mejor_funcion_objetivo = funcion_objetivo_actual;
    }
  }
  return mejor_solucion;
}

void MultiArranqueGVNS::GVNS(std::vector<Solucion>& solucion_a_mejorar, const Nodo* kNodoRaiz) const {
  const int kMAX = 6;
  int funcion_objetivo_inicial = Solucion::getFuncionObjetivo();
  std::vector<Solucion>& mejor_solucion_GVNS = solucion_a_mejorar;
  int contador = 0;
  for (int k = 1; k <= kMAX; ++k) {
    perturbacion(mejor_solucion_GVNS, k, kNodoRaiz);
    VND(mejor_solucion_GVNS, kNodoRaiz);
    if (Solucion::getFuncionObjetivo() < funcion_objetivo_inicial) {
      k = 1;
      funcion_objetivo_inicial = Solucion::getFuncionObjetivo();
    }
  }
  Solucion::setFuncionObjetivo() = funcion_objetivo_inicial;
}

void MultiArranqueGVNS::perturbacion(
  std::vector<Solucion>& solucion_a_perturbar,
  const int kCantidadVecinosAMover,
  const Nodo* kNodoRaiz
) const {
  MovimientoReInsercionInterGRASP algoritmoParaPerturbarEntorno;
  solucion_a_perturbar = algoritmoParaPerturbarEntorno.busquedaLocalPerturbandoEntorno(
    solucion_a_perturbar, kCantidadVecinosAMover, kNodoRaiz
  );
}

void MultiArranqueGVNS::VND(std::vector<Solucion>& solucion, const Nodo* kNodoRaiz) const {
  int funcion_objetivo = Solucion::getFuncionObjetivo();
  MovimientoReInsercionInterGRASP algoritmoReInsercionInter;
  MovimientoSwapIntraGRASP algoritmoSwapIntra;
  MovimientoReInsercionIntraGRASP algoritmoReInsercionIntra;
  MovimientoSwapInterGRASP algoritmoSwapInter;
  std::vector<Solucion> solucion_aux_1, solucion_aux_2;
  do {
    do {
      do {
        solucion_aux_1 = algoritmoReInsercionInter.busquedaLocal(
          solucion, kNodoRaiz
        );        
        funcion_objetivo = Solucion::getFuncionObjetivo();     
        solucion_aux_2 = algoritmoSwapIntra.busquedaLocal(
          solucion_aux_1, kNodoRaiz
        );
        if (Solucion::getFuncionObjetivo() < funcion_objetivo) solucion = solucion_aux_2;
      } while (Solucion::getFuncionObjetivo() < funcion_objetivo);
      solucion = solucion_aux_1;
      solucion_aux_2 = algoritmoReInsercionIntra.busquedaLocal(
        solucion, kNodoRaiz
      );   
      if (Solucion::getFuncionObjetivo() < funcion_objetivo) solucion = solucion_aux_2;
    } while (Solucion::getFuncionObjetivo() < funcion_objetivo);
      solucion_aux_2 = algoritmoSwapInter.busquedaLocal(
        solucion, kNodoRaiz
      );
    if (Solucion::getFuncionObjetivo() < funcion_objetivo) solucion = solucion_aux_2;
  } while (Solucion::getFuncionObjetivo() < funcion_objetivo);
  Solucion::setFuncionObjetivo() = funcion_objetivo;
}