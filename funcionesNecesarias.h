#pragma once

#include <chrono>
#include <fstream>

#include "matriz.h"
#include "multiplicarMatriz.h"
#include "multiplicarPorFilas.h"
#include "multiplicarPorColumnas.h"
#include "comprobarFilasYColumnas.h"

double medirTiempoEjecucion(const MultiplicarMatriz&, const Matriz&, const Matriz&);
void crearDatosParaMeterEnFichero(const Matriz&, Matriz&, double&, double&, Matriz&, Matriz&);
void meterEnFichero(const Matriz&, const Matriz&, const double, const double, const Matriz&, const Matriz&);