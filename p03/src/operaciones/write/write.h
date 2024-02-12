/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file write.h
 * @brief Definición de la clase Write derivada de la clase abstracta Operacion, que se
 *        encargará de ejecutar la instrucción Write.
 * 
 * @see {@link https://docs.google.com/document/d/1n6iua2wSG2UVns-mTA4YdMBVKfKIazkJi4HRzKVKS78/edit}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p02}
 */

#pragma once

#include "../operacion.h"

/**
 * @brief Clase Write derivada de Operacion, se encargará de implementar la escritura de la RAM.
 *        Obtiene el valor de un registro excepto del R0 (prohibido) o de una constante y lo almacena
 *        en la cinta de salida.
 */
class Write : public Operacion {
 public:
  void EjecutarInstruccion(const Instruccion&, MemoriaDatos&, CintaIn&, CintaOut&, int&) const override;
};