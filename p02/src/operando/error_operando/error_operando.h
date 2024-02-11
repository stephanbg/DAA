/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file error_operando.h
 * @brief Definición de la clase ErrorOperando derivada de Operando, que representa cuando un
 *        operando es erróneo.
 * 
 * @see {@link https://docs.google.com/document/d/1n6iua2wSG2UVns-mTA4YdMBVKfKIazkJi4HRzKVKS78/edit}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p02}
 */

#pragma once

#include "../operando.h"

/**
 * @brief Clase ErrorOperando derivada de Operando, para los operandos erróneos
 */
class ErrorOperando : public Operando {
 public:
  // El patrón siempre es falso 
  virtual bool compruebaPatron(const std::string&) const override { return false; }
  // No se puede obtener ningún valor si no hay que leer ni escribir.
  virtual const long double get_valor(const Instruccion&, const MemoriaDatos&, const long double) const { 
    const std::string kErrorLecturaEscritura = "Este operador no es de escritura, ni de lectura.";
    throw (kErrorLecturaEscritura);
    return EXIT_FAILURE; // Por si no es escritura ni lectura
  }
};