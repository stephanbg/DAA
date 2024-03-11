/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 6 de Marzo de 2024
 * @file hanoi.cc
 * @brief Implementación de la clase Hanoi, que se encarga de
 * realizar dicho algoritmo
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p05/src}
 * @see {@link https://docs.google.com/document/d/1pwPk5iI5dRHo8M-raauPP5mgCUHy9m9j_au3UDkn_Rc/edit}
 */

#include "hanoi.h"

/**
 * @brief Verifica si el problema dado es lo suficientemente pequeño
 * como para aplicar Hanoi.
 * @param kSize Tamaño del problema.
 * @return true Si el problema es pequeño y Hanoi puede aplicarse,
 *    false en caso contrario.
 */
bool Hanoi::Small(const int kSize) const {
  // El problema es pequeño si solo hay un disco en la pila de origen
  return kSize == 1;
}

/**
 * @brief Resuelve un problema pequeño utilizando Hanoi. Moviendo un único disco
 * Cuando la pila tiene tamaño 1
 * @param origen Pila origen, de donde sacamos un disco.
 * @param destino Pila destino, donde colocamos el disco sacado de la pila origen.
 */
void Hanoi::SolveSmall(std::stack<int>& origen, std::stack<int>& destino) const {
  std::stack<int> copiaOrigen = origen;
  int disco = origen.top();
  destino.push(disco);
  origen.pop();
}

/**
 * @brief Realiza la accion de Hanoi. Moviendo un disco entre llamadas recursivas
 * @param origen Pila origen, de donde sacamos un disco.
 * @param destino Pila destino, donde colocamos el disco sacado de la pila origen.
 */
void Hanoi::Action(std::stack<int>& origen, std::stack<int>& destino) const {
  std::stack<int> copiaOrigen = origen;
  int disco = origen.top();
  destino.push(disco);
  origen.pop();
}

