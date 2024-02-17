/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file memoria_programa.cc
 * @brief Implementación de la clase MemoriaPrograma, que representa la memoria del programa de la Máquina RAM.
 *        Es decir, contiene todas las instrucciones que se tienen que ejecutar.
 * 
 * @see {@link https://docs.google.com/document/d/1zf_w2HtS4zJX3iqr9yPm6f7rRNsrBxL7afCsMapujMQ/edit#heading=h.5bq8rsdy1ujx}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p03}
 */

#include "memoria_programa.h"

/**
 * @brief Sobrecarga del operador de inserción para imprimir la memoria del programa.
 * 
 * @param os Flujo de salida.
 * @param kMemoria Memoria del programa a imprimir.
 * @return Referencia al flujo de salida.
 */
std::ostream& operator<<(std::ostream& os, const MemoriaPrograma& kMemoria) {
  const int kSizeMemoria = kMemoria.programa_.size();
  for (int i = 0; i < kSizeMemoria; ++i) {
    for (int j = 0; j < kMemoria.programa_[i].get_instruccion().size(); ++j) {
      os << kMemoria.programa_[i].get_instruccion()[j];
      if (j < kMemoria.programa_[i].get_instruccion().size() - 1) os << " ";
    }
    if (i < kSizeMemoria - 1) os << std::endl;
  }
  return os;
}