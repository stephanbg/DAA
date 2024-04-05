#include "movimientoSwapIntraGRASP.h"

const std::vector<Solucion> MovimientoSwapIntraGRASP::busquedaLocal(
  const std::vector<Solucion>& kSolucionActual,
  const Nodo* kNodoRaiz
) const {
  //Solucion::mostrarTareasDeTodasLasMaquinas(kSolucionActual);
  /*std::vector<Solucion> solucion_vecina, solucion_mejor;
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
      const Nodo* kTarea = kSolucionActual[i].getTareas()[j];
      for (int k = j + 1; k < kNumTareas; ++k) {
        solucion_vecina = kSolucionActual;
        //solucion_vecina_anterior = solucion_vecina[i];
        solucion_vecina[i].swapTarea(j, k);
        //const int kTctVecinoI = solucion_vecina[i].calcularTCT(kNodoRaiz);
        //std::cout << "Primer mov TCT TOTAL: " << kTctVecinoI << std::endl;
        //Solucion::mostrarTareasDeTodasLasMaquinas(solucion_vecina);
        const int kTctVecinoI = calcularTCTParcial(
          kNodoRaiz, j, k, kSolucionActual[i], solucion_vecina[i]
        );
        //std::cout << "Primer mov TCT PARCIAL: " << kTctVecinoAux << std::endl;
        //Solucion::mostrarTareasDeTodasLasMaquinas(solucion_vecina);
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
  return solucion_mejor;*/
}

const int MovimientoSwapIntraGRASP::calcularTCTParcial(
  const Nodo* kNodoRaiz,
  const int kPosOrigen,
  const int kPosDestino,
  const Solucion& kSolucionActual,
  Solucion& solucion_tras_swap 
) const {
  /*int tct = kSolucionActual.getTCT();
  const std::vector<const Nodo*> kTareasActual = kSolucionActual.getTareas();
  const std::vector<const Nodo*> kTareasSiguientes = solucion_tras_swap.getTareas();
  const int kNumTareas = kTareasActual.size(),
  kNumTareasMenosPosOrigen = kNumTareas - kPosOrigen, // Factores k
  kNumTareasMenosPosDestino = kNumTareas - kPosDestino;
  if (kPosOrigen == 0) { // Si es primera tarea restar/sumar enlace hacia nodo raíz con nodo origen y destino
    tct -= kNumTareas * kNodoRaiz->getCosteHaciaVecino(kTareasActual[kPosOrigen]);
    tct += kNumTareas * kNodoRaiz->getCosteHaciaVecino(kTareasSiguientes[kPosOrigen]);   
  } else { // Si es cualquier tarea distinta de la primera restar/sumar enlace hacia el nodo de antes con nodo origen y destino
    tct -= (kNumTareasMenosPosOrigen) * kTareasActual[kPosOrigen - 1]->getCosteHaciaVecino(kTareasActual[kPosOrigen]);
    tct += (kNumTareasMenosPosOrigen) * kTareasSiguientes[kPosOrigen - 1]->getCosteHaciaVecino(kTareasSiguientes[kPosOrigen]);
  }
  if (kPosOrigen < kNumTareas - 1) { // Si el origen no es el último restar/sumar enlace hacia siguiente nodo
    tct -= (kNumTareasMenosPosOrigen - 1) * kTareasActual[kPosOrigen]->getCosteHaciaVecino(kTareasActual[kPosOrigen + 1]);
    tct += (kNumTareasMenosPosOrigen - 1) * kTareasSiguientes[kPosOrigen]->getCosteHaciaVecino(kTareasSiguientes[kPosOrigen + 1]);
  }
  if (kPosDestino < kNumTareas - 1) { // Si el destino no es el último restar/sumar enlace hacia siguiente nodo
    tct -= (kNumTareasMenosPosDestino - 1) * (kTareasActual[kPosDestino]->getCosteHaciaVecino(kTareasActual[kPosDestino + 1]));
    tct += (kNumTareasMenosPosDestino - 1) * (kTareasSiguientes[kPosDestino]->getCosteHaciaVecino(kTareasSiguientes[kPosDestino + 1]));
  }  
  if (kPosDestino != kPosOrigen + 1) { // No restar/sumar si el destino es el contiguo al origen (porque se repetiría)
    tct -= (kNumTareasMenosPosDestino) * kTareasActual[kPosDestino - 1]->getCosteHaciaVecino(kTareasActual[kPosDestino]);
    tct += (kNumTareasMenosPosDestino) * kTareasSiguientes[kPosDestino - 1]->getCosteHaciaVecino(kTareasSiguientes[kPosDestino]);
  }
  // Restas (en la solución anterior) y sumas (en la solución siguiente)
  solucion_tras_swap.setTCT() = tct;
  return tct;*/
}