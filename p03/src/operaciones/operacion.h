/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file operacion.h
 * @brief Definición de la clase abstracta Operacion, que tendrá una serie de clases derivadas
 *        que sobreescribirán los métodos de validar y ejecutar instrucción.
 * 
 * @see {@link https://docs.google.com/document/d/1n6iua2wSG2UVns-mTA4YdMBVKfKIazkJi4HRzKVKS78/edit}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p02}
 */

#pragma once

#include <iostream>
#include <regex>

#include "../memoria_datos/memoria_datos.h"
#include "../cintas/cinta_in.h"
#include "../cintas/cinta_out.h"
#include "../instruccion/instruccion.h"
#include "../funciones/funciones_necesarias.h"
#include "../operando/operando_constante/operando_constante.h"
#include "../operando/operando_directo/operando_directo.h"
#include "../operando/operando_directo_vectorial/operando_directo_vectorial.h"
#include "../operando/operando_indirecto/operando_indirecto.h"

/**
 * @brief Clase base abstracta Operacion para representar una operación en el programa RAM.
 *        Esta clase define la interfaz común para todas las operaciones que
 *        pueden ser ejecutadas en el programa RAM.
 */
class Operacion {
 public:
  /**
   * @brief Valida si la instrucción es válida.
   * 
   * @param kInstruccion La instrucción a validar.
   * @return true si la instrucción es válida para, false en caso contrario.
   */
  virtual bool ValidarInstruccion(const Instruccion& kInstruccion) const {
    if (kInstruccion.get_tipo_operando()->compruebaPatron(kInstruccion.get_instruccion()[1])) return true;
    return false;
  }
  virtual void EjecutarInstruccion(const Instruccion&, MemoriaDatos&, CintaIn&, CintaOut&, int&) const = 0;
  virtual ~Operacion() {} // Destructor virtual
};