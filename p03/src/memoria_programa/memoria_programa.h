/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file memoria_programa.h
 * @brief Definición de la clase MemoriaPrograma, que representa la memoria del programa de la Máquina RAM.
 *        Es decir, contiene todas las instrucciones que se tienen que ejecutar.
 * 
 * @see {@link https://docs.google.com/document/d/1n6iua2wSG2UVns-mTA4YdMBVKfKIazkJi4HRzKVKS78/edit}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p02}
 */

#pragma once

#include <iostream>
#include <vector>

#include "../instruccion/instruccion.h"

/**
 * @brief Clase MemoriaPrograma que representa la memoria del programa de la Máquina RAM.
 */
class MemoriaPrograma {
 public:
  MemoriaPrograma() {} // Memoria vacía
  MemoriaPrograma(const std::vector<Instruccion>& programa) : programa_(programa) {} // Memoria cargada con instrucciones
  const std::vector<Instruccion>& get_programa() const { return programa_; }
  friend std::ostream& operator<<(std::ostream&, const MemoriaPrograma&);
 private:
  std::vector<Instruccion> programa_; // Contiene todo el programa
};