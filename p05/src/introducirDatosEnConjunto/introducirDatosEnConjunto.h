/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 6 de Marzo de 2024
 * @file introducirDatosEnConjunto.h
 * @brief Definición de funciones que meten datos en conjuntos, para
 * su posterior evaluación
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p05/src}
 * @see {@link https://docs.google.com/document/d/1pwPk5iI5dRHo8M-raauPP5mgCUHy9m9j_au3UDkn_Rc/edit}
 */

#pragma once

#include <set>
#include <string>

#include "../problema/problema.h"
#include "../problema/problema-vectorial.h"
#include "../problema/problema-vector-pilas.h"
#include "../problema/problema-vector-matricial.h"
#include "../funcionesNecesarias/funcionesNecesarias.h"

void introducirDatosRandEnConjunto(std::set<void*>&, const std::string&);