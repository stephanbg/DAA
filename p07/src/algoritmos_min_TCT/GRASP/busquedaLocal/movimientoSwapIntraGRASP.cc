/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 1 de Abril de 2024
 * @file movimientoSwapIntraGRASP.cc
 * @brief Implementación de la clase MovimientoSwapIntraGRASP que hereda de
 * la clase GRASP, para realizar una búsqueda local de intercambio intra-máquina
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07/src}
 */

#include "movimientoSwapIntraGRASP.h"

/**
 * @brief Realiza una búsqueda local para mejorar una solución actual
 * mediante movimientos de intercambio intra-máquinas.
 * 
 * @param kSolucionActual La solución actual que se va a mejorar.
 * @param kNodoRaiz El nodo raíz del problema.
 * @return Una nueva solución mejorada después de aplicar la búsqueda local.
 */
const std::vector<Solucion> MovimientoSwapIntraGRASP::busquedaLocal(
  const std::vector<Solucion>& kSolucionActual,
  const Nodo* kNodoRaiz
) const {
  std::vector<Solucion> solucion_vecina, solucion_mejor = kSolucionActual;
  Solucion solucion_vecina_anterior;
  const int kNumMaquinas = kSolucionActual.size();
  int funcion_objetivo_inicial = Solucion::getFuncionObjetivo(),
  funcion_objetivo = funcion_objetivo_inicial, funcion_objetivo_vecino = 0;
  for (int i = 0; i < kNumMaquinas; ++i) { // Recorro cada máquina
    const int kTctMaquinaI = kSolucionActual[i].getTCT();
    const int kNumTareas = kSolucionActual[i].getTareas().size();
    for (int j = 0; j < kNumTareas; ++j) { // Recorro cada tarea
      for (int k = j + 1; k < kNumTareas; ++k) { // Recorro a partir de la siguiente tarea para swap
        solucion_vecina = kSolucionActual;
        solucion_vecina[i].swapTarea(j, k);
        const int kTctVecinoI = calcularTCTParcial(kNodoRaiz, j, k, kSolucionActual[i], solucion_vecina[i]);
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

/** EVALUACIÓN DEL MOVIMIENTO
 * 
 * @brief Calcula el tiempo de ciclo total (TCT) parcial de la máquina
 * después de realizar un swap entre tareas.
 * 
 * @param kNodoRaiz El nodo raíz del problema.
 * @param kPosOrigen La posición de la tarea original en la solución actual.
 * @param kPosDestino La posición de la tarea destino después del swap.
 * @param kSolucionActual La solución antes de realizar el swap.
 * @param solucion_tras_swap La solución después de realizar el swap.
 * @return El nuevo valor del TCT parcial después de realizar el swap.
 */
const int MovimientoSwapIntraGRASP::calcularTCTParcial(
  const Nodo* kNodoRaiz,
  const int kPosOrigen,
  const int kPosDestino,
  const Solucion& kSolucionActual,
  Solucion& solucion_tras_swap 
) const {
  int tct = kSolucionActual.getTCT();
  const std::vector<const Nodo*> kTareasActual = kSolucionActual.getTareas();
  const std::vector<const Nodo*> kTareasSiguientes = solucion_tras_swap.getTareas();
  const int kNumTareas = kTareasActual.size(),
  kNumTareasMenosPosOrigen = kNumTareas - kPosOrigen, // Factores k
  kNumTareasMenosPosDestino = kNumTareas - kPosDestino;
  if (kPosOrigen == 0) { // Si es primera tarea restar/sumar enlace de nodo raíz con nodo origen y destino
    tct -= kNumTareas * kNodoRaiz->getCosteHaciaVecino(kTareasActual[kPosOrigen]);
    tct += kNumTareas * kNodoRaiz->getCosteHaciaVecino(kTareasSiguientes[kPosOrigen]);   
  } else { // Si es cualquier tarea distinta de la primera restar/sumar enlace del nodo de antes con nodo origen y destino
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
  solucion_tras_swap.setTCT() = tct;
  return tct;
}