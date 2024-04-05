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
    //std::cout << "Maquina " << i << std::endl << std::endl;
    //        std::cout << "kTctMaquinaI: " << kTctMaquinaI << std::endl;
    //    Solucion::mostrarTareasDeTodasLasMaquinas(kSolucionActual);
    for (int j = 0; j < kNumTareas; ++j) {
      solucion_vecina = kSolucionActual;
      const Nodo* kTarea = solucion_vecina[i].getTareas()[j];
      for (int k = j + 1; k < kNumTareas; ++k) {
        solucion_vecina_anterior = solucion_vecina[i];
        solucion_vecina[i].moverTareaAPosicionDada(kTarea, k);
        //const int kTctVecinoI = solucion_vecina[i].calcularTCT(kNodoRaiz);
        //std::cout << "Primer mov TCT TOTAL: " << kTctVecinoI << std::endl;
        //Solucion::mostrarTareasDeTodasLasMaquinas(solucion_vecina);
        const int kTctVecinoI = calcularTCTParcial(
          kNodoRaiz, k, solucion_vecina_anterior, solucion_vecina[i]
        );
        /*std::cout << "Primer mov TCT PARCIAL: " << kTctVecinoAux << std::endl;
        Solucion::mostrarTareasDeTodasLasMaquinas(solucion_vecina);*/
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
  const int kPosTareaMovida,
  const Solucion& kSolucionAnterior,
  Solucion& solucion_tras_movimiento
) const {
  if (kPosTareaMovida <= (solucion_tras_movimiento.getTareas().size() / 2)) {
    return solucion_tras_movimiento.calcularTCT(kNodoRaiz);
  }
  /*std::cout << "TCT: " << kSolucionAnterior.getTCT() << std::endl;
  solucion_tras_movimiento.calcularTCT(kNodoRaiz);
  std::cout << "TCT: " << solucion_tras_movimiento.getTCT() << std::endl;*/
  const std::vector<const Nodo*> kTareasAnterior = kSolucionAnterior.getTareas();
  const std::vector<const Nodo*> kTareas = solucion_tras_movimiento.getTareas();
  const int kNumTareas = kTareasAnterior.size(), kNumPasos = (kNumTareas - kPosTareaMovida + 1);
  int tct = kSolucionAnterior.getTCT();
  //std::cout << "kNumPasos: " << kNumPasos << std::endl;
  //std::cout << "tct: " << tct << std::endl;
  for (int i = 1; i <= kNumPasos; ++i) {
    tct -= i * (
      kTareasAnterior[kNumTareas - 1 - i]->getCosteHaciaVecino(kTareasAnterior[kNumTareas - i])
    );
    tct += i * (
      kTareas[kNumTareas - 1 - i]->getCosteHaciaVecino(kTareas[kNumTareas - i])
    );
  }
  solucion_tras_movimiento.setTCT() = tct;
  return tct;
  //exit(EXIT_FAILURE);
}