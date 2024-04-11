/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 20 de Marzo de 2024
 * @file algoritmo_constructivo_voraz_TCT.h
 * @brief Definición de la clase AlgoritmoConstructivoVoraz que hereda de
 * la clase abstracta AlgoritmoMinimizarTCT para minimizar el TCT mediante un algoritmo Voraz
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07/src}
 */

#pragma once

#include <algorithm>
#include <numeric>   // Para std::iota

#include "../algoritmos_min_TCT.h"
#include "../../funciones/funciones.h"

/**
 * @brief Estructura que representa una tarea asignada a una máquina en una posición específica.
 */
struct TareaMaquinaPosicion {
  const Nodo* tarea;
  int indice_maquina;
  int posicion;
};

/**
 * @brief Clase que implementa un algoritmo constructivo voraz para minimizar el tiempo de completado total (TCT).
 */
class AlgoritmoConstructivoVoraz : public AlgoritmoMinimizarTCT {
 public:
  virtual const std::vector<Solucion> ejecutar(const int, const Problema&, const int kIteraciones = 100) override;
 private:
  void seleccionarTareasInciales(
    std::vector<Solucion>&, const Problema&, std::vector<int>&
  ) const;
  const TareaMaquinaPosicion obtenerTareaMaquinaPosicion(
    const int, std::vector<Solucion>&,
    const std::vector<int>&, const Problema&
  ) const;
};