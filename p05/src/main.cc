/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 6 de Marzo de 2024
 * @file main.cc
 * @brief Práctica 5, Algoritmos de Divide y Vencerás
 * Hacer uso del framework de la práctica anterior para realizar
 * algoritmos de DyV
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p05/src}
 * @see {@link https://docs.google.com/document/d/1pwPk5iI5dRHo8M-raauPP5mgCUHy9m9j_au3UDkn_Rc/edit}
 */

#include "debug/debug.h"
#include "tablaAlgoritmos/tablaAlgoritmos.h"
#include "algoritmos-DyV/fibonacci.h"

/**
 * @brief Función principal del programa.
 * 
 * @returns 0 si el programa se ejecuta correctamente.
 */
int main() {
  srand(time(nullptr));
  Debug* modo_depurador = Debug::crearModo();
  TablaAlgoritmos tabla;
  try {
    modo_depurador->ejecutar(tabla);
  } catch(const std::string& kPararEjecucion) {
    return 0;
  }
  tabla.peticionUsuario();
  return 0;
}