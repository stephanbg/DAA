/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 27 de Febrero de 2024
 * @file calculos.h
 * @brief Definición de funciones, que se usarán en el main
 * para simplificarlo. Solamente llaman internamente a los métodos
 * de la clase AlgoritmoDyV para resolver los problemas y calculan los tiempos
 * que se tardan.
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p04/src}
 * @see {@link https://docs.google.com/document/d/1CcrG-85_oTdAkTo-zgXkudKT8C8z7T7m2hUHVLGUReQ/edit#heading=h.5bq8rsdy1ujx}
 */

#pragma once

#include <vector>
#include <string>
#include <chrono>

#include "../framework/algoritmoDyV.h"
#include "../problema/problema.h"
#include "../solucion/solucion.h"

// Todas las funciones que realizan los cálculos de los algoritmos
template<typename TipoProblema, typename TipoSolucion>
void calcularMergeSort(
    const AlgoritmoDyV<TipoProblema, TipoSolucion>*,
    const Problema<TipoProblema>*,
    Solucion<TipoSolucion>*&,
    std::vector<double>&,
    std::vector<std::string>&
);

template<typename TipoProblema, typename TipoSolucion>
void calcularQuickSort(
    const AlgoritmoDyV<TipoProblema, TipoSolucion>*,
    const Problema<TipoProblema>*,
    Solucion<TipoSolucion>*&,
    std::vector<double>&,
    std::vector<std::string>&
);

template<typename TipoProblema, typename TipoSolucion>
void calcularBusquedaBinaria(
    const AlgoritmoDyV<TipoProblema, TipoSolucion>*,
    const Problema<TipoProblema>*,
    Solucion<TipoSolucion>*&,
    std::vector<double>&,
    std::vector<std::string>&
);

#include "calculos.cc"