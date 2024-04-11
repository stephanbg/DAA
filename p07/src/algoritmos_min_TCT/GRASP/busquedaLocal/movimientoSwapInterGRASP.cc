/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 1 de Abril de 2024
 * @file movimientoSwapInterGRASP.cc
 * @brief Implementación de la clase MovimientoSwapInterGRASP que hereda de
 * la clase GRASP, para realizar una búsqueda local de intercambio inter-máquinas
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07/src}
 */

#include "movimientoSwapInterGRASP.h"

/**
 * @brief Realiza una búsqueda local para mejorar una solución actual
 * mediante movimientos de intercambio Inter-máquinas.
 * 
 * @param kSolucionActual La solución actual que se va a mejorar.
 * @param kNodoRaiz El nodo raíz del problema.
 * @return Una nueva solución mejorada después de aplicar la búsqueda local.
 */
const std::vector<Solucion> MovimientoSwapInterGRASP::busquedaLocal(
  const std::vector<Solucion>& kSolucionActual,
  const Nodo* kNodoRaiz
) const {
  std::vector<Solucion> solucion_vecina, solucion_mejor;
  Solucion solucion_vecina_anterior;
  const int kNumMaquinas = kSolucionActual.size();
  int funcion_objetivo_inicial = Solucion::getFuncionObjetivo(),
  funcion_objetivo = funcion_objetivo_inicial, funcion_objetivo_vecino = 0;
  for (int i = 0; i < kNumMaquinas - 1; ++i) { // Recorre todas las máquinas menos la última
    const int kTctMaquinaI = kSolucionActual[i].getTCT();
    const int kNumTareasI = kSolucionActual[i].getTareas().size();
    for (int j = 0; j < kNumTareasI; ++j) { // Recorro cada tarea que voy a intercambiar
      for (int l = i + 1; l < kNumMaquinas; ++l) { // Recorro las máquinas siguientes
        const int kNumTareasL = kSolucionActual[l].getTareas().size();      
        for (int k = 0; k < kNumTareasL; ++k) { // Recorro cada posición de la máquina siguiente
          solucion_vecina = kSolucionActual;
          const int kTctMaquinaL = solucion_vecina[l].getTCT();
          solucion_vecina[i].swapTareaEntreMaquinas(j, k, solucion_vecina[l]);
          const std::pair<int, int> kTctVecinoIL = calcularTCTParcial(
            kNodoRaiz, j, k, solucion_vecina[i], solucion_vecina[l]
          );
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

/** EVALUACIÓN DEL MOVIMIENTO
 * 
 * @brief Calcula los tiempos de ciclo total (TCT) parciales después de realizar
 * un swap Inter-máquinas.
 * 
 * @param kNodoRaiz El nodo raíz del problema.
 * @param kPosTareaSolucionOrigen La posición de la tarea original en la máquina origen.
 * @param kPosTareaSolucionDestino La posición de la tarea destino en la máquina destino después del swap.
 * @param solucion_origen_tras_swap La solución en la máquina origen después del swap.
 * @param solucion_destino_tras_swap La solución en la máquina destino después del swap.
 * @return Un par de enteros que representan los nuevos valores de los TCT parciales después del swap.
 */
const std::pair<int, int> MovimientoSwapInterGRASP::calcularTCTParcial(
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