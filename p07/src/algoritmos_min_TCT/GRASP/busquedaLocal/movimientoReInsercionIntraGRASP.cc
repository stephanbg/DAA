#include "movimientoReInsercionIntraGRASP.h"

const std::vector<Solucion> MovimientoReInsercionIntraGRASP::busquedaLocal(
  const std::vector<Solucion>& kSolucionActual,
  const Nodo* kNodoRaiz
) const {
  std::vector<Solucion> solucion_vecina, solucion_mejor;
  Solucion solucion_vecina_anterior;
  const int kNumMaquinas = kSolucionActual.size();
  int funcion_objetivo_inicial = Solucion::getFuncionObjetivo(),
  funcion_objetivo = funcion_objetivo_inicial, funcion_objetivo_vecino = 0;
  for (int i = 0; i < kNumMaquinas - 1; ++i) {
    const int kTctMaquinaI = kSolucionActual[i].getTCT();
    const int kNumTareasI = kSolucionActual[i].getTareas().size();
    for (int j = 0; j < kNumTareasI; ++j) {
      Solucion copia_solucion_sin_elemento = kSolucionActual[i];
      copia_solucion_sin_elemento.setTareas().erase(copia_solucion_sin_elemento.setTareas().begin() + j);
      // Si es menos que la mitad hago el cálculo parcial sino el entero
      const int kTctTrasEliminarEnMaquinaI = (j < (kSolucionActual.size() / 2)) ?
          calcularTCTParcialMaquina1(kNodoRaiz, j, kSolucionActual[i]) :
          copia_solucion_sin_elemento.calcularTCT(kNodoRaiz);
      for (int l = i + 1; l < kNumMaquinas; ++l) {
        const int kNumTareasL = kSolucionActual[l].getTareas().size();
        for (int k = 0; k <= kNumTareasL; ++k) {
          solucion_vecina = kSolucionActual;
          const int kTctMaquinaL = solucion_vecina[l].getTCT();
          solucion_vecina[i].moverTareaEntreMaquinas(j, k, solucion_vecina[l]);
          // Si es menos que la mitad hago el cálculo parcial sino el entero
          const int kTctTrasInsertarEnMaquinaL = (k < (solucion_vecina[l].getTareas().size() / 2)) ?
              calcularTCTParcialMaquina2(kNodoRaiz, k, solucion_vecina[l]) :
              solucion_vecina[l].calcularTCT(kNodoRaiz);
          funcion_objetivo_vecino = (
            funcion_objetivo_inicial - kTctMaquinaI - kTctMaquinaL + kTctTrasEliminarEnMaquinaI + kTctTrasInsertarEnMaquinaL
          );
          if (funcion_objetivo_vecino < funcion_objetivo) {
            solucion_mejor = solucion_vecina;
            solucion_mejor[i].setTCT() = kTctTrasEliminarEnMaquinaI;
            solucion_mejor[l].setTCT() = kTctTrasInsertarEnMaquinaL;
            funcion_objetivo = funcion_objetivo_vecino;
          }
        }
      }
    }
  }
  Solucion::setFuncionObjetivo() = funcion_objetivo;
  return solucion_mejor;
}

const int MovimientoReInsercionIntraGRASP::calcularTCTParcialMaquina1(
  const Nodo* kNodoRaiz,
  const int kPosTareaOrg,
  const Solucion& kSolucionActual
) const {
  int tct = kSolucionActual.getTCT(); // Tct antes de eliminar tarea
  const std::vector<const Nodo*> kTareas = kSolucionActual.getTareas();
  const int kTareasAntes = kTareas.size(), kTareasDespues = kTareasAntes - 1;
  const int kNumPasos1 = kPosTareaOrg - 1; // Un paso menos porque no cuento el nodo raíz
  tct -= kTareasAntes * kNodoRaiz->getCosteHaciaVecino(kTareas[0]); // Resto del nodo raíz al primero
  // Si extraigo el primero resto de él al siguiente y luego sumo del raíz al siguiente
  if (kPosTareaOrg == 0) {
    tct -= (kTareasAntes - 1) * kTareas[0]->getCosteHaciaVecino(kTareas[1]);
    tct += kTareasDespues * kNodoRaiz->getCosteHaciaVecino(kTareas[1]); // Hago el nodo raíz
  } else {
    if (kPosTareaOrg < kTareasAntes - 1) { // Resto antes y después del nodo que extraigo y luego sumo el enlace que queda
      tct -= (kTareasAntes - kPosTareaOrg) * (kTareas[kPosTareaOrg - 1]->getCosteHaciaVecino(kTareas[kPosTareaOrg]));
      tct -= (kTareasAntes - kPosTareaOrg - 1) * (kTareas[kPosTareaOrg]->getCosteHaciaVecino(kTareas[kPosTareaOrg + 1]));
      tct += (kTareasDespues - kPosTareaOrg) * (kTareas[kPosTareaOrg - 1]->getCosteHaciaVecino(kTareas[kPosTareaOrg + 1]));  
      // Si extraigo el último solo resto del último al nodo que extraigo
    } else tct -= (kTareas[kPosTareaOrg - 1]->getCosteHaciaVecino(kTareas[kPosTareaOrg]));
    tct += kTareasDespues * kNodoRaiz->getCosteHaciaVecino(kTareas[0]); // Hago el nodo raíz al primero
  }
  for (int i = 1; i <= kNumPasos1; ++i) { // Hago lo común sin el nodo raíz y sin llegar al que extraigo
    tct -= (kTareasAntes - i) * (kTareas[i - 1]->getCosteHaciaVecino(kTareas[i]));
    tct += (kTareasDespues - i) * (kTareas[i - 1]->getCosteHaciaVecino(kTareas[i]));
  }
  return tct;
}

const int MovimientoReInsercionIntraGRASP::calcularTCTParcialMaquina2(
  const Nodo* kNodoRaiz,
  const int kPosTareaDst,
  const Solucion& kSolucionTrasInsercion
) const {
  int tct = kSolucionTrasInsercion.getTCT(); // Tct antes de insertar
  const std::vector<const Nodo*> kTareas = kSolucionTrasInsercion.getTareas();  
  const int kTareasDespues = kTareas.size(), kTareasAntes = kTareasDespues - 1;
  const int kNumPasos = kPosTareaDst - 1; // Un paso menos porque no cuento el nodo raíz
  tct += kTareasDespues * kNodoRaiz->getCosteHaciaVecino(kTareas[0]); // Hago del nodo raíz al primero
  // Si inserto en la primera pos resto de él raíz al siguiente y sumo del primero al siguiente
  if (kPosTareaDst == 0) {
    tct -= kTareasAntes * kNodoRaiz->getCosteHaciaVecino(kTareas[1]);
    tct += (kTareasDespues - 1) * kTareas[0]->getCosteHaciaVecino(kTareas[1]);
  } else {
    tct -= kTareasAntes * kNodoRaiz->getCosteHaciaVecino(kTareas[0]); // Resto del raíz al primero
    if (kPosTareaDst < kTareasDespues - 1) { // Resto lo que había y sumo de atrás al nodo insertado y de este al siguiente
      tct -= (kTareasAntes - kPosTareaDst) * (kTareas[kPosTareaDst - 1]->getCosteHaciaVecino(kTareas[kPosTareaDst + 1]));
      tct += (kTareasDespues - kPosTareaDst) * (kTareas[kPosTareaDst - 1]->getCosteHaciaVecino(kTareas[kPosTareaDst]));
      tct += (kTareasDespues - kPosTareaDst - 1) * (kTareas[kPosTareaDst]->getCosteHaciaVecino(kTareas[kPosTareaDst + 1]));
      // Solamente sumo del último al insertado
    } else tct += (kTareas[kPosTareaDst - 1]->getCosteHaciaVecino(kTareas[kPosTareaDst]));
  }
  for (int i = 1; i <= kNumPasos; ++i) { // Hago lo común sin el nodo raíz y sin llegar al que inserto
    tct -= (kTareasAntes - i) * (kTareas[i - 1]->getCosteHaciaVecino(kTareas[i]));
    tct += (kTareasDespues - i) * (kTareas[i - 1]->getCosteHaciaVecino(kTareas[i]));
  }
  return tct;
}