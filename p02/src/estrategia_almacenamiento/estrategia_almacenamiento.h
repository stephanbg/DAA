/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file estrategia_almacenamiento.h
 * @brief Definición de la clase abstracta EstrategiaAlmacenamiento y sus métodos
 *        para poder almacenar y obtener datos de los registros de la memoria de datos
 * 
 * @see {@link https://docs.google.com/document/d/1n6iua2wSG2UVns-mTA4YdMBVKfKIazkJi4HRzKVKS78/edit}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p02}
 */

#pragma once

#include <vector>

/**
 * @brief Clase abstracta EstrategiaAlmacenamiento, que actúa
 *        de interfaz para la estrategia de almacenamiento
 */
class EstrategiaAlmacenamiento {
 public:
  virtual void almacenarDato(std::vector<std::vector<long double>>&, const long double, const int, const int) const = 0;
  virtual const long double obtenerDato(const std::vector<std::vector<long double>>&, const int, const int) const = 0;
  virtual ~EstrategiaAlmacenamiento() {}
};