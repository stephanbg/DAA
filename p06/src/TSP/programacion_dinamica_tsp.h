/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Marzo de 2024
 * @file programacion_dinamica_tsp.h
 * @brief Definición de la clase ProgramacionDinamicaTSP que hereda de la clase TSP
 * para resolver dicho problema
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p06/src}
 * @see {@link https://docs.google.com/document/d/1a691HPtHQL4qBtI2qaTMTp23wxZvU8-CCIbGOyNJRQo/edit}
 */

#pragma once

#include <cmath>
#include <algorithm>

#include "tsp.h"
#include "../funciones/peticionesUsuario.h"

/**
 * @brief Clase que implementa el algoritmo de Programación Dinámica para resolver el Problema del
 * Viajante de Comercio (TSP).
 * 
 * Esta clase hereda de la clase base TSP y proporciona la funcionalidad para ejecutar
 * el algoritmo de Programación Dinámica, mostrar el camino mínimo encontrado y
 * mostrar el tiempo de ejecución.
 */
class ProgramacionDinamicaTSP: public TSP {
 public:
  virtual void ejecutar(const GrafoNoDirigidoCompleto&) override;
  virtual void mostrarCaminoMinimo() const override;
  virtual void mostrarTiempoEjecución() const override;
 protected:
  std::vector<std::vector<int>> inicializarDistanciasVecinos(const std::vector<Nodo*>&, const int);
  std::vector<std::vector<int>> inicializarVectores(const int); 
  void reconstruirCaminoMinimo(
    const std::vector<Nodo*>,
    const std::vector<std::vector<int>>&,
    const std::chrono::high_resolution_clock::time_point&
  );
  int HeldKarp(
    const std::vector<std::vector<int>>&,
    const int, const int,
    std::vector<std::vector<int>>&,
    std::vector<std::vector<int>>&,
    const std::chrono::high_resolution_clock::time_point&
  );
};