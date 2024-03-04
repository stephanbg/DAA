/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 27 de Febrero de 2024
 * @file tablaAlgoritmos.h
 * @brief Definición de la clase TablaAlgoritmos
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p04/src}
 * @see {@link https://docs.google.com/document/d/1CcrG-85_oTdAkTo-zgXkudKT8C8z7T7m2hUHVLGUReQ/edit#heading=h.5bq8rsdy1ujx}
 */

#pragma once

#include <vector>
#include <iostream>
#include <fstream>

/**
 * @brief La clase TablaAlgoritmos representa una tabla para almacenar los
 * tiempos de ejecución de los algoritmos y sus nombres. Proporciona funcionalidad
 * para interactuar con la tabla, como establecer tamaños de instancias, tiempos
 * de ejecución de algoritmos y nombres de algoritmos.
 */
class TablaAlgoritmos {
 public:
  void peticionUsuario() const;
  std::vector<int>& setSizeInstancias() { return sizeInstancias_; }
  std::vector<std::vector<double>>& setTiempoAlgoritmos() { return tiempoAlgoritmos_; }
  std::vector<std::vector<std::string>>& setNombresAlgoritmos() { return nombresAlgoritmos_; }
 private:
  std::vector<int> sizeInstancias_;
  std::vector<std::vector<double>> tiempoAlgoritmos_;
  std::vector<std::vector<std::string>> nombresAlgoritmos_;
  void imprimirTabla() const;
  void meterEnFicheroTabla() const;
};