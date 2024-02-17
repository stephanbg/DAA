/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file operando_indirecto.h
 * @brief Definición de la clase OperandoIndirecto derivada de Operando, que representa cuando un
 *        operando es indirecto, es decir, cuando se accede a un registro, contiene otro registro,
 *        y ahí se encuentra el valor.
 * 
 * @see {@link https://docs.google.com/document/d/1zf_w2HtS4zJX3iqr9yPm6f7rRNsrBxL7afCsMapujMQ/edit#heading=h.5bq8rsdy1ujx}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p03}
 */

#pragma once

#include "../operando.h"

/**
 * @brief Clase OperandoIndirecto derivada de Operando, para los operandos indirectos
 */
class OperandoIndirecto : public Operando {
 public:
  virtual bool compruebaPatron(const std::string&) const override;
  virtual const long double get_registro_o_valor(const Instruccion&, const MemoriaDatos&) const override;
};