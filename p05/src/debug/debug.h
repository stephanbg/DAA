/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 6 de Marzo de 2024
 * @file debug.h
 * @brief Definición de la clase Debug, que servirá
 * de clase base abstracta para los diferentes modos debug que hayan
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p05/src}
 * @see {@link https://docs.google.com/document/d/1pwPk5iI5dRHo8M-raauPP5mgCUHy9m9j_au3UDkn_Rc/edit}
 */

#pragma once

#include <iostream>
#include <set>
#include <array>
#include <stack>

#include "../framework/algoritmoDyV.h"
#include "../framework/algoritmoDyVAccion.h"
#include "../algoritmos-DyV/mergesort.h"
#include "../algoritmos-DyV/quicksort.h"
#include "../algoritmos-DyV/busqueda_binaria.h"
#include "../algoritmos-DyV/hanoi.h"
#include "../algoritmos-DyV/strassen.h"
#include "../problema/problema.h"
#include "../problema/problema-vectorial.h"
#include "../problema/problema-vector-pilas.h"
#include "../problema/problema-vector-matricial.h"
#include "../solucion/solucion.h"
#include "../solucion/solucion-vectorial.h"
#include "../solucion/solucion-matricial.h"
#include "../solucion/solucion-integer.h"
#include "../solucion/solucion-pila.h"
#include "../calculos/calculos.h"
#include "../tablaAlgoritmos/tablaAlgoritmos.h"
#include "../introducirDatosEnConjunto/introducirDatosEnConjunto.h"
#include "../funcionesNecesarias/funcionesNecesarias.h"

/**
 * @brief Clase Debug, clase base abstracta
 * que define los diferentes modos de depuración
 */
class Debug {
 public:
  static Debug* crearModo();
  virtual void ejecutar(TablaAlgoritmos&) const = 0;
  virtual ~Debug() {}
 protected:
  const std::string eleccionDeAlgoritmo() const;
};