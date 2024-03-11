/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 6 de Marzo de 2024
 * @file introducirDatosEnConjunto.cc
 * @brief Implementación de funciones que meten datos en conjuntos, para
 * su posterior evaluación
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p05/src}
 * @see {@link https://docs.google.com/document/d/1pwPk5iI5dRHo8M-raauPP5mgCUHy9m9j_au3UDkn_Rc/edit}
 */

#include "introducirDatosEnConjunto.h"

/**
 * @brief Introduce instancias aleatorias en un conjunto según el tipo de datos especificado.
 * @param conjunto Conjunto donde se introducirán las instancias.
 * @param kTipoDatos Tipo de datos de las instancias a introducir.
 */
void introducirDatosRandEnConjunto(std::set<void*>& conjunto, const std::string& kTipoDatos) {
  if (kTipoDatos == "Vectorial") {
    do {
      Problema<std::vector<int>>* cada_instancia = new ProblemaVectorial(true);     
      conjunto.insert(cada_instancia);
    } while (rand() % 10 != 0);
  } else if (kTipoDatos == "Pilas") {
    const int kNumero = ProblemaVectorPilas::cantidadPilas();
    do {
      Problema<std::vector<std::stack<int>>>* cada_instancia = new ProblemaVectorPilas(kNumero, true);     
      conjunto.insert(cada_instancia);
    } while (rand() % 10 != 0);
  } else if (kTipoDatos == "Matrices") {
    /*do {
      Problema<std::vector<std::vector<std::vector<int>>>>* cada_instancia = new ProblemaVectorMatricial(true);     
      conjunto.insert(cada_instancia);
    } while (rand() % 10 != 0);*/
  }
}