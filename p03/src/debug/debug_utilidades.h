/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 13 de Febrero de 2024
 * @file debug_utilidades.h
 * @brief Implementación de funciones utiles relacionadas con el debugger
 * 
 * @see {@link https://docs.google.com/document/d/1zf_w2HtS4zJX3iqr9yPm6f7rRNsrBxL7afCsMapujMQ/edit#heading=h.5bq8rsdy1ujx}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p03}
 */

#pragma once

#include "debug.h"
#include "debug_0.h"
#include "debug_1.h"
#include "debug_2.h"

/**
 * @brief Crea la opción del depurador dependiendo del parámetro.
 * 
 * @param kValorDebug el valor del depurador a establecer
 * @return Un puntero al objeto Debug, es decir, en tiempo de
 *         ejecución sabrá que tipo de Debug es.
 */
Debug* crear_debug(const std::string kValorDebug) {
  Debug* debugger;
  switch (std::stoi(kValorDebug)) {
    case 0: debugger = new Debug0(); break;
    case 1: debugger = new Debug1(); break;
    case 2: debugger = new Debug2(); break;
    default:  debugger = nullptr;
  }
  return debugger;
}