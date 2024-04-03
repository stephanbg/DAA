/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 20 de Marzo de 2024
 * @file solucion.h
 * @brief Definición de la clase Solucion que se encarga
 * de realizar tareas
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07_parcial_1/src}
 */

#pragma once

#include <iostream>
#include <fstream>
#include <filesystem>
#include <algorithm>

#include "../nodo/nodo.h"

namespace fs = std::filesystem;

/**
 * @brief Clase que representa una solución (máquina) a la que se le asignan tareas.
 */
class Solucion {
 public:
  static const int cuantasMaquinasACrear(const std::string&);
  void añadirTarea(const Nodo*);
  void insertarTarea(const Nodo*, const int);
  void moverTareaAPosicionDada(const Nodo*, const int);
  const int calcularTCT(const Nodo*) const;   
  const std::vector<const Nodo*> getTareas() const { return tareas_; }
  const int getTCT() const { return tct_; }
  int& setTCT() { return tct_; }
  static void mostrarTareasDeTodasLasMaquinas(const std::vector<Solucion>&);
 private:
  std::vector<const Nodo*> tareas_;
  int tct_ = 0;
};