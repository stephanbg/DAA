#include "movimientoReInsercionInterGRASP.h"

const std::vector<Solucion> MovimientoReInsercionInterGRASP::busquedaLocal(
  const std::vector<Solucion>& kSolucionActual,
  const Nodo* kNodoRaiz
) const {
  std::vector<Solucion> solucion_vecina, solucion_mejor;
  Solucion solucion_vecina_anterior;
  const int kNumMaquinas = kSolucionActual.size();
  int funcion_objetivo_inicial = Solucion::getFuncionObjetivo(),
  funcion_objetivo = funcion_objetivo_inicial, funcion_objetivo_vecino = 0;
  for (int i = 0; i < kNumMaquinas; ++i) {
    const int kTctMaquinaI = kSolucionActual[i].getTCT();
    const int kNumTareas = kSolucionActual[i].getTareas().size();
    for (int j = 0; j < kNumTareas; ++j) {
      solucion_vecina = kSolucionActual;
      for (int k = j + 1; k < kNumTareas; ++k) {
        solucion_vecina_anterior = solucion_vecina[i];      
        solucion_vecina[i].moverTarea(k - 1, k);
        const int kTctVecinoI = calcularTCTParcial(
          kNodoRaiz, k - 1, k, solucion_vecina_anterior, solucion_vecina[i]
        );
        funcion_objetivo_vecino = funcion_objetivo_inicial - kTctMaquinaI + kTctVecinoI;
        if (funcion_objetivo_vecino < funcion_objetivo) {
          solucion_mejor = solucion_vecina;
          solucion_mejor[i].setTCT() = kTctVecinoI;
          funcion_objetivo = funcion_objetivo_vecino;
        }
      }
    }
  }
  Solucion::setFuncionObjetivo() = funcion_objetivo;
  return solucion_mejor;
}

const int MovimientoReInsercionInterGRASP::calcularTCTParcial(
  const Nodo* kNodoRaiz,
  const int kPosTareaOriginal,
  const int kPosTareaMovida,
  const Solucion& kSolucionAnterior,
  Solucion& solucion_tras_movimiento
) const {
  // No calculo el valor absoluto entre kPosTareaOriginal y kPosTareaMovida, para ver si es
  // más eficiente calcular todo el TCT de nuevo porque siempre entra a está función los elementos contiguos
  const std::vector<const Nodo*> kTareasAnterior = kSolucionAnterior.getTareas();
  const std::vector<const Nodo*> kTareas = solucion_tras_movimiento.getTareas();
  const int kNumTareas = kTareasAnterior.size();//, kNumPasos = kPosTareaMovida + 1;
  int tct = kSolucionAnterior.getTCT(), inf = kPosTareaOriginal - 1, sup = kPosTareaMovida;
  // Resto del kNodoRaiz al que muevo y sumo al siguiente, actualizo el limite inferior del for
  if (kPosTareaOriginal == 0) {
    inf = kPosTareaOriginal;
    tct -= kNumTareas * kNodoRaiz->getCosteHaciaVecino(kTareasAnterior[0]);
    tct += kNumTareas * kNodoRaiz->getCosteHaciaVecino(kTareas[0]);
  }
  if (kPosTareaMovida == kNumTareas - 1) sup--; // Si se mueve al último resto el índice superior 
  for (; inf <= sup; ++inf) { // Son 3 restas y 3 sumas porque siempre están contiguos
    tct -= (kNumTareas - inf - 1) * kTareasAnterior[inf]->getCosteHaciaVecino(kTareasAnterior[inf + 1]);
    tct += (kNumTareas - inf - 1) * kTareas[inf]->getCosteHaciaVecino(kTareas[inf + 1]);
  }
  solucion_tras_movimiento.setTCT() = tct;
  return tct;
}