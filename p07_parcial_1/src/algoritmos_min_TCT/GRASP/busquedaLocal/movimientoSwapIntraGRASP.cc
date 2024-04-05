#include "movimientoSwapIntraGRASP.h"

const std::vector<Solucion> MovimientoSwapIntraGRASP::busquedaLocal(
  const std::vector<Solucion>& kSolucionActual,
  const Nodo* kNodoRaiz
) const {
  //Solucion::mostrarTareasDeTodasLasMaquinas(kSolucionActual);
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
      const Nodo* kTarea = kSolucionActual[i].getTareas()[j];
      for (int l = i + 1; l < kNumMaquinas; ++l) {
        for (int k = 0; k < kNumTareas; ++k) {
          solucion_vecina = kSolucionActual;
          const int kTctMaquinaL = solucion_vecina[l].getTCT();
          //solucion_vecina_anterior = solucion_vecina[i];
          solucion_vecina[i].swapTareaEntreMaquinas(j, k, solucion_vecina[l]);
          //const int kTctVecinoI = solucion_vecina[i].calcularTCT(kNodoRaiz);
          //std::cout << "Primer mov TCT TOTAL: " << kTctVecinoI << std::endl;
          //Solucion::mostrarTareasDeTodasLasMaquinas(solucion_vecina);
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
  std::pair<int, int> tct_ambas_maquinas;
  tct_ambas_maquinas.first = solucion_origen_tras_swap.getTCT();
  tct_ambas_maquinas.second = solucion_destino_tras_swap.getTCT();
  const std::vector<const Nodo*> kTareasOrigen = solucion_origen_tras_swap.getTareas();
  const std::vector<const Nodo*> kTareasDestino = solucion_destino_tras_swap.getTareas();
  const int kNumTareasOrigen = kTareasOrigen.size();
  const int kNumTareasDestino = kTareasDestino.size();
  // RESTAS CRUZADAS Y SUMAS EN MISMA MAQUINA PORQUE SE HIZO UN SWAP PREVIO
  if (kPosTareaSolucionOrigen == 0) { // Tarea origen está en la primera pos de la máquina 1
    if (kPosTareaSolucionDestino == 0) { // Tarea destino está en la primera pos de la máquina 2 CREO QUE BIEN
      // Restar maquina 1
      tct_ambas_maquinas.first -= kNumTareasOrigen * (
        kNodoRaiz->getCosteHaciaVecino(kTareasDestino[kPosTareaSolucionDestino])
      );
      if (kPosTareaSolucionOrigen < kNumTareasOrigen - 1) {
        tct_ambas_maquinas.first -= (kNumTareasOrigen - 1) * (
          kTareasDestino[kPosTareaSolucionDestino]->getCosteHaciaVecino(kTareasOrigen[kPosTareaSolucionOrigen + 1])
        );
      }
      // Restar maquina 2
      tct_ambas_maquinas.second -= kNumTareasDestino * (
        kNodoRaiz->getCosteHaciaVecino(kTareasOrigen[kPosTareaSolucionOrigen])
      );
      if (kPosTareaSolucionDestino < kNumTareasDestino - 1) {
        tct_ambas_maquinas.second -= (kNumTareasDestino - 1) * (
          kTareasOrigen[kPosTareaSolucionOrigen]->getCosteHaciaVecino(kTareasDestino[kPosTareaSolucionDestino + 1])
        );
      }
      // Sumar maquina 1
      tct_ambas_maquinas.first += kNumTareasOrigen * (
        kNodoRaiz->getCosteHaciaVecino(kTareasOrigen[kPosTareaSolucionOrigen])
      );
      if (kPosTareaSolucionOrigen < kNumTareasOrigen - 1) {
        tct_ambas_maquinas.first += (kNumTareasOrigen - 1) * (
          kTareasOrigen[kPosTareaSolucionOrigen]->getCosteHaciaVecino(kTareasOrigen[kPosTareaSolucionOrigen + 1])
        );    
      }
      // Sumar maquina 2
      tct_ambas_maquinas.second += kNumTareasDestino * (
        kNodoRaiz->getCosteHaciaVecino(kTareasDestino[kPosTareaSolucionDestino])
      );
      if (kPosTareaSolucionDestino < kNumTareasDestino - 1) {
        tct_ambas_maquinas.second += (kNumTareasDestino - 1) * (
          kTareasDestino[kPosTareaSolucionDestino]->getCosteHaciaVecino(kTareasDestino[kPosTareaSolucionDestino + 1])
        );
      }
    } else if (kPosTareaSolucionDestino == kNumTareasDestino - 1) { // Tarea destino está en la última pos de la máquina 2 CREO QUE BIEN
      // Restar maquina 1
      tct_ambas_maquinas.first -= kNumTareasOrigen * (
        kNodoRaiz->getCosteHaciaVecino(kTareasDestino[kPosTareaSolucionDestino])
      );
      if (kPosTareaSolucionOrigen < kNumTareasOrigen - 1) {
        tct_ambas_maquinas.first -= (kNumTareasOrigen - 1) * (
          kTareasDestino[kPosTareaSolucionDestino]->getCosteHaciaVecino(kTareasOrigen[kPosTareaSolucionOrigen + 1])
        );
      }
      // Restar maquina 2
      tct_ambas_maquinas.second -= (
        kTareasDestino[kPosTareaSolucionDestino - 1]->getCosteHaciaVecino(kTareasOrigen[kPosTareaSolucionOrigen])
      );
      // Sumar maquina 1
      tct_ambas_maquinas.first += kNumTareasOrigen * (
        kNodoRaiz->getCosteHaciaVecino(kTareasOrigen[kPosTareaSolucionOrigen])
      );
      if (kPosTareaSolucionOrigen < kNumTareasOrigen - 1) {
        tct_ambas_maquinas.first += (kNumTareasOrigen - 1) * (
          kTareasOrigen[kPosTareaSolucionOrigen]->getCosteHaciaVecino(kTareasOrigen[kPosTareaSolucionOrigen + 1])
        );    
      }
      // Sumar maquina 2
      tct_ambas_maquinas.second += (
        kTareasDestino[kPosTareaSolucionDestino - 1]->getCosteHaciaVecino(kTareasDestino[kPosTareaSolucionDestino])
      );            
    } else { // La tarea en destino no está ni en 0 ni al final CREO QUE BIEN
      // Restar maquina 1
      tct_ambas_maquinas.first -= kNumTareasOrigen * (
        kNodoRaiz->getCosteHaciaVecino(kTareasDestino[kPosTareaSolucionDestino])
      );
      if (kPosTareaSolucionOrigen < kNumTareasOrigen - 1) {
        tct_ambas_maquinas.first -= (kNumTareasOrigen - 1) * (
          kTareasDestino[kPosTareaSolucionDestino]->getCosteHaciaVecino(kTareasOrigen[kPosTareaSolucionOrigen + 1])
        );    
      }
      // Restar maquina 2
      tct_ambas_maquinas.second -= (kNumTareasDestino - kPosTareaSolucionDestino) * (
        kTareasDestino[kPosTareaSolucionDestino - 1]->getCosteHaciaVecino(kTareasOrigen[kPosTareaSolucionOrigen])
      );
      tct_ambas_maquinas.second -= (kNumTareasDestino - kPosTareaSolucionDestino - 1) * (
        kTareasOrigen[kPosTareaSolucionOrigen]->getCosteHaciaVecino(kTareasDestino[kPosTareaSolucionDestino + 1])
      );
      // Sumar maquina 1
      tct_ambas_maquinas.first += kNumTareasOrigen * (
        kNodoRaiz->getCosteHaciaVecino(kTareasOrigen[kPosTareaSolucionOrigen])
      );
      if (kPosTareaSolucionOrigen < kNumTareasOrigen - 1) {
        tct_ambas_maquinas.first += (kNumTareasOrigen - 1) * (
          kTareasOrigen[kPosTareaSolucionOrigen]->getCosteHaciaVecino(kTareasOrigen[kPosTareaSolucionOrigen + 1])
        );    
      }
      // Sumar maquina 2
      tct_ambas_maquinas.second += (kNumTareasDestino - kPosTareaSolucionDestino) * (
        kTareasDestino[kPosTareaSolucionDestino - 1]->getCosteHaciaVecino(kTareasDestino[kPosTareaSolucionDestino])
      );
      tct_ambas_maquinas.second += (kNumTareasDestino - kPosTareaSolucionDestino - 1) * (
        kTareasDestino[kPosTareaSolucionDestino]->getCosteHaciaVecino(kTareasDestino[kPosTareaSolucionDestino + 1])
      );    
    }
  } else if (kPosTareaSolucionOrigen == kNumTareasOrigen - 1) { // Origen al final CREO QUE BIEN
    if (kPosTareaSolucionDestino == 0) { // Destino al inicio
      // Restar maquina 1
      tct_ambas_maquinas.first -= (
        kTareasOrigen[kPosTareaSolucionOrigen - 1]->getCosteHaciaVecino(kTareasDestino[kPosTareaSolucionDestino])
      );
      // Restar maquina 2
      tct_ambas_maquinas.second -= kNumTareasDestino * (
        kNodoRaiz->getCosteHaciaVecino(kTareasOrigen[kPosTareaSolucionOrigen])
      );   
      if (kPosTareaSolucionDestino < kNumTareasDestino - 1) {
        tct_ambas_maquinas.second -= (kNumTareasDestino - 1) * (
          kTareasOrigen[kPosTareaSolucionOrigen]->getCosteHaciaVecino(kTareasDestino[kPosTareaSolucionDestino + 1])
        );    
      }
      // Sumar maquina 1
      tct_ambas_maquinas.first += (
        kTareasOrigen[kPosTareaSolucionOrigen - 1]->getCosteHaciaVecino(kTareasOrigen[kPosTareaSolucionOrigen])
      );
      // Sumar maquina 2
      tct_ambas_maquinas.second += kNumTareasDestino * (
        kNodoRaiz->getCosteHaciaVecino(kTareasDestino[kPosTareaSolucionDestino])
      );
      if (kPosTareaSolucionDestino < kNumTareasDestino - 1) {
        tct_ambas_maquinas.second += (kNumTareasDestino - 1) * (
          kTareasDestino[kPosTareaSolucionDestino]->getCosteHaciaVecino(kTareasDestino[kPosTareaSolucionDestino + 1])
        );
      }
    } else if (kPosTareaSolucionDestino == kNumTareasDestino - 1) { // Destino al final
      // Restar maquina 1
      tct_ambas_maquinas.first -= (
        kTareasOrigen[kPosTareaSolucionOrigen - 1]->getCosteHaciaVecino(kTareasDestino[kPosTareaSolucionDestino])
      );
      // Restar maquina 2
      tct_ambas_maquinas.second -= (
        kTareasDestino[kPosTareaSolucionDestino - 1]->getCosteHaciaVecino(kTareasOrigen[kPosTareaSolucionOrigen])
      );
      // Sumar maquina 1
      tct_ambas_maquinas.first += (
        kTareasOrigen[kPosTareaSolucionOrigen - 1]->getCosteHaciaVecino(kTareasOrigen[kPosTareaSolucionOrigen])
      );
      // Sumar maquina 2
      tct_ambas_maquinas.second += (
        kTareasDestino[kPosTareaSolucionDestino - 1]->getCosteHaciaVecino(kTareasDestino[kPosTareaSolucionDestino])
      );    
    } else { // Destino ni al final ni al inicio
      /*std::cout << "EY" << std::endl;
      std::cout << kTareasOrigen[kPosTareaSolucionOrigen - 1]->getId() << std::endl;
      std::cout << kTareasDestino[kPosTareaSolucionDestino]->getId() << std::endl;
      std::cout << kTareasDestino[kPosTareaSolucionDestino - 1]->getId() << std::endl;
      std::cout << kTareasOrigen[kPosTareaSolucionOrigen]->getId() << std::endl;
      std::cout << kTareasDestino[kPosTareaSolucionDestino + 1]->getId() << std::endl;*/
      // Restar maquina 1
      tct_ambas_maquinas.first -= (
        kTareasOrigen[kPosTareaSolucionOrigen - 1]->getCosteHaciaVecino(kTareasDestino[kPosTareaSolucionDestino])
      );
      // Restar maquina 2
      tct_ambas_maquinas.second -= (kNumTareasDestino - kPosTareaSolucionDestino) * (
        kTareasDestino[kPosTareaSolucionDestino - 1]->getCosteHaciaVecino(kTareasOrigen[kPosTareaSolucionOrigen])
      );  
      tct_ambas_maquinas.second -= (kNumTareasDestino - kPosTareaSolucionDestino - 1) * (
        kTareasOrigen[kPosTareaSolucionOrigen]->getCosteHaciaVecino(kTareasDestino[kPosTareaSolucionDestino + 1])
      );
      // Sumar maquina 1
      tct_ambas_maquinas.first += (
        kTareasOrigen[kPosTareaSolucionOrigen - 1]->getCosteHaciaVecino(kTareasOrigen[kPosTareaSolucionOrigen])
      );
      // Sumar maquina 2
      tct_ambas_maquinas.second += (kNumTareasDestino - kPosTareaSolucionDestino) * (
        kTareasDestino[kPosTareaSolucionDestino - 1]->getCosteHaciaVecino(kTareasDestino[kPosTareaSolucionDestino])
      );   
      tct_ambas_maquinas.second += (kNumTareasDestino - kPosTareaSolucionDestino - 1) * (
        kTareasDestino[kPosTareaSolucionDestino]->getCosteHaciaVecino(kTareasDestino[kPosTareaSolucionDestino + 1])
      );                   
    }
  } else { // Origen ni al inicio ni al final CREO QUE BIEN
    if (kPosTareaSolucionDestino == 0) { // Destino al inicio
      // Restar maquina 1
      tct_ambas_maquinas.first -= (kNumTareasOrigen - kPosTareaSolucionOrigen) * (
        kTareasOrigen[kPosTareaSolucionOrigen - 1]->getCosteHaciaVecino(kTareasDestino[kPosTareaSolucionDestino])
      );
      tct_ambas_maquinas.first -= (kNumTareasOrigen - kPosTareaSolucionOrigen - 1) * (
        kTareasDestino[kPosTareaSolucionDestino]->getCosteHaciaVecino(kTareasOrigen[kPosTareaSolucionOrigen + 1])
      );      
      // Restar maquina 2
      tct_ambas_maquinas.second -= kNumTareasDestino * (
        kNodoRaiz->getCosteHaciaVecino(kTareasOrigen[kPosTareaSolucionOrigen])
      );
      if (kPosTareaSolucionDestino < kNumTareasDestino - 1) {
        tct_ambas_maquinas.second -= (kNumTareasDestino - 1) * (
          kTareasOrigen[kPosTareaSolucionOrigen]->getCosteHaciaVecino(kTareasDestino[kPosTareaSolucionDestino + 1])
        );        
      }
      // Sumar maquina 1
      tct_ambas_maquinas.first += (kNumTareasOrigen - kPosTareaSolucionOrigen) * (
        kTareasOrigen[kPosTareaSolucionOrigen - 1]->getCosteHaciaVecino(kTareasOrigen[kPosTareaSolucionOrigen])
      );
      tct_ambas_maquinas.first += (kNumTareasOrigen - kPosTareaSolucionOrigen - 1) * (
        kTareasOrigen[kPosTareaSolucionOrigen]->getCosteHaciaVecino(kTareasOrigen[kPosTareaSolucionOrigen + 1])
      );           
      // Sumar maquina 2
      tct_ambas_maquinas.second += kNumTareasDestino * (
        kNodoRaiz->getCosteHaciaVecino(kTareasDestino[kPosTareaSolucionDestino])
      );
      if (kPosTareaSolucionDestino < kNumTareasDestino - 1) {
        tct_ambas_maquinas.second += (kNumTareasDestino - 1) * (
          kTareasDestino[kPosTareaSolucionDestino]->getCosteHaciaVecino(kTareasDestino[kPosTareaSolucionDestino + 1])
        );        
      }
    } else if (kPosTareaSolucionDestino == kNumTareasDestino - 1) { // Destino al final
      // Restar maquina 1
      tct_ambas_maquinas.first -= (kNumTareasOrigen - kPosTareaSolucionOrigen) * (
        kTareasOrigen[kPosTareaSolucionOrigen - 1]->getCosteHaciaVecino(kTareasDestino[kPosTareaSolucionDestino])
      );
      tct_ambas_maquinas.first -= (kNumTareasOrigen - kPosTareaSolucionOrigen - 1) * (
        kTareasDestino[kPosTareaSolucionDestino]->getCosteHaciaVecino(kTareasOrigen[kPosTareaSolucionOrigen + 1])
      );
      // Restar maquina 2
      tct_ambas_maquinas.second -= (
        kTareasDestino[kPosTareaSolucionDestino - 1]->getCosteHaciaVecino(kTareasOrigen[kPosTareaSolucionOrigen])
      );      
      // Sumar maquina 1
      tct_ambas_maquinas.first += (kNumTareasOrigen - kPosTareaSolucionOrigen) * (
        kTareasOrigen[kPosTareaSolucionOrigen - 1]->getCosteHaciaVecino(kTareasOrigen[kPosTareaSolucionOrigen])
      );
      tct_ambas_maquinas.first += (kNumTareasOrigen - kPosTareaSolucionOrigen - 1) * (
        kTareasOrigen[kPosTareaSolucionOrigen]->getCosteHaciaVecino(kTareasOrigen[kPosTareaSolucionOrigen + 1])
      );          
      // Sumar maquina 2
      tct_ambas_maquinas.second += (
        kTareasDestino[kPosTareaSolucionDestino - 1]->getCosteHaciaVecino(kTareasDestino[kPosTareaSolucionDestino])
      );
    } else { // Destino ni al inicio ni al final
      // Restar maquina 1
      tct_ambas_maquinas.first -= (kNumTareasOrigen - kPosTareaSolucionOrigen) * (
        kTareasOrigen[kPosTareaSolucionOrigen - 1]->getCosteHaciaVecino(kTareasDestino[kPosTareaSolucionDestino])
      );
      tct_ambas_maquinas.first -= (kNumTareasOrigen - kPosTareaSolucionOrigen - 1) * (
        kTareasDestino[kPosTareaSolucionDestino]->getCosteHaciaVecino(kTareasOrigen[kPosTareaSolucionOrigen + 1])
      );
      // Restar maquina 2
      tct_ambas_maquinas.second -= (kNumTareasDestino - kPosTareaSolucionDestino) * (
        kTareasDestino[kPosTareaSolucionDestino - 1]->getCosteHaciaVecino(kTareasOrigen[kPosTareaSolucionOrigen])
      );
      tct_ambas_maquinas.second -= (kNumTareasDestino - kPosTareaSolucionDestino - 1) * (
        kTareasOrigen[kPosTareaSolucionOrigen]->getCosteHaciaVecino(kTareasDestino[kPosTareaSolucionDestino + 1])
      );
      // Sumar maquina 1
      tct_ambas_maquinas.first += (kNumTareasOrigen - kPosTareaSolucionOrigen) * (
        kTareasOrigen[kPosTareaSolucionOrigen - 1]->getCosteHaciaVecino(kTareasOrigen[kPosTareaSolucionOrigen])
      );
      tct_ambas_maquinas.first += (kNumTareasOrigen - kPosTareaSolucionOrigen - 1) * (
        kTareasOrigen[kPosTareaSolucionOrigen]->getCosteHaciaVecino(kTareasOrigen[kPosTareaSolucionOrigen + 1])
      );
      // Sumar maquina 2
      tct_ambas_maquinas.second += (kNumTareasDestino - kPosTareaSolucionDestino) * (
        kTareasDestino[kPosTareaSolucionDestino - 1]->getCosteHaciaVecino(kTareasDestino[kPosTareaSolucionDestino])
      );
      tct_ambas_maquinas.second += (kNumTareasDestino - kPosTareaSolucionDestino - 1) * (
        kTareasDestino[kPosTareaSolucionDestino]->getCosteHaciaVecino(kTareasDestino[kPosTareaSolucionDestino + 1])
      );                           
    }
  }
  solucion_origen_tras_swap.setTCT() = tct_ambas_maquinas.first;
  solucion_destino_tras_swap.setTCT() = tct_ambas_maquinas.second;
  if (tct_ambas_maquinas.first != solucion_origen_tras_swap.calcularTCT(kNodoRaiz) || 
  tct_ambas_maquinas.second != solucion_destino_tras_swap.calcularTCT(kNodoRaiz)) {
    std::cout << std::endl;  
    for (auto a : solucion_origen_tras_swap.getTareas()) {
      std::cout << a->getId() << " ";
    }
    std::cout << std::endl;
    for (auto a : solucion_destino_tras_swap.getTareas()) {
      std::cout << a->getId() << " ";
    }
    std::cout << std::endl;    
    std::cout << "AYUDA POR FAVOR TENGO HAMBRE" << std::endl;
    std::cout << "tct_ambas_maquinas.first: " << tct_ambas_maquinas.first << std::endl;
    std::cout << "tct_ambas_maquinas.first: " << tct_ambas_maquinas.second << std::endl;
    std::cout << "real.first: " << solucion_origen_tras_swap.calcularTCT(kNodoRaiz) << std::endl;
    std::cout << "real.second: " << solucion_destino_tras_swap.calcularTCT(kNodoRaiz) << std::endl;
    exit(1);
  }
  return tct_ambas_maquinas;
}