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
    const int kFilas = ProblemaVectorMatricial::cantidadFilas();
    int columnas = ProblemaVectorMatricial::cantidadColumnas();  
    while (columnas != kFilas) {
      std::cout << "Las matrices para el algoritmo de strassen tienen que ser cuadradas.\n";
      columnas = ProblemaVectorMatricial::cantidadColumnas();
    }    
    do {
      const int kNumeroMatrices = rand() % 8 + 2;
      std::vector<std::pair<int, int>> vectorDimensiones(kNumeroMatrices);
      // Llenar el vector con las mismas dimensiones para todas las matrices
      for (int i = 0; i < kNumeroMatrices; ++i) {
        vectorDimensiones[i] = std::make_pair(kFilas, columnas);
      }      
      Problema<std::vector<std::vector<std::vector<int>>>>* cada_instancia =
          new ProblemaVectorMatricial(kNumeroMatrices, vectorDimensiones, true);
      conjunto.insert(cada_instancia);
    } while (rand() % 10 != 0);
  } else if (kTipoDatos == "Integer") {
    do {
      Problema<int>* cada_instancia = new ProblemaInteger(true);     
      conjunto.insert(cada_instancia);
    } while (rand() % 10 != 0);
  }
}