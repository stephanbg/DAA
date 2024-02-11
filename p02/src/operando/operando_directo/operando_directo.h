/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file operando_directo.h
 * @brief Definición de la clase OperandoDirecto derivada de Operando, que representa cuando un
 *        operando es directo, es decir, cuando se accede a un registro ese es el valor.
 * 
 * @see {@link https://docs.google.com/document/d/1n6iua2wSG2UVns-mTA4YdMBVKfKIazkJi4HRzKVKS78/edit}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p02}
 */

#pragma once

#include "../operando.h"

/**
 * @brief Clase OperandoDirecto derivada de Operando, para los operandos directos
 */
class OperandoDirecto : public Operando {
 public:
  virtual bool compruebaPatron(const std::string&) const override;
  virtual const long double get_valor(const Instruccion&, const MemoriaDatos&, const long double) const override;
};