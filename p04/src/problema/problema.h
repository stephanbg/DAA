/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 27 de Febrero de 2024
 * @file problema.h
 * @brief Definición de la clase Problema, que representa cualquier problema de DyV
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p04/src}
 * @see {@link https://docs.google.com/document/d/1CcrG-85_oTdAkTo-zgXkudKT8C8z7T7m2hUHVLGUReQ/edit#heading=h.5bq8rsdy1ujx}
 */

#pragma once

/**
 * @brief La clase Problema representa cualquier problema de DyV.
 * @tparam TipoProblema Tipo del problema generado por el algoritmo.
 */
template<typename TipoProblema>
class Problema {
 public:
  virtual const TipoProblema& getProblema() const = 0;
  virtual TipoProblema& setProblema() = 0;
  virtual void mostrarProblema() const = 0;
  virtual ~Problema() {}
};