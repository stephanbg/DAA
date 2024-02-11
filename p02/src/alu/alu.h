/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file alu.h
 * @brief Definición de la clase ALU (Unidad Aritmético-Lógica) para el simulador de la Máquina RAM.
 * @author Stephan Brommer Gutiérrez
 * @date 30 de Enero de 2024
 * @see {@link https://docs.google.com/document/d/1n6iua2wSG2UVns-mTA4YdMBVKfKIazkJi4HRzKVKS78/edit}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p02}
 */

#pragma once

#include "../memoria_programa/memoria_programa.h"
#include "../memoria_datos/memoria_datos.h"
#include "../cintas/cinta_in.h"
#include "../cintas/cinta_out.h"
#include "../operaciones/operacion.h"

/**
 * @brief Clase que representa la Unidad Aritmético-Lógica (ALU) de la máquina RAM.
 *        La ALU se encarga de ejecutar las operaciones del programa.
 */
class ALU {
 public:
  void EjecutarPrograma(const MemoriaPrograma&, MemoriaDatos&, CintaIn&, CintaOut&);
 private:
  int pc_; // Contador de programa que indica la próxima instrucción a ejecutar.
};