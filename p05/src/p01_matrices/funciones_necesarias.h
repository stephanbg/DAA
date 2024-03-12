/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 *
 * @author Stephan Brommer Gutiérrez
 * Correo: alu0101493497@ull.edu.es
 * @date 30/01/2024
 * @file funciones_necesarias.h
 * @brief Definición de funciones auxiliares que van a ser necesarias en el resto del programa
 * @see {@link https://github.com/stephanbg/DAA}
 *
 */

#pragma once

#include <fstream>
#include <cstdlib>
#include <chrono>

#include "matriz.h"
#include "multiplicar_matriz.h"
#include "multiplicar_por_filas.h"
#include "multiplicar_por_columnas.h"
#include "comprobar_filas_columnas.h"

double MedirTiempoEjecucion(const MultiplicarMatriz&, const Matriz&, const Matriz&);
void CrearDatosParaMeterEnFichero(const Matriz&, Matriz&, double&, double&, Matriz&, Matriz&);
void MeterEnFichero(const Matriz&, const Matriz&, const double, const double, const Matriz&, const Matriz&);
void IniciarSemilla();
int GenerarNumerosAleatorias();