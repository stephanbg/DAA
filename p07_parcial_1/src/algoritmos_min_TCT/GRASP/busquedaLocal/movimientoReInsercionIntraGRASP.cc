#include "movimientoReInsercionIntraGRASP.h"

const std::vector<Solucion> MovimientoReInsercionIntraGRASP::busquedaLocal(
  const std::vector<Solucion>& kSolucionActual,
  const Nodo* kNodoRaiz
) const {
  ////Solucion::mostrarTareasDeTodasLasMaquinas(kSolucionActual);
  //std::cout << std::endl;
  std::vector<Solucion> solucion_vecina, solucion_mejor;
  Solucion solucion_vecina_anterior;
  const int kNumMaquinas = kSolucionActual.size();
  int funcion_objetivo_inicial = Solucion::getFuncionObjetivo(),
  funcion_objetivo = funcion_objetivo_inicial, funcion_objetivo_vecino = 0;
  for (int i = 0; i < kNumMaquinas; ++i) {
    const int kTctMaquinaI = kSolucionActual[i].getTCT();
    const int kNumTareas = kSolucionActual[i].getTareas().size();
    for (int j = 0; j < kNumTareas; ++j) {
      for (int l = i + 1; l < kNumMaquinas; ++l) {
        for (int k = 0; k <= kNumTareas; ++k) {
          solucion_vecina = kSolucionActual;
          const int kTctMaquinaL = solucion_vecina[l].getTCT();
          //solucion_vecina_anterior = solucion_vecina[i];
          //Solucion::mostrarTareasDeTodasLasMaquinas(solucion_vecina);
          //std::cout << std::endl;
          solucion_vecina[i].moverTareaEntreMaquinas(j, k, solucion_vecina[l]);
          //Solucion::mostrarTareasDeTodasLasMaquinas(solucion_vecina);
          //std::cout << std::endl;
          //const int kTctVecinoI = solucion_vecina[i].calcularTCT(kNodoRaiz);
          //std::cout << "Primer mov TCT TOTAL: " << kTctVecinoI << std::endl;
          //if (j < 10) continue; 
          const std::pair<int, int> kTctVecinoIL = calcularTCTParcial(
            kNodoRaiz, j, k, solucion_vecina[i], solucion_vecina[l]
          );
          //std::cout << "Primer mov TCT PARCIAL: " << kTctVecinoAux << std::endl;
          //Solucion::mostrarTareasDeTodasLasMaquinas(solucion_vecina);
          funcion_objetivo_vecino = (
            funcion_objetivo_inicial - kTctMaquinaI - kTctMaquinaL + kTctVecinoIL.first + kTctVecinoIL.second
          );
          if (funcion_objetivo_vecino < funcion_objetivo) {
            solucion_mejor = solucion_vecina;
            solucion_mejor[i].setTCT() = kTctVecinoIL.first;
            solucion_mejor[l].setTCT() = kTctVecinoIL.second;
            funcion_objetivo = funcion_objetivo_vecino;
          }
        }
      }
    }
  }
  Solucion::setFuncionObjetivo() = funcion_objetivo;
  return solucion_mejor;
}

int contador = 0;

const std::pair<int, int> MovimientoReInsercionIntraGRASP::calcularTCTParcial(
  const Nodo* kNodoRaiz,
  const int kPosTareaOrigen,
  const int kPosTareaDestino,
  Solucion& solucion_origen_tras_mov,
  Solucion& solucion_destino_tras_mov
) const {
  std::pair<int, int> tct;
  const std::vector<const Nodo*> kTareasMaquina1 = solucion_origen_tras_mov.getTareas();
  const std::vector<const Nodo*> kTareasMaquina2 = solucion_destino_tras_mov.getTareas();  
  tct.first = solucion_origen_tras_mov.getTCT();
  tct.second = solucion_destino_tras_mov.getTCT();
  // Se realizan los cálculos en cruzado debido a que hubo un previo swap
  const int kTareasMaq1Despues = kTareasMaquina1.size(), kTareasMaq1Antes = kTareasMaq1Despues + 1;
  const int kTareasMaq2Despues = kTareasMaquina2.size(), kTareasMaq2Antes = kTareasMaq2Despues - 1;
  const int kNumPasos1 = kPosTareaOrigen - 1, kNumPasos2 = kPosTareaDestino - 1;
  //std::cout << "kNumPasos1: " << kNumPasos1 << std::endl;
  //const int kNumTareasMaq2 = kTareasMaquina2.size();
  // En ambos pasos voy a hacer solo hasta el elmento que se mueve porque el anterior lo haré fuera del for
  //const int kNumPasosMaq2 = (kNumTareasMaq2 - kPosTareaDestino - 2);
  //std::cout << "kNumPasos: " << kNumPasos << std::endl;
  //std::cout << "tct: " << tct << std::endl;
  // Maquina 1
  if (kPosTareaOrigen == 0) {
    tct.first -= kTareasMaq1Antes * kNodoRaiz->getCosteHaciaVecino(kTareasMaquina2[kPosTareaDestino]);
    tct.first -= (kTareasMaq1Antes - 1) * kTareasMaquina2[kPosTareaDestino]->getCosteHaciaVecino(kTareasMaquina1[kPosTareaOrigen]);
    //std::cout << (kTareasMaq1Antes) << "*" << kNodoRaiz->getId() << "-" << kTareasMaquina2[kPosTareaDestino]->getId() << std::endl;
    //std::cout << (kTareasMaq1Antes - 1) << "*" << kTareasMaquina2[kPosTareaDestino]->getId() << "-" << kTareasMaquina1[kPosTareaOrigen]->getId() << std::endl;
  } else {
    tct.first -= kTareasMaq1Antes * kNodoRaiz->getCosteHaciaVecino(kTareasMaquina1[0]);
    if (kPosTareaOrigen < kTareasMaq1Antes - 1) {
      //std::cout << (kTareasMaq1Antes - kPosTareaOrigen) << "*" << kTareasMaquina1[kPosTareaOrigen - 1]->getId() << "-" << kTareasMaquina2[kPosTareaDestino]->getId() << std::endl;
      tct.first -= (kTareasMaq1Antes - kPosTareaOrigen) * (kTareasMaquina1[kPosTareaOrigen - 1]->getCosteHaciaVecino(kTareasMaquina2[kPosTareaDestino]));
      //std::cout << (kTareasMaq1Antes - kPosTareaOrigen - 1) << "*" << kTareasMaquina2[kPosTareaDestino]->getId() << "-" << kTareasMaquina1[kPosTareaOrigen]->getId() << std::endl;
      tct.first -= (kTareasMaq1Antes - kPosTareaOrigen - 1) * (kTareasMaquina2[kPosTareaDestino]->getCosteHaciaVecino(kTareasMaquina1[kPosTareaOrigen]));    
      //std::cout << (kTareasMaq1Despues - kPosTareaOrigen) << "*" << kTareasMaquina1[kPosTareaOrigen - 1]->getId() << "+" << kTareasMaquina1[kPosTareaOrigen]->getId() << std::endl;
      tct.first += (kTareasMaq1Despues - kPosTareaOrigen) * (kTareasMaquina1[kPosTareaOrigen - 1]->getCosteHaciaVecino(kTareasMaquina1[kPosTareaOrigen]));  
    }
    if (kPosTareaOrigen == kTareasMaq1Antes - 1) {
      //std::cout << 1 << "*" << kTareasMaquina1[kPosTareaOrigen - 1]->getId() << "-" << kTareasMaquina2[kPosTareaDestino]->getId() << std::endl;
      tct.first -= (kTareasMaquina1[kPosTareaOrigen - 1]->getCosteHaciaVecino(kTareasMaquina2[kPosTareaDestino]));        
    }    
    //std::cout << (kTareasMaq1Antes) << "*" << kNodoRaiz->getId() << "-" << kTareasMaquina1[0]->getId() << std::endl;
  }
  tct.first += kTareasMaq1Despues * kNodoRaiz->getCosteHaciaVecino(kTareasMaquina1[0]);
  //std::cout << (kTareasMaq1Despues) << "*" << kNodoRaiz->getId() << "+" << kTareasMaquina1[0]->getId() << std::endl;
  for (int i = 1; i <= kNumPasos1; ++i) {
    //std::cout << (kTareasMaq1Antes - i) << "*" << kTareasMaquina1[i - 1]->getId() << "-" << kTareasMaquina1[i]->getId() << std::endl;
    tct.first -= (kTareasMaq1Antes - i) * (kTareasMaquina1[i - 1]->getCosteHaciaVecino(kTareasMaquina1[i]));
    //std::cout << (kTareasMaq1Despues - i) << "*" << kTareasMaquina1[i - 1]->getId() << "+" << kTareasMaquina1[i]->getId() << std::endl;
    tct.first += (kTareasMaq1Despues - i) * (kTareasMaquina1[i - 1]->getCosteHaciaVecino(kTareasMaquina1[i]));
  }

  // Maquina 2
  if (kPosTareaDestino == 0) {
    tct.second -= kTareasMaq2Antes * kNodoRaiz->getCosteHaciaVecino(kTareasMaquina2[1]);
    //std::cout << (kTareasMaq2Antes) << "*" << kNodoRaiz->getId() << "-" << kTareasMaquina2[1]->getId() << std::endl;
    tct.second += (kTareasMaq2Despues - 1) * kTareasMaquina2[0]->getCosteHaciaVecino(kTareasMaquina2[1]);
    //std::cout << (kTareasMaq2Despues - 1) << "*" << kTareasMaquina2[0]->getId() << "+" << kTareasMaquina2[1]->getId() << std::endl;
  } else {
    tct.second -= kTareasMaq2Antes * kNodoRaiz->getCosteHaciaVecino(kTareasMaquina2[0]);
    //std::cout << (kTareasMaq2Antes) << "*" << kNodoRaiz->getId() << "-" << kTareasMaquina2[0]->getId() << std::endl;
    if (kPosTareaDestino < kTareasMaq2Despues - 1) {
      //std::cout << (kTareasMaq2Antes - kPosTareaDestino) << "*" << kTareasMaquina2[kPosTareaDestino - 1]->getId() << "-" << kTareasMaquina2[kPosTareaDestino + 1]->getId() << std::endl;
      tct.second -= (kTareasMaq2Antes - kPosTareaDestino) * (kTareasMaquina2[kPosTareaDestino - 1]->getCosteHaciaVecino(kTareasMaquina2[kPosTareaDestino + 1]));
      //std::cout << (kTareasMaq2Despues - kPosTareaDestino) << "*" << kTareasMaquina2[kPosTareaDestino - 1]->getId() << "+" << kTareasMaquina2[kPosTareaDestino]->getId() << std::endl;
      tct.second += (kTareasMaq2Despues - kPosTareaDestino) * (kTareasMaquina2[kPosTareaDestino - 1]->getCosteHaciaVecino(kTareasMaquina2[kPosTareaDestino]));
      //std::cout << (kTareasMaq2Despues - kPosTareaDestino - 1) << "*" << kTareasMaquina2[kPosTareaDestino]->getId() << "+" << kTareasMaquina2[kPosTareaDestino + 1]->getId() << std::endl;
      tct.second += (kTareasMaq2Despues - kPosTareaDestino - 1) * (kTareasMaquina2[kPosTareaDestino]->getCosteHaciaVecino(kTareasMaquina2[kPosTareaDestino + 1]));
    }
    if (kPosTareaDestino == kTareasMaq2Despues - 1) {
      //std::cout << 1 << "*" << kTareasMaquina2[kPosTareaDestino - 1]->getId() << "+" << kTareasMaquina2[kPosTareaDestino]->getId() << std::endl;
      tct.second += (kTareasMaquina2[kPosTareaDestino - 1]->getCosteHaciaVecino(kTareasMaquina2[kPosTareaDestino]));
    }     
  }
  tct.second += kTareasMaq2Despues * kNodoRaiz->getCosteHaciaVecino(kTareasMaquina2[0]);
  //std::cout << (kTareasMaq2Despues) << "*" << kNodoRaiz->getId() << "+" << kTareasMaquina2[0]->getId() << std::endl;  
  for (int i = 1; i <= kNumPasos2; ++i) {
    tct.second -= (kTareasMaq2Antes - i) * (kTareasMaquina2[i - 1]->getCosteHaciaVecino(kTareasMaquina2[i]));
    //std::cout << (kTareasMaq2Antes - i) << "*" << kTareasMaquina2[i - 1]->getId() << "-" << kTareasMaquina2[i]->getId() << std::endl;
    tct.second += (kTareasMaq2Despues - i) * (kTareasMaquina2[i - 1]->getCosteHaciaVecino(kTareasMaquina2[i]));
    //std::cout << (kTareasMaq2Despues - i) << "*" << kTareasMaquina2[i - 1]->getId() << "+" << kTareasMaquina2[i]->getId() << std::endl;
  } 
  solucion_origen_tras_mov.setTCT() = tct.first;
  solucion_destino_tras_mov.setTCT() = tct.second;
  if (tct.first != solucion_origen_tras_mov.calcularTCT(kNodoRaiz) ||
  tct.second != solucion_destino_tras_mov.calcularTCT(kNodoRaiz)) {
    std::cout << tct.first << std::endl;
    std::cout << solucion_origen_tras_mov.calcularTCT(kNodoRaiz) << std::endl;
    std::cout << tct.second << std::endl;
    std::cout << solucion_destino_tras_mov.calcularTCT(kNodoRaiz) << std::endl;    
    exit(1);
  }
  return tct;
}