/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 13 de Febrero de 2024
 * @file debug_1.h
 * @brief Definición de la clase Debug1, clase derivada de la
 *        clase virtual puro Debug, utilizada para representar
 *        a la opción 1 del debugger.
 * 
 * @see {@link https://docs.google.com/document/d/1zf_w2HtS4zJX3iqr9yPm6f7rRNsrBxL7afCsMapujMQ/edit#heading=h.5bq8rsdy1ujx}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p03}
 */

#pragma once

#include "debug.h"

/**
 * @brief Clase Debug1, clase derivada de la
 *        clase virtual puro Debug, utilizada para representar
 *        a la opción 1 del debugger.
 */
class Debug1 : public Debug {
 public:  
  virtual void InfoDuranteEjecucion(const MemoriaDatos&, const CintaIn&,
                                    const CintaOut&, const int,
                                    const std::vector<std::string>&) const override {}
};