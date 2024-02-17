/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file memoria_datos.h
 * @brief Definición de la clase MemoriaDatos, que representa la memoria de datos de la Máquina RAM.
 *        Es decir, los registros.
 * 
 * @see {@link https://docs.google.com/document/d/1zf_w2HtS4zJX3iqr9yPm6f7rRNsrBxL7afCsMapujMQ/edit#heading=h.5bq8rsdy1ujx}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p03}
 */

#pragma once

#include <iostream>
#include <vector>
#include <iomanip>

#include "../estrategia_almacenamiento/estrategia_almacenamiento.h"
#include "../funciones/funciones_necesarias.h"

/**
 * @brief Clase MemoriaDatos que representa la memoria de datos de la Máquina RAM.
 */
class MemoriaDatos {
 public:
  // Constructor
  MemoriaDatos(const int, EstrategiaAlmacenamiento*);
  // Como getters y setters
  void almacenarDato(const long double, const int, const int = 0);
  const long double obtenerDato(const int, const int = 0) const;
  const std::vector<std::vector<long double>>& get_registros() const { return registros_; }
  friend std::ostream& operator<<(std::ostream&, const MemoriaDatos&);
 private:
  std::vector<std::vector<long double>> registros_; // Matriz de registros (pueden ser de una columna o de varias)
  EstrategiaAlmacenamiento* estrategia_; // La estrategia de almacenamiento (indica cantidad de columnas)
};