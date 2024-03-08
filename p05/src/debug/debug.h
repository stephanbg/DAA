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

// Definición de códigos de colores ANSI
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"

class Debug{
 public:
  static Debug* crearModo();
  virtual void ejecutar(TablaAlgoritmos&) const = 0;
  virtual ~Debug() {}
 protected:
  const std::string eleccionDeAlgoritmo() const;
};