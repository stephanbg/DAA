/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 19 de Abril de 2024
 * @file solucion.cc
 * @brief Implementación de la clase Solucion para representar una solución
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p08/src}
 */

#include "solucion.h"

/**
 * @brief Inserta un nuevo punto junto con su índice en la solución.
 * 
 * @param kIndice El índice donde se insertará el nuevo punto.
 * @param kFilaElementoFueraDeSolucion Las coordenadas del nuevo punto.
 * @param kNuevoIndice El nuevo índice del elemento introducido en la solución.
 */
void Solucion::insertarNuevoPuntoEIndice(
  const int kIndice,
  const std::vector<double>& kFilaElementoFueraDeSolucion,
  const int kNuevoIndice
) {
  coordenadas_[kIndice] = kFilaElementoFueraDeSolucion;
  indices_elementos_introducidos_[kIndice] = kNuevoIndice;
}

/**
 * @brief Añade un nuevo elemento junto con su índice a la solución.
 * 
 * @param kElemento Las coordenadas del nuevo elemento.
 * @param kIndiceElemento El índice del nuevo elemento.
 */
void Solucion::añadirNuevoElementoEIndice(
  const std::vector<double> kElemento, const int kIndiceElemento
) { 
  coordenadas_.setMatriz().push_back(kElemento);
  indices_elementos_introducidos_.push_back(kIndiceElemento); 
}

void Solucion::swapPuntoEIndice(
  const int kIndiceEnSolucion,
  const int kIndiceEnEntorno,
  std::pair<Matriz, std::vector<int>>& puntosFueraDeSolucion
) {
  std::swap(coordenadas_[kIndiceEnSolucion], puntosFueraDeSolucion.first[kIndiceEnEntorno]);
  std::swap(indices_elementos_introducidos_[kIndiceEnSolucion], puntosFueraDeSolucion.second[kIndiceEnEntorno]);
}

/**
 * @brief Sobrecarga del operador de inserción en flujo para imprimir la solución.
 * 
 * @param salida El flujo de salida donde se imprimirá la solución.
 * @param kSolucion La solución que se imprimirá.
 * @return El flujo de salida modificado.
 */
std::ostream& operator<<(std::ostream& salida, const Solucion& kSolucion) {
  salida << "Matriz coordenadas de cada elemento (Solución)" << std::endl;
  salida << "-----------------------------------" << std::endl;
  salida << kSolucion.getCoordenadas();
  salida << std::endl;
  salida << "Función objetivo: ";
  salida << std::fixed << std::setprecision(contarDecimales(kSolucion.getFuncionObjetivo(), 5)) << kSolucion.getFuncionObjetivo();
  salida << std::endl;  
  return salida;
}