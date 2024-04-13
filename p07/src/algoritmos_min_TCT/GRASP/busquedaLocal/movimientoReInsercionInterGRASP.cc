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
 * la clase GRASP, para realizar una búsqueda local de reinserción entre máquinas
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07/src}
 */

#include "movimientoReInsercionInterGRASP.h"

/**
 * @brief Realiza una búsqueda local para mejorar una solución actual
 * mediante movimientos de re-inserción inter-máquinas.
 * 
 * @param kSolucionActual La solución actual que se va a mejorar.
 * @param kNodoRaiz El nodo raíz del problema.
 * @return Una nueva solución mejorada después de aplicar la búsqueda local.
 */
const std::vector<Solucion> MovimientoReInsercionInterGRASP::busquedaLocal(
  const std::vector<Solucion>& kSolucionActual,
  const Nodo* kNodoRaiz
) const {
  std::vector<Solucion> solucion_vecina, solucion_mejor = kSolucionActual;
  Solucion solucion_vecina_anterior;
  const int kNumMaquinas = kSolucionActual.size();
  int funcion_objetivo_inicial = Solucion::getFuncionObjetivo(),
  funcion_objetivo = funcion_objetivo_inicial, funcion_objetivo_vecino = 0;
  for (int i = 0; i < kNumMaquinas; ++i) { // Recorre todas las máquinas
    const int kTctMaquinaI = kSolucionActual[i].getTCT();
    const int kNumTareasI = kSolucionActual[i].getTareas().size();
    for (int j = 0; j < kNumTareasI; ++j) { // Recorro cada tarea que voy a mover
      Solucion copia_solucion_sin_elemento = kSolucionActual[i];
      copia_solucion_sin_elemento.setTareas().erase(copia_solucion_sin_elemento.setTareas().begin() + j);
      // Si es menos que la mitad hago el cálculo parcial sino el entero
      int tct_tras_eliminar_en_maquina_i = 0;
      if (copia_solucion_sin_elemento.getTareas().size() != 0) {
        tct_tras_eliminar_en_maquina_i = (j < (kSolucionActual.size() / 2)) ?
          calcularTCTParcialMaquina1AntesDeExtraerRealmente(kNodoRaiz, j, kSolucionActual[i]) :
          copia_solucion_sin_elemento.calcularTCT(kNodoRaiz);
      }
      for (int l = 0; l < kNumMaquinas; ++l) { // Recorro las máquinas siguientes
        if (i == l) continue;
        const int kNumTareasL = kSolucionActual[l].getTareas().size();
        for (int k = 0; k <= kNumTareasL; ++k) { // Recorro cada posición de la máquina siguiente
          solucion_vecina = kSolucionActual;
          const int kTctMaquinaL = solucion_vecina[l].getTCT();
          solucion_vecina[i].moverTareaEntreMaquinas(j, k, solucion_vecina[l]);
          int tct_tras_insertar_en_maquina_l = 0;
          if (solucion_vecina[l].getTareas().size() != 0) {
            // Si es menos que la mitad hago el cálculo parcial sino el entero
            tct_tras_insertar_en_maquina_l = (k < (solucion_vecina[l].getTareas().size() / 2)) ?
              calcularTCTParcialMaquina2DespuesDeExtraer(kNodoRaiz, k, solucion_vecina[l]) :
              solucion_vecina[l].calcularTCT(kNodoRaiz);
          }
          funcion_objetivo_vecino = (
            funcion_objetivo_inicial - kTctMaquinaI - kTctMaquinaL + tct_tras_eliminar_en_maquina_i + tct_tras_insertar_en_maquina_l
          );
          if (funcion_objetivo_vecino < funcion_objetivo) {
            solucion_mejor = solucion_vecina;
            solucion_mejor[i].setTCT() = tct_tras_eliminar_en_maquina_i;
            solucion_mejor[l].setTCT() = tct_tras_insertar_en_maquina_l;
            funcion_objetivo = funcion_objetivo_vecino;
          }
        }
      }
    }
  }
  Solucion::setFuncionObjetivo() = funcion_objetivo;
  return solucion_mejor;
}

/**
 * @brief Ejecuta una búsqueda local perturbando el entorno para mejorar la solución.
 * 
 * @param kSolucionAPerturbar La solución inicial que se va a perturbar.
 * @param kCantidadVecinosAMover El número de vecinos que se moverán durante la perturbación.
 * @param kNodoRaiz El nodo raíz del grafo.
 * @return Un vector de soluciones mejoradas después de la búsqueda local.
 */
const std::vector<Solucion> MovimientoReInsercionInterGRASP::busquedaLocalPerturbandoEntorno(
  const std::vector<Solucion>& kSolucionAPerturbar,
  const int kCantidadVecinosAMover,
  const Nodo* kNodoRaiz
) const {
  int funcion_objetivo = Solucion::getFuncionObjetivo();
  std::vector<Solucion> solucion_a_perturbar = kSolucionAPerturbar;
  std::random_device dispositivo_aleatorio;
  std::mt19937 generador(dispositivo_aleatorio());
  std::vector<const Nodo*> nodos_movidos;
  for (int i = 0; i < kCantidadVecinosAMover; ++i) { // Se recorro el número de vecinos a mover
    int indice_maquina_origen, indice_maquina_destino;
    do { // Se elije aleatoriamente una máquina origen (Tiene que tener m´nimo una tarea)
      std::uniform_int_distribution<> dis1(0, solucion_a_perturbar.size() - 1);
      indice_maquina_origen = dis1(generador);
    } while(solucion_a_perturbar[indice_maquina_origen].getTareas().size() == 0);
    do { // Se elije aleatoriamente una máquina destino (No puede ser la máquina origen)
      std::uniform_int_distribution<> dis2(0, solucion_a_perturbar.size() - 1);
      indice_maquina_destino = dis2(generador);      
    } while (indice_maquina_origen == indice_maquina_destino);
    int indice_tarea;
    std::vector<const Nodo *>::iterator it;
    do { // Se elije aleatoriamente una tarea a mover (No puede haber sido movida previamente)
      std::uniform_int_distribution<> dis3(0, solucion_a_perturbar[indice_maquina_origen].getTareas().size() - 1);
      indice_tarea = dis3(generador);
      it = std::find(nodos_movidos.begin(), nodos_movidos.end(), solucion_a_perturbar[indice_maquina_origen].getTareas()[indice_tarea]);
    } while (it != nodos_movidos.end());
    std::uniform_int_distribution<> dis4(0, solucion_a_perturbar[indice_maquina_destino].getTareas().size());
    const int kPosDestino = dis4(generador); // Se elije donde insertar   
    nodos_movidos.push_back(solucion_a_perturbar[indice_maquina_origen].getTareas()[indice_tarea]);
    // Eliminar de la función objetivo lo que se va a modificar
    funcion_objetivo =
        funcion_objetivo - solucion_a_perturbar[indice_maquina_origen].getTCT() - solucion_a_perturbar[indice_maquina_destino].getTCT();
    // CÁLCULO TCT PARCIAL MÁQUINA ORIGEN
    Solucion copia_solucion_sin_elemento = solucion_a_perturbar[indice_maquina_origen];  
    copia_solucion_sin_elemento.setTareas().erase(copia_solucion_sin_elemento.setTareas().begin() + indice_tarea);
    int tct_tras_eliminar_en_maquina_origen = 0;
    if (copia_solucion_sin_elemento.getTareas().size() != 0) {      
    // Si es menos que la mitad hago el cálculo parcial sino el entero
    tct_tras_eliminar_en_maquina_origen = (indice_maquina_origen < (solucion_a_perturbar.size() / 2)) ?
      calcularTCTParcialMaquina1AntesDeExtraerRealmente(
        kNodoRaiz, indice_tarea, solucion_a_perturbar[indice_maquina_origen]
      ) : copia_solucion_sin_elemento.calcularTCT(kNodoRaiz);
    }
    // Mover tarea entre máquinas
    solucion_a_perturbar[indice_maquina_origen].moverTareaEntreMaquinas(
      indice_tarea, kPosDestino, solucion_a_perturbar[indice_maquina_destino]
    );
    solucion_a_perturbar[indice_maquina_origen].setTCT() = tct_tras_eliminar_en_maquina_origen;
    // CÁLCULO TCT PARCIAL MÁQUINA DESTINO
    const int kTctTrasInsertarEnMaquinaDestino = (
      kPosDestino < (solucion_a_perturbar[indice_maquina_destino].getTareas().size() / 2)
    ) ? calcularTCTParcialMaquina2DespuesDeExtraer(kNodoRaiz, kPosDestino, solucion_a_perturbar[indice_maquina_destino]):
        solucion_a_perturbar[indice_maquina_destino].calcularTCT(kNodoRaiz);
    solucion_a_perturbar[indice_maquina_destino].setTCT() = kTctTrasInsertarEnMaquinaDestino;
    funcion_objetivo += tct_tras_eliminar_en_maquina_origen + kTctTrasInsertarEnMaquinaDestino;
  }
  Solucion::setFuncionObjetivo() = funcion_objetivo;
  return busquedaLocal(solucion_a_perturbar, kNodoRaiz); // Realizar la búsqueda local a la solución perturbada
}

/** EVALUACIÓN DEL MOVIMIENTO
 * 
 * @brief Calcula el tiempo de ciclo total (TCT) parcial de la máquina
 * en la que se ha eliminado una tarea.
 * 
 * @param kNodoRaiz El nodo raíz del problema.
 * @param kPosTareaOrg La posición de la tarea eliminada.
 * @param kSolucionActual La solución antes de eliminar la tarea.
 * @return El nuevo valor del TCT parcial después de eliminar la tarea.
 */
const int MovimientoReInsercionInterGRASP::calcularTCTParcialMaquina1AntesDeExtraerRealmente(
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

/** EVALUACIÓN DEL MOVIMIENTO
 * 
 * @brief Calcula el tiempo de ciclo total (TCT) parcial de la máquina
 * en la que se ha insertado una tarea.
 * 
 * @param kNodoRaiz El nodo raíz del problema.
 * @param kPosTareaDst La posición en la que se ha insertado la tarea.
 * @param kSolucionTrasInsercion La solución después de insertar la tarea.
 * @return El nuevo valor del TCT parcial después de insertar la tarea.
 */
const int MovimientoReInsercionInterGRASP::calcularTCTParcialMaquina2DespuesDeExtraer(
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