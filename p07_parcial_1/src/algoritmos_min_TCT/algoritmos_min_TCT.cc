#include "algoritmos_min_TCT.h"

void AlgoritmoMinimizarTCT::calcularFuncionObjetivo(const std::vector<Maquina>& kMaquinas) {
  funcion_objetivo_ = 0;
  const int kCantidadMaquinas = kMaquinas.size();
  for (int i = 0; i < kCantidadMaquinas; ++i) {
    funcion_objetivo_ += kMaquinas[i].getTCT();
  }
}

const long long int AlgoritmoMinimizarTCT::calcularTCT(
  const Nodo* kNodoRaiz,
  const Maquina& kMaquina
) const {
  const std::vector<const Nodo*>& kTareas = kMaquina.getTareas();
  const int kNumTareas = kTareas.size();
  long long int tct = kNumTareas * kNodoRaiz->getCosteHaciaVecino(kTareas[0]);
  for (int i = 1; i < kNumTareas; ++i) {
    const int kCoeficiente = kNumTareas - i;
    tct += kCoeficiente * kTareas[i - 1]->getCosteHaciaVecino(kTareas[i]);
  }
  return tct;
}