/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file read.h
 * @brief Definición de la clase Read derivada de la clase abstracta Operacion, que se
 *        encargará de validar si la instrucción Read junto a un opernando es válida
 *        y la ejecutará.
 * 
 * @see {@link https://docs.google.com/document/d/1n6iua2wSG2UVns-mTA4YdMBVKfKIazkJi4HRzKVKS78/edit}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p02}
 */

#pragma once

#include "../operacion.h"

/**
 * @brief Clase Read derivada de Operacion, se encargará de implementar la lectura de la RAM.
 *        Lee de la cinta de entrada y almacena el valor donde diga el operando, no se puede
 *        almacenar en R0, ni READ =constante.
 */
class Read : public Operacion {
 public:
  void EjecutarInstruccion(const Instruccion&, MemoriaDatos&, CintaIn&, CintaOut&, int&) const override;
};