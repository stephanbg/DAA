/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 6 de marzo de 2024
 * @file problema-vectorial.cc
 * @brief Implementación de la clase ProblemaVectorial, que representa
 * cualquier problema vectorial de DyV, clase hija de la clase abstracta Problema
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p04/src}
 * @see {@link https://docs.google.com/document/d/1CcrG-85_oTdAkTo-zgXkudKT8C8z7T7m2hUHVLGUReQ/edit#heading=h.5bq8rsdy1ujx}
 */

#include "problema-vectorial.h"

/**
 * @brief Constructor de problemas aleatorios con tamaños aleatorios (si se indica)
 * @param generarAleatorio Si se indica como true se genera aleatorio
 *     el problema, si no está vacío
 */
ProblemaVectorial::ProblemaVectorial(const bool kGenerarAleatorio) { 
  if (kGenerarAleatorio) generadorInstanciaAleatoria();
}

/**
 * @brief Constructor de problemas aleatorios (si se indica) con tamaños fijos
 * @param kCantidadElementos Tamaño del problema
 * @param generarAleatorio Si se indica como true se genera aleatorio
 *     el problema, si no está vacío
 */  
ProblemaVectorial::ProblemaVectorial(const int kCantidadElementos, const bool kGenerarAleatorio) { 
  problema_.resize(kCantidadElementos);
  if (kGenerarAleatorio) generadorInstanciaAleatoriaSizeFijo();
}

/**
 * @brief Constructor de problemas con copia de vector
 * @param instancia el vector que se va a copiar como problema 
 */
ProblemaVectorial::ProblemaVectorial(const std::vector<int>& kInstancia): problema_(kInstancia) {} 

/**
 * @brief Genera problemas de tamaño aleatorio
 * y sus valores también son aleatorios
 */
void ProblemaVectorial::generadorInstanciaAleatoria() {
  const int kSizeInstancia = rand() % 10 + 1;
  problema_.resize(kSizeInstancia);
  for (int pos = 0; pos < kSizeInstancia; ++pos) {
    problema_[pos] = rand() % 1000 + 1;
  }
}

/**
 * @brief Genera problemas de tamaño fijo
 * y sus valores son aleatorios
 */
void ProblemaVectorial::generadorInstanciaAleatoriaSizeFijo() {
  const int kSizeInstancia = problema_.size();
  for (int pos = 0; pos < kSizeInstancia; ++pos) {
    problema_[pos] = rand() % 1000 + 1;
  }
}

/**
 * @brief Muestra el problema vectorial
 */
void ProblemaVectorial::mostrarProblema() const {
  std::cout << "{ ";
  const int kSize = size();
  for (int i = 0; i < kSize; ++i) {
    std::cout << getProblema()[i];
    if (i < kSize - 1) std::cout << ", ";
  }
  std::cout << " }";
}