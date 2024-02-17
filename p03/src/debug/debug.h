/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 13 de Febrero de 2024
 * @file debug.h
 * @brief Definición de la clase Debug (virtual puro), que
 *        se utiliza para establecer el debugger en 3 versiones.
 *        Si es 0 actúa de la misma manera, si es 1 muestra el número de instrucciones
 *        que se han ejecutado, y si es el 2 no solo muestra el número de instrucciones
 *        que se han ejecutado, si no también la instrucción ejecutada, como se encuentran
 *        los registros en cada instrucción, la cinta de entrada y la posición actual del puntero,
 *        y la cinta de salida y la posición actual del puntero.
 * 
 * @see {@link https://docs.google.com/document/d/1zf_w2HtS4zJX3iqr9yPm6f7rRNsrBxL7afCsMapujMQ/edit#heading=h.5bq8rsdy1ujx}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p03}
 */

#pragma once

#include <iostream>

#include "../instruccion/instruccion.h"
#include "../memoria_datos/memoria_datos.h"
#include "../cintas/cinta_in.h"
#include "../cintas/cinta_out.h"

/**
 * @brief Clase Debug que actúa como la clase base virtual puro,
 *        para 3 clases distintas, que representan las diferentes
 *        formas de depuración
 */
class Debug {
 public:  
  /**
     * @brief Muetra el número de instrucciones que se han ejecutado
     *        en todo el programa RAM
     * @param kNumInstrucciones La cantidad de instrucciones
     */
  virtual void MostrarNumeroInstruccionesEjecutadas(const int kNumInstrucciones) const {
    std::cout << "Número de instrucciones ejecutadas: " << kNumInstrucciones << std::endl;
  } 
  virtual void InfoDuranteEjecucion(const MemoriaDatos&, const CintaIn&,
                                    const CintaOut&, const int,
                                    const std::vector<std::string>&) const = 0;
  virtual ~Debug() {} // Destructor virtual
};