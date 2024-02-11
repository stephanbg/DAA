/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file div.h
 * @brief Definición de la clase Div derivada de la clase abstracta Operacion, que se
 *        encargará de validar si la instrucción Div junto a un opernando es válida
 *        y la ejecutará.
 * 
 * @see {@link https://docs.google.com/document/d/1n6iua2wSG2UVns-mTA4YdMBVKfKIazkJi4HRzKVKS78/edit}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p02}
 */

#pragma once

#include "../operacion.h"

/**
 * @brief Clase Div derivada de Operacion, se encargará de implementar la división de la RAM
 *        R0 = R0 / (lo que diga el operando)
 */
class Div : public Operacion {
 public:
  void EjecutarInstruccion(const Instruccion&, MemoriaDatos&, CintaIn&, CintaOut&, int&) const override;
};