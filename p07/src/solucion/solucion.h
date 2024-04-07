/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 1 de Abril de 2024
 * @file solucion.h
 * @brief Definición de la clase Solucion que se encarga
 * de realizar tareas
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07/src}
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
  // Movimientos, inserciones de tareas
  void añadirTarea(const Nodo*);
  void insertarTarea(const Nodo*, const int);
  void moverTarea(const int, const int);
  void moverTareaEntreMaquinas(const int, const int, Solucion&);
  void swapTarea(const int, const int);
  void swapTareaEntreMaquinas(const int, const int, Solucion&);
  // TCT
  const int calcularTCT(const Nodo*);
  const int getTCT() const { return tct_; }
  int& setTCT() { return tct_; }
  // Función objetivo 
  static void calcularFuncionObjetivo(const std::vector<Solucion>&);  
  static const int getFuncionObjetivo() { return funcion_objetivo_; }
  static int& setFuncionObjetivo() { return funcion_objetivo_; }
  // Getter y Setter tareas
  const std::vector<const Nodo*> getTareas() const { return tareas_; }
  std::vector<const Nodo*>& setTareas() { return tareas_; }  
  // Mostrar tarea de todas las máquinas que recibe
  static void mostrarTareasDeTodasLasMaquinas(const std::vector<Solucion>&);
 private:
  std::vector<const Nodo*> tareas_;
  static int funcion_objetivo_;
  int tct_ = 0;
};