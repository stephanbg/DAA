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
 * @see {@link https://docs.google.com/document/d/1n6iua2wSG2UVns-mTA4YdMBVKfKIazkJi4HRzKVKS78/edit}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p02}
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