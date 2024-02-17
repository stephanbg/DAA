/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file instruccion.h
 * @brief Definición de la clase Instruccion, que contiene todos los detalles sobre una isntrucción
 * 
 * @see {@link https://docs.google.com/document/d/1zf_w2HtS4zJX3iqr9yPm6f7rRNsrBxL7afCsMapujMQ/edit#heading=h.5bq8rsdy1ujx}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p03}
 */

#pragma once

#include <iostream>
#include <vector>
#include <regex>

#include "../funciones/funciones_necesarias.h"

// Previa declaración de las clases Operacion y Operando
class Operacion;
class Operando;

/**
 * @brief Clase Instruccion que representa una instrucción en el programa.
 * 
 * Esta clase encapsula los detalles de una instrucción, incluyendo su tipo,
 * operando(s) y cualquier información adicional necesaria para su ejecución.
 */
class Instruccion {
 public:
  // Constructores
  Instruccion() {}
  Instruccion(const std::string&);
  // Obtener info de la instrucción
  const std::string& TipoOperador() const;
  const std::string& TipoOperando() const;
  const long double ObtenerConstante() const;
  // Getters y Setters
  const Operacion* get_tipo_operacion() const { return tipo_operacion_; }
  const Operando* get_tipo_operando() const { return tipo_operando_; }
  const std::vector<std::string>& get_instruccion() const { return instruccion_; }
  std::vector<std::string>& set_instruccion() { return instruccion_; }
  const std::string& get_lectura_escritura() const { return lectura_escritura_; }
  void set_lectura_escritura(const std::string&);
  // Sobrecarga del operador de inserción
  friend std::ostream& operator<<(std::ostream&, const Instruccion&);
 private:
  std::vector<std::string> instruccion_; // La instrucción
  Operacion* tipo_operacion_; // Puntero a la clase Operación (Load, Add, ...)
  Operando* tipo_operando_; // Puntero a la clase Operando (constante, directo, ...)
  std::string lectura_escritura_{""}; // Determina si la instrucción es de lectura o de escritura
  // Operaciones sobre la instrucción
  void SepararInstruccionEnPalabras(const std::string&);
  bool ConstruirOperador(const std::string&);
  bool ConstruirOperando(const std::string&, const std::string&);
};