#include "hanoi.h"

/**
 * @brief Verifica si el problema dado es lo suficientemente pequeño
 * como para aplicar QuickSort.
 * @param kProblema Problema a evaluar.
 * @return true Si el problema es pequeño y QuickSort puede aplicarse,
 *    false en caso contrario.
 */
bool Hanoi::Small(const int kSize) const {
  // El problema es pequeño si solo hay un disco en la pila de origen
  return kSize == 1;
}

/**
 * @brief Resuelve un problema pequeño utilizando QuickSort.
 * @param kProblema Problema pequeño a resolver.
 * @return Solución al problema.
 */
void Hanoi::SolveSmall(std::stack<int>& origen, std::stack<int>& destino) const {
  std::stack<int> copiaOrigen = origen;
  int disco = origen.top();
  destino.push(disco);
  origen.pop();
}