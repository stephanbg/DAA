/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 13 de Febrero de 2024
 * @file debug_2.cc
 * @brief Implementación de la clase Debug2, clase derivada de la
 *        clase virtual puro Debug, utilizada para representar
 *        a la opción 2 del debugger.
 * 
 * @see {@link https://docs.google.com/document/d/1zf_w2HtS4zJX3iqr9yPm6f7rRNsrBxL7afCsMapujMQ/edit#heading=h.5bq8rsdy1ujx}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p03}
 */

#include "debug_2.h"

/**
 * @brief Muestra información por pantalla en cada instrucción ejecutada.
 *        Cuál fue la instrucción ejecutada, los registros, la cinta de entrada,
 *        la cinta de salida y sus respectivos punteros.
 * 
 * @param kMemoriaDatos La memoria de los registros
 * @param kCintaIn La cinta de entrada
 * @param kCintaOut La cinta de salida
 * @param kLineaOriginal La linea original en el fichero
 * @param kInstruccionesFichero Las instrucciones del fichero
 */
void Debug2::InfoDuranteEjecucion(const MemoriaDatos& kMemoriaDatos,
                                  const CintaIn& kCintaIn, const CintaOut& kCintaOut,
                                  const int kLineaOriginal,
                                  const std::vector<std::string>& kInstruccionesFichero) const {
  std::cout << "Línea en el fichero: " << kLineaOriginal << std::endl;
  std::cout << "Instrucción ejecutada: " << kInstruccionesFichero[kLineaOriginal - 1] << std::endl << std::endl;
  std::cout << "Memoria de datos:\n" << kMemoriaDatos << std::endl << std::endl;
  std::cout << "Cinta de entrada: " << kCintaIn << std::endl;
  std::cout << "Posición actual de la cinta de entrada: " << kCintaIn.get_puntero() << std::endl << std::endl;
  std::cout << "Cinta de salida: " << kCintaOut << std::endl;
  std::cout << "Posición actual de la cinta de salida: " << kCintaOut.get_puntero() << std::endl << std::endl;
}