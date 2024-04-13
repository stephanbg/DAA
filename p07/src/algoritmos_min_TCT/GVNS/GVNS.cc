/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 10 de Abril de 2024
 * @file GVNS.h
 * @brief Implementación de la clase GVNS que hereda de
 * la clase AlgoritmoMinimizarTCT, para realizar dicho algoritmo,
 * junto a sus dos fases de perturbación y VND para minimizar el TCT
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07/src}
 */

#include "GVNS.h"

/**
 * @brief Ejecuta el algoritmo GVNS para minimizar el TCT.
 * 
 * @param kNumeroMaquinas Número de máquinas disponibles.
 * @param kGrafo Problema representado como un grafo.
 * @param kIteracionesGRASP Número de iteraciones para el algoritmo GRASP (No se usa pero lo tiene la clase base).
 * @return Un vector de soluciones obtenidas por el algoritmo.
 */
const std::vector<Solucion> GVNS::ejecutar(
  const int kNumeroMaquinas,
  const Problema& kGrafo,
  const int kIteracionesGRASP
) {
  const Nodo* kNodoRaiz = kGrafo.getGrafo()[0];
  MovimientoReInsercionInterGRASP algoritmoGRASP;
  std::vector<Solucion> mejor_solucion =
      algoritmoGRASP.ejecutar(kNumeroMaquinas, kGrafo, 1), mejor_solucion_auxiliar;
  AlgoritmoGVNS(mejor_solucion, kNodoRaiz);
  int iteraciones = 0, mejor_funcion_objetivo = Solucion::getFuncionObjetivo(), funcion_objetivo_actual;
  while (++iteraciones < 3) {
    mejor_solucion_auxiliar = algoritmoGRASP.ejecutar(kNumeroMaquinas, kGrafo, 1);
    AlgoritmoGVNS(mejor_solucion_auxiliar, kNodoRaiz);
    funcion_objetivo_actual = Solucion::getFuncionObjetivo();
    if (funcion_objetivo_actual < mejor_funcion_objetivo) {
      mejor_solucion = mejor_solucion_auxiliar;
      mejor_funcion_objetivo = funcion_objetivo_actual;
    }
  }
  Solucion::setFuncionObjetivo() = mejor_funcion_objetivo;
  return mejor_solucion;
}

/**
 * @brief Implementa el algoritmo GVNS.
 * 
 * @param solucion_a_mejorar Solución a mejorar.
 * @param kNodoRaiz Nodo raíz del grafo.
 */
void GVNS::AlgoritmoGVNS(std::vector<Solucion>& solucion_a_mejorar, const Nodo* kNodoRaiz) const {
  const int kMAX = 6;
  int funcion_objetivo_inicial = Solucion::getFuncionObjetivo();
  std::vector<Solucion>& mejor_solucion_GVNS = solucion_a_mejorar;
  int contador = 0;
  for (int k = 1; k <= kMAX; ++k) {
    perturbacion(mejor_solucion_GVNS, k, kNodoRaiz);
    VND(mejor_solucion_GVNS, kNodoRaiz);
    if (Solucion::getFuncionObjetivo() < funcion_objetivo_inicial) {
      k = 1;
      funcion_objetivo_inicial = Solucion::getFuncionObjetivo();
    }
  }
  Solucion::setFuncionObjetivo() = funcion_objetivo_inicial;
}

/**
 * @brief Aplica una perturbación a las soluciones.
 * 
 * @param solucion_a_perturbar Solución a perturbar.
 * @param kCantidadVecinosAMover Cantidad de vecinos a mover en la perturbación.
 * @param kNodoRaiz Nodo raíz del grafo.
 */
void GVNS::perturbacion(
  std::vector<Solucion>& solucion_a_perturbar,
  const int kCantidadVecinosAMover,
  const Nodo* kNodoRaiz
) const {
  MovimientoReInsercionInterGRASP algoritmoParaPerturbarEntorno;
  solucion_a_perturbar = algoritmoParaPerturbarEntorno.busquedaLocalPerturbandoEntorno(
    solucion_a_perturbar, kCantidadVecinosAMover, kNodoRaiz
  );
}

/**
 * @brief Implementa la fase de VND.
 * 
 * @param solucion Solución a mejorar.
 * @param kNodoRaiz Nodo raíz del grafo.
 */
void GVNS::VND(std::vector<Solucion>& solucion, const Nodo* kNodoRaiz) const {
  int funcion_objetivo = Solucion::getFuncionObjetivo();
  MovimientoReInsercionInterGRASP algoritmoReInsercionInter;
  MovimientoSwapIntraGRASP algoritmoSwapIntra;
  MovimientoReInsercionIntraGRASP algoritmoReInsercionIntra;
  MovimientoSwapInterGRASP algoritmoSwapInter;
  std::vector<Solucion> solucion_aux_1, solucion_aux_2;
  do {
    do {
      do {
        // Primer entorno
        solucion_aux_1 = algoritmoReInsercionInter.busquedaLocal(
          solucion, kNodoRaiz
        );        
        funcion_objetivo = Solucion::getFuncionObjetivo();     
        // Segundo entorno
        solucion_aux_2 = algoritmoSwapIntra.busquedaLocal(
          solucion_aux_1, kNodoRaiz
        );
        if (Solucion::getFuncionObjetivo() < funcion_objetivo) solucion = solucion_aux_2;
      } while (Solucion::getFuncionObjetivo() < funcion_objetivo);
      solucion = solucion_aux_1;
      // Tercer entorno
      solucion_aux_2 = algoritmoReInsercionIntra.busquedaLocal(
        solucion, kNodoRaiz
      );   
      if (Solucion::getFuncionObjetivo() < funcion_objetivo) solucion = solucion_aux_2;
    } while (Solucion::getFuncionObjetivo() < funcion_objetivo);
      // Cuarto entorno
      solucion_aux_2 = algoritmoSwapInter.busquedaLocal(
        solucion, kNodoRaiz
      );
    if (Solucion::getFuncionObjetivo() < funcion_objetivo) solucion = solucion_aux_2;
  } while (Solucion::getFuncionObjetivo() < funcion_objetivo);
  Solucion::setFuncionObjetivo() = funcion_objetivo;
}