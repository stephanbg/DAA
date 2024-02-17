/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file operando.h
 * @brief Definición de la clase abstracta Operando, que tendrá una serie de clases derivadas
 *        que sobreescribirán los métodos de comprobar patrón y obtener el valor para las oepraciones.
 * 
 * @see {@link https://docs.google.com/document/d/1zf_w2HtS4zJX3iqr9yPm6f7rRNsrBxL7afCsMapujMQ/edit#heading=h.5bq8rsdy1ujx}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p03}
 */

#pragma once

#include <regex>

#include "../memoria_datos/memoria_datos.h"
#include "../instruccion/instruccion.h"

/**
 * @brief Clase abstracta Operando que representa un operando en una instrucción.
 */
class Operando {
 public:
  virtual bool compruebaPatron(const std::string&) const = 0;
  virtual const long double get_registro_o_valor(const Instruccion&, const MemoriaDatos&) const = 0;
  virtual ~Operando() {} // Destructor virtual
};