#include "multiArranqueGVNS.h"

const std::vector<Solucion> MultiArranqueGVNS::ejecutar(
  const int kNumeroMaquinas,
  const Problema& kGrafo,
  const int kIteracionesGRASP
) {
  const Nodo* kNodoRaiz = kGrafo.getGrafo()[0];
  MovimientoReInsercionInterGRASP algoritmoGRASP;
  std::vector<Solucion> mejor_solucion =
      algoritmoGRASP.ejecutar(kNumeroMaquinas, kGrafo, kIteracionesGRASP), mejor_solucion_auxiliar;
  int iteraciones = 0, mejor_funcion_objetivo = Solucion::getFuncionObjetivo(), funcion_objetivo_actual;
  do {
    mejor_solucion_auxiliar = algoritmoGRASP.ejecutar(kNumeroMaquinas, kGrafo, kIteracionesGRASP);
    GVNS(mejor_solucion_auxiliar, kNodoRaiz);
    funcion_objetivo_actual = Solucion::getFuncionObjetivo();
    if (funcion_objetivo_actual < mejor_funcion_objetivo) {
      mejor_solucion = mejor_solucion_auxiliar;
      mejor_funcion_objetivo = funcion_objetivo_actual;
    }
  } while (++iteraciones < 100);
  return mejor_solucion;
}

void MultiArranqueGVNS::GVNS(std::vector<Solucion>& solucion_a_mejorar, const Nodo* kNodoRaiz) const {
  const int kMAX = 5;
  std::vector<Solucion> mejor_solucion_GVNS = solucion_a_mejorar;
  for (int k = 1; k <= kMAX; ++k) {
    mejor_solucion_GVNS = perturbacion(mejor_solucion_GVNS, k, kNodoRaiz);
    //VND();
  }
  exit(1);
}

const std::vector<Solucion> MultiArranqueGVNS::perturbacion(
  const std::vector<Solucion>& kSolucionAPerturbar,
  const int kCantidadVecinosAMover,
  const Nodo* kNodoRaiz
) const {
  MovimientoReInsercionInterGRASP algoritmoParaPerturbarEntorno;
  return algoritmoParaPerturbarEntorno.busquedaLocalPerturbandoEntorno(
    kSolucionAPerturbar, kCantidadVecinosAMover, kNodoRaiz
  );
}

void MultiArranqueGVNS::VND() const {
  
}