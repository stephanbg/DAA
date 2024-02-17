/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file estrategia_almacenamiento_dinamico.h
 * @brief Definición de la clase EstrategiaVectorDinamico derivada de
 *        EstrategiaAlmacenamiento, utilizada para poder almacenar y obtener datos
 *        de los registros de la memoria de datos, pero cuando un registro puede almacenar
 *        varias columnas de datos. 
 * 
 * @see {@link https://docs.google.com/document/d/1zf_w2HtS4zJX3iqr9yPm6f7rRNsrBxL7afCsMapujMQ/edit#heading=h.5bq8rsdy1ujx}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p03}
 */

#pragma once

#include "estrategia_almacenamiento.h"

/**
 * @brief Clase EstrategiaVectorDinamico derivada de EstrategiaAlmacenamiento.
 *        Estrategia actual: Cada registro puede almacenar un vector de datos.
 */
class EstrategiaVectorDinamico : public EstrategiaAlmacenamiento {
 public:
  void almacenarDato(std::vector<std::vector<long double>>&, const long double, const int, const int) const override;
  const long double obtenerDato(const std::vector<std::vector<long double>>&, const int, const int) const override;
};