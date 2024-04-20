/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 19 de Abril de 2024
 * @file ejecutar_algoritmos.h
 * @brief Definición de la función que se encarga de ejecutar cualquier algoritmo
 * para maximizar la diversidad
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p08/src}
 */

#pragma once

#include <functional>
#include <utility>

#include "../solucion/solucion.h"
#include "../problema/problema.h"
#include "../algoritmosDiversidadMaxima/algoritmosDiversidadMaxima.h"
#include "../controlador_tiempo/controlador_tiempo.h"

std::pair<Solucion, int> ejecutarAlgoritmo(AlgoritmosDiversidadMaxima*, Problema&, int);