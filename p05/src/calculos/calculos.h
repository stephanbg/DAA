/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 6 de Marzo de 2024
 * @file calculos.h
 * @brief Definición de funciones, para simplificar el cálculo
 * de los algoritmos de DyV. Solamente llaman internamente a los algoritmos
 * de DyV para resolver los problemas y calculan los tiempos
 * que se tardan.
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p05/src}
 * @see {@link https://docs.google.com/document/d/1pwPk5iI5dRHo8M-raauPP5mgCUHy9m9j_au3UDkn_Rc/edit}
 */

#pragma once

#include <vector>
#include <string>
#include <chrono>

#include "../framework/algoritmoDyV.h"
#include "../framework/algoritmoDyVAccion.h"
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

template<typename TipoProblema, typename TipoSolucion>
void calcularHanoi(
    const AlgoritmoDyVAccion<TipoProblema, TipoSolucion>*,
    const Problema<TipoProblema>*,
    Solucion<TipoSolucion>*&,
    std::vector<double>&,
    std::vector<std::string>&
);

#include "calculos.cc"