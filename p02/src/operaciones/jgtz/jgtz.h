/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file jgtz.h
 * @brief Definición de la clase Jgtz derivada de la clase abstracta Operacion, que se
 *        encargará de ejecutar la instrucción Jgtz.
 * 
 * @see {@link https://docs.google.com/document/d/1n6iua2wSG2UVns-mTA4YdMBVKfKIazkJi4HRzKVKS78/edit}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p02}
 */

#pragma once

#include "../operacion.h"

/**
 * @brief Clase Jgtz derivada de Operacion, se encargará de implementar un tipo
 *        de salto (R0 > 0) del pc en las instrucciones de la RAM
 */
class Jgtz : public Operacion {
 public:
  void EjecutarInstruccion(const Instruccion&, MemoriaDatos&, CintaIn&, CintaOut&, int&) const override;
};