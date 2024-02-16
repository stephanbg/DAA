/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 13 de Febrero de 2024
 * @file debug_0.h
 * @brief Definición de la clase Debug0, clase derivada de la
 *        clase virtual puro Debug, utilizada para representar
 *        a la opción 0 del debugger.
 * 
 * @see {@link https://docs.google.com/document/d/1n6iua2wSG2UVns-mTA4YdMBVKfKIazkJi4HRzKVKS78/edit}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p02}
 */

#pragma once

#include "debug.h"

/**
 * @brief Clase Debug0, clase derivada de la
 *        clase virtual puro Debug, utilizada para representar
 *        a la opción 0 del debugger.
 */
class Debug0 : public Debug {
 public:
  virtual void MostrarNumeroInstruccionesEjecutadas(const int) const override {}
  virtual void InfoDuranteEjecucion(const Instruccion&, const MemoriaDatos&,
                                    const CintaIn&, const CintaOut&) const override {}
};