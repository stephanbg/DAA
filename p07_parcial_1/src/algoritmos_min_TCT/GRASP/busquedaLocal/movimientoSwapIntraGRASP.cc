#include "movimientoSwapIntraGRASP.h"

const std::vector<Solucion> MovimientoSwapIntraGRASP::busquedaLocal(
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
    const int kNumTareasI = kSolucionActual[i].getTareas().size();
    for (int j = 0; j < kNumTareasI; ++j) {
      const Nodo* kTarea = kSolucionActual[i].getTareas()[j];
      for (int l = i + 1; l < kNumMaquinas; ++l) {
        const int kNumTareasL = kSolucionActual[l].getTareas().size();
        for (int k = 0; k < kNumTareasL; ++k) {
          solucion_vecina = kSolucionActual;
          const int kTctMaquinaL = solucion_vecina[l].getTCT();
          //solucion_vecina_anterior = solucion_vecina[i];
          solucion_vecina[i].swapTareaEntreMaquinas(j, k, solucion_vecina[l]);
          //const int kTctVecinoI = solucion_vecina[i].calcularTCT(kNodoRaiz);
          //std::cout << "Primer mov TCT TOTAL: " << kTctVecinoI << std::endl;
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

const std::pair<int, int> MovimientoSwapIntraGRASP::calcularTCTParcial(
  const Nodo* kNodoRaiz,
  const int kPosTareaSolucionOrigen,
  const int kPosTareaSolucionDestino,
  Solucion& solucion_origen_tras_swap,
  Solucion& solucion_destino_tras_swap
) const {
  std::pair<int, int> tct;
  tct.first = solucion_origen_tras_swap.getTCT();
  tct.second = solucion_destino_tras_swap.getTCT();
  const std::vector<const Nodo*> kTareasMaquina1 = solucion_origen_tras_swap.getTareas();
  const std::vector<const Nodo*> kTareasMaquina2 = solucion_destino_tras_swap.getTareas();
  // Cada Tarea y anterior y siguiente
  const Nodo* kTarea1 = kTareasMaquina1[kPosTareaSolucionOrigen];
  const Nodo* kTarea2 = kTareasMaquina2[kPosTareaSolucionDestino];
  const Nodo* kTareaSiguienteA1 = kTareasMaquina1[kPosTareaSolucionOrigen + 1];
  const Nodo* kTareaSiguienteA2 = kTareasMaquina2[kPosTareaSolucionDestino + 1];
  const Nodo* kTareaAnteriorA1 = kTareasMaquina1[kPosTareaSolucionOrigen - 1];
  const Nodo* kTareaAnteriorA2 = kTareasMaquina2[kPosTareaSolucionDestino - 1];  
  const int kNumTareas1 = kTareasMaquina1.size();
  const int kNumTareas2 = kTareasMaquina2.size();
  // RESTAS CRUZADAS Y SUMAS EN MISMA MAQUINA PORQUE SE HIZO UN SWAP PREVIO
  // Maquina Origen
  if (kPosTareaSolucionOrigen == 0) { // Cuando es el primero restas y sumas para atrás con Nodo raíz
    tct.first -= kNumTareas1 * (kNodoRaiz->getCosteHaciaVecino(kTarea2));
    tct.first += kNumTareas1 * (kNodoRaiz->getCosteHaciaVecino(kTarea1));
  }
  if (kPosTareaSolucionOrigen < kNumTareas1 - 1) { // Cuando son todos menos el último restas y sumas para alante
    tct.first -= (kNumTareas1 - kPosTareaSolucionOrigen - 1) * (kTarea2->getCosteHaciaVecino(kTareaSiguienteA1));
    tct.first += (kNumTareas1 - kPosTareaSolucionOrigen - 1) * (kTarea1->getCosteHaciaVecino(kTareaSiguienteA1));
  }
  if (kPosTareaSolucionOrigen > 0) { // Cuando son todos menos el primero restar y sumar para atrás
    tct.first -= (kNumTareas1 - kPosTareaSolucionOrigen) * (kTareaAnteriorA1->getCosteHaciaVecino(kTarea2));
    tct.first += (kNumTareas1 - kPosTareaSolucionOrigen) * (kTareaAnteriorA1->getCosteHaciaVecino(kTarea1));
  }  
  // Maquina Destino
  if (kPosTareaSolucionDestino == 0) { // Cuando es el primero restas y sumas para atrás con Nodo raíz
    tct.second -= kNumTareas2 * (kNodoRaiz->getCosteHaciaVecino(kTarea1));
    tct.second += kNumTareas2 * (kNodoRaiz->getCosteHaciaVecino(kTarea2));
  }
  if (kPosTareaSolucionDestino < kNumTareas2 - 1) { // Cuando son todos menos el último restas y sumas para alante
    tct.second -= (kNumTareas2 - kPosTareaSolucionDestino - 1) * (kTarea1->getCosteHaciaVecino(kTareaSiguienteA2));
    tct.second += (kNumTareas2 - kPosTareaSolucionDestino - 1) * (kTarea2->getCosteHaciaVecino(kTareaSiguienteA2));
  }
  if (kPosTareaSolucionDestino > 0) { // Cuando son todos menos el primero restar y sumar para atrás
    tct.second -= (kNumTareas2 - kPosTareaSolucionDestino) * (kTareaAnteriorA2->getCosteHaciaVecino(kTarea1));
    tct.second += (kNumTareas2 - kPosTareaSolucionDestino) * (kTareaAnteriorA2->getCosteHaciaVecino(kTarea2));
  }  
  solucion_origen_tras_swap.setTCT() = tct.first;
  solucion_destino_tras_swap.setTCT() = tct.second;
  return tct;
}