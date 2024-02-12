/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file estrategia_almacenamiento_unico.h
 * @brief Definición de la clase EstrategiaUnicoEspacio derivada de
 *        EstrategiaAlmacenamiento, utilizada para poder almacenar y obtener datos
 *        de los registros de la memoria de datos, pero cuando solo hay una única columna. 
 * 
 * @see {@link https://docs.google.com/document/d/1n6iua2wSG2UVns-mTA4YdMBVKfKIazkJi4HRzKVKS78/edit}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p02}
 */

#pragma once

#include "estrategia_almacenamiento.h"

/**
 * @brief Clase EstrategiaUnicoEspacio derivada de EstrategiaAlmacenamiento.
 *        Estrategia actual: Cada registro almacena un único espacio para datos.
 */
class EstrategiaUnicoEspacio : public EstrategiaAlmacenamiento {
 public:
  void almacenarDato(std::vector<std::vector<long double>>&, const long double, const int, const int = 0) const override;
  const long double obtenerDato(const std::vector<std::vector<long double>>&, const int, const int = 0) const override;
};