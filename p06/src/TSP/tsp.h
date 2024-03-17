/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Marzo de 2024
 * @file tsp.h
 * @brief Definición de la clase abstracta TSP
 * que servirá de clase base para todos los tipso de algoritmos para resolver el TSP
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p06/src}
 * @see {@link https://docs.google.com/document/d/1a691HPtHQL4qBtI2qaTMTp23wxZvU8-CCIbGOyNJRQo/edit}
 */

#pragma once

#include <chrono>

#include "../grafo/grafoNoDirigidoCompleto.h"
#include "../controlTiempo/controlTiempo.h"

using Clock = std::chrono::high_resolution_clock;

/**
 * @brief Clase abstracta base para los algoritmos de resolución del Problema del Viajante de Comercio (TSP).
 * 
 * Esta clase define la interfaz común para los algoritmos que resuelven el Problema del Viajante de Comercio.
 * Proporciona métodos virtuales puros para ejecutar el algoritmo, mostrar el camino mínimo
 * y mostrar el tiempo de ejecución.
 */
class TSP {
 public:
  virtual void ejecutar(const GrafoNoDirigidoCompleto&) = 0;
  // Mostrar
  virtual void mostrarCaminoMinimo() const = 0;
  virtual void mostrarTiempoEjecución() const = 0;
  void mostrarCoste();
  // Getter
  const std::vector<const Nodo*>& getCaminoMinimo() const { return caminoMinimo_; }
  const long double getCoste() const { return coste_; }
  const long double getTiempoEjecución() const { return tiempoEjecucion_; }
 protected:
  std::vector<const Nodo*> caminoMinimo_;
  long double coste_;
  long double tiempoEjecucion_;
  const long double calcularCoste();
};