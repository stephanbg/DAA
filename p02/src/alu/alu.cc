/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file alu.cc
 * @brief Implementación de la clase ALU (Unidad Aritmético-Lógica) para el simulador de la Máquina RAM.
 * @author Stephan Brommer Gutiérrez
 * @date 30 de Enero de 2024
 * @see {@link https://docs.google.com/document/d/1n6iua2wSG2UVns-mTA4YdMBVKfKIazkJi4HRzKVKS78/edit}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p02}
 */

#include "alu.h"

/**
 * @brief Ejecuta el programa almacenado en la memoria de programa.
 * 
 * @param kMemoriaPrograma Referencia constante a la memoria de programa que contiene el programa a ejecutar.
 * @param memoria_datos Referencia a la memoria de datos en la que se realizarán las operaciones (registros).
 * @param cinta_in Referencia a la cinta de entrada desde la que se leerán los datos.
 * @param cinta_out Referencia a la cinta de salida en la que se escribirán los resultados.
 * @throw Lanza una excepción si no se pudo validar la instrucción o ejecutar. 
 */
void ALU::EjecutarPrograma(const MemoriaPrograma& kMemoriaPrograma,
                           MemoriaDatos& memoria_datos,
                           CintaIn& cinta_in, CintaOut& cinta_out) {
  const int kSizeMemoriaPrograma = kMemoriaPrograma.get_programa().size();
  pc_ = 0;
  while ((pc_ < kSizeMemoriaPrograma) && (pc_ != -1)) {
    if (!kMemoriaPrograma.get_programa()[pc_].get_tipo_operacion()->ValidarInstruccion(kMemoriaPrograma.get_programa()[pc_])) {
      throw (pc_); // Si no se pudo validar la instrucción reenvía la línea errónea hacia el main.
    }
    try { // Si al ejecutar detecta error reenvía la línea errónea hacia el main
      kMemoriaPrograma.get_programa()[pc_].get_tipo_operacion()->EjecutarInstruccion(kMemoriaPrograma.get_programa()[pc_],
                                                                                     memoria_datos, cinta_in, cinta_out, pc_);
    } catch (const std::string& kError) {
      // Concatena el tipo de error y la línea para poder concatenarlo en el main
      std::string error_con_linea = kError + "|" + std::to_string(pc_);
      throw(error_con_linea);
    }
  }
}