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
      for (int k = j + 1; k < kNumTareas; ++k) {
        solucion_vecina_anterior = solucion_vecina[i];
        /*std::cout << "Antes:\n";
        Solucion::mostrarTareasDeTodasLasMaquinas(solucion_vecina);
        std::cout << std::endl;*/       
        solucion_vecina[i].moverTarea(k - 1, k);
        /*std::cout << "Despues:\n";
        Solucion::mostrarTareasDeTodasLasMaquinas(solucion_vecina);
        std::cout << std::endl;*/
        //const int kTctVecinoI = solucion_vecina[i].calcularTCT(kNodoRaiz);
        //std::cout << "Primer mov TCT TOTAL: " << kTctVecinoI << std::endl;
        const int kTctVecinoI = calcularTCTParcial(
          kNodoRaiz, k - 1, k, solucion_vecina_anterior, solucion_vecina[i]
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
  const int kPosTareaOriginal,
  const int kPosTareaMovida,
  const Solucion& kSolucionAnterior,
  Solucion& solucion_tras_movimiento
) const {
  /*std::cout << std::endl;
  for (auto a : kSolucionAnterior.getTareas()) {
    std::cout << a->getId() << " ";
  }
  std::cout << std::endl;
  for (auto a : solucion_tras_movimiento.getTareas()) {
    std::cout << a->getId() << " ";
  }  
  std::cout << std::endl;*/
  /*std::cout << "TCT: " << kSolucionAnterior.getTCT() << std::endl;
  solucion_tras_movimiento.calcularTCT(kNodoRaiz);
  std::cout << "TCT: " << solucion_tras_movimiento.getTCT() << std::endl;*/
  const std::vector<const Nodo*> kTareasAnterior = kSolucionAnterior.getTareas();
  const std::vector<const Nodo*> kTareas = solucion_tras_movimiento.getTareas();
  const int kNumTareas = kTareasAnterior.size();//, kNumPasos = kPosTareaMovida + 1;
  int tct = kSolucionAnterior.getTCT(), inf = kPosTareaOriginal - 1, sup = kPosTareaMovida;
  if (kPosTareaOriginal == 0) {
    inf = kPosTareaOriginal;
    tct -= kNumTareas * kNodoRaiz->getCosteHaciaVecino(kTareasAnterior[0]);
    tct += kNumTareas * kNodoRaiz->getCosteHaciaVecino(kTareas[0]);
    //std::cout << kNumTareas << " * " << kNodoRaiz->getId() << " - " << kTareasAnterior[0]->getId() << std::endl;
    //std::cout << kNumTareas << " * " << kNodoRaiz->getId() << " + " << kTareas[0]->getId() << std::endl;
  }
  if (kPosTareaMovida == kNumTareas - 1) sup--;
  for (; inf <= sup; ++inf) {
    tct -= (kNumTareas - inf - 1) * kTareasAnterior[inf]->getCosteHaciaVecino(kTareasAnterior[inf + 1]);
    tct += (kNumTareas - inf - 1) * kTareas[inf]->getCosteHaciaVecino(kTareas[inf + 1]);
    //std::cout << kNumTareas - inf - 1 << " * " << kTareasAnterior[inf]->getId() << " - " << kTareasAnterior[inf + 1]->getId() << std::endl;
    //std::cout << kNumTareas - inf - 1 << " * " << kTareas[inf]->getId() << " + " << kTareas[inf + 1]->getId() << std::endl;    
  }
  //std::cout << std::endl;
  /*tct -= kNumTareas * (kNodoRaiz->getCosteHaciaVecino(kTareasAnterior[0]));
  tct += kNumTareas * (kNodoRaiz->getCosteHaciaVecino(kTareas[0]));  
  for (int i = 1; i <= kNumPasos; ++i) {
    tct -= (kNumTareas - i) * kTareasAnterior[i - 1]->getCosteHaciaVecino(kTareasAnterior[i]);
    tct += (kNumTareas - i) * kTareas[i - 1]->getCosteHaciaVecino(kTareas[i]);
  }*/
  /*if (tct != solucion_tras_movimiento.calcularTCT(kNodoRaiz)) {
    
  std::cout << std::endl;
  for (auto a : kSolucionAnterior.getTareas()) {
    std::cout << a->getId() << " ";
  }
  std::cout << std::endl;
  std::cout << std::endl;
  for (auto a : solucion_tras_movimiento.getTareas()) {
    std::cout << a->getId() << " ";
  }
  std::cout << std::endl;      
    std::cout << "CUIDAO" << std::endl;
    std::cout << "tct: " << tct << std::endl;
    std::cout << "tct: " << solucion_tras_movimiento.calcularTCT(kNodoRaiz) << std::endl;
    exit(1);
  }*/
  solucion_tras_movimiento.setTCT() = tct;
  return tct;
  //exit(EXIT_FAILURE);
}