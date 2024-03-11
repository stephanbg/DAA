/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 27 de Febrero de 2024
 * @file solucion.h
 * @brief Definición e Implementación de la clase Solucion, que representa
 * la solución a cualquier problema de DyV
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p05/src}
 * @see {@link https://docs.google.com/document/d/1pwPk5iI5dRHo8M-raauPP5mgCUHy9m9j_au3UDkn_Rc/edit}
 */

#pragma once

#include <iostream>

/**
 * @brief La clase Solucion representa la solución
 * a cualquier problema de DyV.
 * @tparam TipoSolucion Tipo de la solución generada por el algoritmo.
 */
template<typename TipoSolucion>
class Solucion {
 public:
  virtual const TipoSolucion& getSolucion() const = 0;
  virtual TipoSolucion& setSolucion() = 0;
  virtual void mostrarSolucion() const = 0;
  /**
   * @brief Muestra la información de la solución
   * @param kNombreAlgoritmo nombre del algoritmo
   * @param kFormulaRecurrencia la fórmula de recurrencia
   */
  virtual void mostrarInfoSolucion(
    const std::string& kNombreAlgoritmo,
    const std::string& kFormulaRecurrencia
  ) const {
    std::cout << kNombreAlgoritmo << ": ";
    mostrarSolucion();   
    std::cout << "\nFórmula recurrencia: " << kFormulaRecurrencia;
  }
  virtual ~Solucion() {}
};