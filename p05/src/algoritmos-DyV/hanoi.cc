#include "hanoi.h"

/**
 * @brief Verifica si el problema dado es lo suficientemente pequeño
 * como para aplicar QuickSort.
 * @param kProblema Problema a evaluar.
 * @return true Si el problema es pequeño y QuickSort puede aplicarse,
 *    false en caso contrario.
 */
bool Hanoi::Small(const Problema<std::stack<int>>* kProblema) const {
  
}

/**
 * @brief Resuelve un problema pequeño utilizando QuickSort.
 * @param kProblema Problema pequeño a resolver.
 * @return Solución al problema.
 */
Solucion<std::stack<int>>* Hanoi::SolveSmall(const Problema<std::stack<int>>* kProblema) const {

}

/**
 * @brief Divide el problema en dos subproblemas separados por
 * un pivote para aplicar QuickSort recursivamente.
 * @param kProblema Problema a dividir.
 * @param kSize Tamaño del problema.
 * @return Vector con los dos subproblemas resultantes
 *     de la división por el pivote.
 */
const std::vector<Problema<std::stack<int>>*> Hanoi::Divide(
    const Problema<std::stack<int>>* kProblema,
    const int kSize) const {

}

/**
 * @brief Combina las soluciones de los subproblemas resultantes de la división.
 * @param kSoluciones Vector de soluciones de los subproblemas.
 * @return Solución combinada.
 */
Solucion<std::stack<int>>* Hanoi::Combine(
    const std::vector<const Solucion<std::stack<int>>*>& kSoluciones) const {

}