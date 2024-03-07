/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 27 de Febrero de 2024
 * @brief Práctica 4, framework DyV
 *        Implementación de un framework para realizar
 *        algoritmos de DyV
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p04/src}
 * @see {@link https://docs.google.com/document/d/1CcrG-85_oTdAkTo-zgXkudKT8C8z7T7m2hUHVLGUReQ/edit#heading=h.5bq8rsdy1ujx}
 */

#include <set>
#include <array>
#include <stack>

#include "framework/algoritmoDyV.h"
#include "framework/algoritmoDyVAccion.h"
#include "algoritmos-DyV/mergesort.h"
#include "algoritmos-DyV/quicksort.h"
#include "algoritmos-DyV/busqueda_binaria.h"
#include "algoritmos-DyV/hanoi.h"
#include "algoritmos-DyV/strassen.h"
#include "problema/problema.h"
#include "problema/problema-vectorial.h"
#include "problema/problema-vector-pilas.h"
#include "problema/problema-vector-matricial.h"
#include "solucion/solucion.h"
#include "solucion/solucion-vectorial.h"
#include "solucion/solucion-matricial.h"
#include "solucion/solucion-integer.h"
#include "solucion/solucion-pila.h"
#include "calculos/calculos.h"
#include "tablaAlgoritmos/tablaAlgoritmos.h"

// Definición de códigos de colores ANSI
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"

/**
 * @brief Función principal del programa.
 * 
 * @returns 0 si el programa se ejecuta correctamente.
 */
int main() {
  srand(time(nullptr));
  std::vector<std::vector<int>> vector1 = {{3, 4, 5},
                                           {6, 8, 9},
                                           {7, 2, 1} };
  std::vector<std::vector<int>> vector2 = {{1, 2, 5},
                                           {6, 4, 1},
                                           {5, 2, 6} };                                           
  std::vector<std::vector<std::vector<int>>> todasLasMatrices;
  todasLasMatrices.push_back(vector1);
  todasLasMatrices.push_back(vector2);
  AlgoritmoDyV<std::vector<std::vector<std::vector<int>>>,
               std::vector<std::vector<int>>>* strassen = new Strassen();
  const int kCantidadMatrices = 2;               
  Problema<std::vector<std::vector<std::vector<int>>>>* cada_problema = new ProblemaVectorMatricial(kCantidadMatrices);
  ProblemaVectorMatricial matrices(kCantidadMatrices);
  matrices.meterValores(todasLasMatrices);
  cada_problema->setProblema() = matrices.getProblema();
  cada_problema->mostrarProblema();
  Solucion<std::vector<std::vector<int>>>* cada_solucion = new SolucionMatricial();
  cada_solucion->mostrarSolucion();
  cada_solucion = strassen->Solve(cada_problema, cada_problema->getProblema().size());
  cada_solucion->mostrarSolucion();











  /*std::set<std::vector<int>> conjunto;
  // Genere un conjunto de instancias aleatorias de diferentes tamaños.
  do {
    Problema<std::vector<int>>* cada_instancia = new ProblemaVectorial(true);
    conjunto.insert(cada_instancia->getProblema());
  } while (rand() % 10 != 0);
  AlgoritmoDyV<std::vector<int>, std::vector<int>>* mergesort = new MergeSort();
  AlgoritmoDyV<std::vector<int>, std::vector<int>>* quicksort = new QuickSort();
  Problema<std::vector<int>>* cada_problema = new ProblemaVectorial;
  Solucion<std::vector<int>>* cada_solucion = new SolucionVectorial;
  TablaAlgoritmos tabla;
  // Para cada instancia, ejecute los algoritmos MergeSort y QuickSort.
  for (const std::vector<int>& instancia : conjunto) {
    std::vector<double> tiempos_por_instancia;
    std::vector<std::string> nombres_algoritmos;    
    tabla.setSizeInstancias().push_back(instancia.size()); 
    cada_problema->setProblema() = instancia;
    std::cout << "Problema: ";
    cada_problema->mostrarProblema();
    // MergeSort
    calcularMergeSort<std::vector<int>, std::vector<int>>(mergesort, cada_problema, cada_solucion,
                                                          tiempos_por_instancia, nombres_algoritmos);
    std::cout << RED << std::endl << std::endl; 
    cada_solucion->mostrarInfoSolucion("MergeSort", mergesort->Recurrence());
    std::cout << RESET;
    // QuickSort
    calcularQuickSort<std::vector<int>, std::vector<int>>(quicksort, cada_problema, cada_solucion,
                                                          tiempos_por_instancia, nombres_algoritmos);  
    std::cout << BLUE << std::endl << std::endl;
    cada_solucion->mostrarInfoSolucion("QuickSort", quicksort->Recurrence());
    std::cout << RESET << std::endl << std::endl;
    tabla.setTiempoAlgoritmos().push_back(tiempos_por_instancia);
    tabla.setNombresAlgoritmos().push_back(nombres_algoritmos);
  }
  /* Mostrar por pantalla (y opcionalmente por fichero) una tabla con
  la comparación de tiempos de ejecución de los algoritmos para diferentes tamaños de instancia.*/
  //tabla.peticionUsuario();
  return 0;
}