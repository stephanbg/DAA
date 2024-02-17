/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file error_tipo.h
 * @brief Definición de la clase ErrorTipo derivada de la clase abstracta Operacion, que se
 *        encargará de validar si la instrucción es válida, como es un error de tipo nunca será válida
 *        por lo que tampoco se ejcutará.
 * 
 * @see {@link https://docs.google.com/document/d/1zf_w2HtS4zJX3iqr9yPm6f7rRNsrBxL7afCsMapujMQ/edit#heading=h.5bq8rsdy1ujx}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p03}
 */

#pragma once

#include "../operacion.h"

/**
 * @brief Clase ErrorTipo derivada de Operacion, se encargará de decir que dicha instrucción,
 *        es decir, instancia de esta clase, no es válida
 */
class ErrorTipo : public Operacion {
 public:
  // La validación siempre es false
  bool ValidarInstruccion(const Instruccion&) const override { return false; }
  // No ejecuta
  void EjecutarInstruccion(const Instruccion&, MemoriaDatos&, CintaIn&, CintaOut&, int&) const override {}
};