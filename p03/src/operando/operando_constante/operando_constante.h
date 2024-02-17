/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file operando_constante.h
 * @brief Definición de la clase OperandoConstante derivada de Operando, que representa cuando un
 *        operando es constante.
 * 
 * @see {@link https://docs.google.com/document/d/1zf_w2HtS4zJX3iqr9yPm6f7rRNsrBxL7afCsMapujMQ/edit#heading=h.5bq8rsdy1ujx}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p03}
 */

#pragma once

#include "../operando.h"

/**
 * @brief Clase OperandoConstante derivada de Operando, para los operandos constantes
 */
class OperandoConstante : public Operando {
 public:
  virtual bool compruebaPatron(const std::string&) const override;
  virtual const long double get_registro_o_valor(const Instruccion&, const MemoriaDatos&) const override;
};