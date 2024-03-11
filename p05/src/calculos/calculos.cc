/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 6 de Marzo de 2024
 * @file calculos.h
 * @brief Implementación de funciones, para simplificar el cálculo
 * de los algoritmos de DyV. Solamente llaman internamente a los algoritmos
 * de DyV para resolver los problemas y calculan los tiempos
 * que se tardan.
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p05/src}
 * @see {@link https://docs.google.com/document/d/1pwPk5iI5dRHo8M-raauPP5mgCUHy9m9j_au3UDkn_Rc/edit}
 */

#ifndef CALCULOS_CC
#define CALCULOS_CC

#include "calculos.h"

/**
 * @brief Resuelve el problema con el algoritmo MergeSort y
 * calcula el tiempo de ejecución del algoritmo MergeSort
 * para resolver un problema dado.
 * @tparam TipoProblema Tipo de datos del problema.
 * @tparam TipoSolucion Tipo de datos de la solución.
 * @param kMergeSort Instancia del algoritmo MergeSort.
 * @param kCadaProblema Problema a resolver.
 * @param cada_solucion Referencia al puntero que contendrá la solución obtenida.
 * @param tiempos_por_instancia Vector donde se almacenarán los tiempos de ejecución.
 * @param nombres_algoritmos Vector donde se almacenarán los nombres de los algoritmos.
 */
template<typename TipoProblema, typename TipoSolucion>
void calcularMergeSort(
    const AlgoritmoDyV<TipoProblema, TipoSolucion>* kMergeSort,
    const Problema<TipoProblema>* kCadaProblema,
    Solucion<TipoSolucion>*& cada_solucion,
    std::vector<double>& tiempos_por_instancia,
    std::vector<std::string>& nombres_algoritmos
) {
  const auto kInicioTiempo = std::chrono::steady_clock::now();
  cada_solucion = kMergeSort->Solve(kCadaProblema, kCadaProblema->getProblema().size());
  const auto kFinTiempo = std::chrono::steady_clock::now();
  const auto kDuracion = std::chrono::duration_cast<std::chrono::microseconds>(kFinTiempo - kInicioTiempo);
  tiempos_por_instancia.push_back(kDuracion.count());
  nombres_algoritmos.push_back("MergeSort");  
}

/**
 * @brief Resuelve el problema con el algoritmo QuickSort y
 * calcula el tiempo de ejecución del algoritmo QuickSort
 * para resolver un problema dado.
 * @tparam TipoProblema Tipo de datos del problema.
 * @tparam TipoSolucion Tipo de datos de la solución.
 * @param kQuicksort Instancia del algoritmo QuickSort.
 * @param kCadaProblema Problema a resolver.
 * @param cada_solucion Referencia al puntero que contendrá la solución obtenida.
 * @param tiempos_por_instancia Vector donde se almacenarán los tiempos de ejecución.
 * @param nombres_algoritmos Vector donde se almacenarán los nombres de los algoritmos.
 */
template<typename TipoProblema, typename TipoSolucion>
void calcularQuickSort(
    const AlgoritmoDyV<TipoProblema, TipoSolucion>* kQuicksort,
    const Problema<TipoProblema>* kCadaProblema,
    Solucion<TipoSolucion>*& cada_solucion,
    std::vector<double>& tiempos_por_instancia,
    std::vector<std::string>& nombres_algoritmos
) {
  const auto kInicioTiempo = std::chrono::steady_clock::now();
  cada_solucion = kQuicksort->Solve(kCadaProblema, kCadaProblema->getProblema().size());
  const auto kFinTiempo = std::chrono::steady_clock::now();
  const auto kDuracion = std::chrono::duration_cast<std::chrono::microseconds>(kFinTiempo - kInicioTiempo);
  tiempos_por_instancia.push_back(kDuracion.count());
  nombres_algoritmos.push_back("QuickSort"); 
}

/**
 * @brief Resuelve el problema con el algoritmo BusquedaBinaria y
 * calcula el tiempo de ejecución del algoritmo BusquedaBinaria
 * para resolver un problema dado.
 * @tparam TipoProblema Tipo de datos del problema.
 * @tparam TipoSolucion Tipo de datos de la solución.
 * @param kBusquedaBinaria Instancia del algoritmo BusquedaBinaria.
 * @param kCadaProblema Problema a resolver.
 * @param cada_solucion Referencia al puntero que contendrá la solución obtenida.
 * @param tiempos_por_instancia Vector donde se almacenarán los tiempos de ejecución.
 * @param nombres_algoritmos Vector donde se almacenarán los nombres de los algoritmos.
 */
template<typename TipoProblema, typename TipoSolucion>
void calcularBusquedaBinaria(
    const AlgoritmoDyV<TipoProblema, TipoSolucion>* kBusquedaBinaria,
    const Problema<TipoProblema>* kCadaProblema,
    Solucion<TipoSolucion>*& cada_solucion,
    std::vector<double>& tiempos_por_instancia,
    std::vector<std::string>& nombres_algoritmos
) {
  const auto kInicioTiempo = std::chrono::steady_clock::now();
  cada_solucion = kBusquedaBinaria->Solve(kCadaProblema, kCadaProblema->getProblema().size());
  const auto kFinTiempo = std::chrono::steady_clock::now();
  const auto kDuracion = std::chrono::duration_cast<std::chrono::microseconds>(kFinTiempo - kInicioTiempo);
  tiempos_por_instancia.push_back(kDuracion.count());
  nombres_algoritmos.push_back("BusquedaBinaria"); 
}

/**
 * @brief Resuelve el problema con el algoritmo Hanoi y
 * calcula el tiempo de ejecución del algoritmo Hanoi
 * para resolver un problema dado.
 * @tparam TipoProblema Tipo de datos del problema.
 * @tparam TipoSolucion Tipo de datos de la solución.
 * @param kHanoi Instancia del algoritmo Hanoi.
 * @param kCadaProblema Problema a resolver.
 * @param cada_solucion Referencia al puntero que contendrá la solución obtenida.
 * @param tiempos_por_instancia Vector donde se almacenarán los tiempos de ejecución.
 * @param nombres_algoritmos Vector donde se almacenarán los nombres de los algoritmos.
 */
template<typename TipoProblema, typename TipoSolucion>
void calcularHanoi(
    const AlgoritmoDyVAccion<TipoProblema, TipoSolucion>* kHanoi,
    const Problema<TipoProblema>* kCadaProblema,
    Solucion<TipoSolucion>*& cada_solucion,
    std::vector<double>& tiempos_por_instancia,
    std::vector<std::string>& nombres_algoritmos
) {
  const auto kInicioTiempo = std::chrono::steady_clock::now();
  cada_solucion = kHanoi->Solve(kCadaProblema, kCadaProblema->getProblema()[0].size());
  const auto kFinTiempo = std::chrono::steady_clock::now();
  const auto kDuracion = std::chrono::duration_cast<std::chrono::microseconds>(kFinTiempo - kInicioTiempo);
  tiempos_por_instancia.push_back(kDuracion.count());
  nombres_algoritmos.push_back("Hanoi"); 
}

#endif