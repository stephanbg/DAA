/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 1 de Abril de 2024
 * @file ejecutar_algoritmos.h
 * @brief Definición de la función que se encarga de ejecutar cualquier algoritmo
 * para minimizar el TCT
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07/src}
 */

#pragma once

#include <functional> // Para std::function
#include <utility>    // Para std::move

#include "../solucion/solucion.h"
#include "../problema/problema.h"
#include "../algoritmos_min_TCT/algoritmos_min_TCT.h"
#include "../controlador_tiempo/controlador_tiempo.h"

std::pair<std::vector<Solucion>, int> ejecutarAlgoritmo(AlgoritmoMinimizarTCT*, int, Problema&);