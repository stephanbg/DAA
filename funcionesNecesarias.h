#pragma once

#include <fstream>
#include <cstdlib>  // Para rand() y srand()
#include <chrono> // Añadir esta línea para incluir la cabecera chrono

#include "matriz.h"
#include "multiplicarMatriz.h"
#include "multiplicarPorFilas.h"
#include "multiplicarPorColumnas.h"
#include "comprobarFilasYColumnas.h"

double medirTiempoEjecucion(const MultiplicarMatriz&, const Matriz&, const Matriz&);
void crearDatosParaMeterEnFichero(const Matriz&, Matriz&, double&, double&, Matriz&, Matriz&);
void meterEnFichero(const Matriz&, const Matriz&, const double, const double, const Matriz&, const Matriz&);
void generarSemillaRand();
int generarNumerosAleatorias();