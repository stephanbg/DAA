/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 1 de Abril de 2024
 * @file movimientoReInsercionInterGRASP.cc
 * @brief Implementación de la clase MovimientoReInsercionInterGRASP que hereda de
 * la clase GRASP, para realizar una búsqueda local de reinserción en la misma máquina
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07/src}
 */

#include "movimientoReInsercionIntraGRASP.h"

/**
 * @brief Realiza una búsqueda local para mejorar una solución actual
 * mediante movimientos de re-inserción intra-máquinas.
 * 
 * @param kSolucionActual La solución actual que se va a mejorar.
 * @param kNodoRaiz El nodo raíz del problema.
 * @return Una nueva solución mejorada después de aplicar la búsqueda local.
 */
const std::vector<Solucion> MovimientoReInsercionIntraGRASP::busquedaLocal(
  const std::vector<Solucion>& kSolucionActual,
  const Nodo* kNodoRaiz
) const {
  std::vector<Solucion> solucion_vecina, solucion_mejor = kSolucionActual;
  Solucion solucion_vecina_anterior;
  const int kNumMaquinas = kSolucionActual.size();
  int funcion_objetivo_inicial = Solucion::getFuncionObjetivo(),
  funcion_objetivo = funcion_objetivo_inicial, funcion_objetivo_vecino = 0;
  for (int i = 0; i < kNumMaquinas; ++i) { // Se recorren las máquinas
    const int kTctMaquinaI = kSolucionActual[i].getTCT();
    const int kNumTareas = kSolucionActual[i].getTareas().size();
    for (int j = 0; j < kNumTareas; ++j) { // Se recorren las tareas
      solucion_vecina = kSolucionActual;
      for (int k = j + 1; k < kNumTareas; ++k) { // Posición a donde se mueve la tarea
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

/** EVALUACIÓN DEL MOVIMIENTO
 * 
 * @brief Calcula el tiempo de ciclo total (TCT) parcial después de
 * realizar un movimiento de re-inserción inter-máquinas.
 * 
 * @param kNodoRaiz El nodo raíz del problema.
 * @param kPosTareaOriginal La posición original de la tarea que se ha movido.
 * @param kPosTareaMovida La posición a la que se ha movido la tarea.
 * @param kSolucionAnterior La solución antes de realizar el movimiento.
 * @param solucion_tras_movimiento La solución después de realizar el movimiento.
 * @return El nuevo valor del TCT parcial después del movimiento.
 */
const int MovimientoReInsercionIntraGRASP::calcularTCTParcial(
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