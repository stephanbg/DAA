/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 6 de Marzo de 2024
 * @file modoDepurador.cc
 * @brief Implementación de la clase ModoDepurador, que hereda
 * de la clase base Debug, y permite elegir el algoritmo y tamaño de instancia
 * y se muestra por pantalla tanto la instancia como la solución obtenida.
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p05/src}
 * @see {@link https://docs.google.com/document/d/1pwPk5iI5dRHo8M-raauPP5mgCUHy9m9j_au3UDkn_Rc/edit}
 */

#include "modoDepurador.h"

/**
 * @brief Ejecuta el modo Depurador.
 * @param tabla Tabla de tiempos y tamaños de las instancias de los alogoritmos.
 */
void ModoDepurador::ejecutar(TablaAlgoritmos& tabla) const {
  std::cout << "\nHa elegido el modo Depurador" << std::endl << std::endl;
  const std::string kEleccion = this->eleccionDeAlgoritmo();
  int sizeInstancia;
  if (kEleccion != "5") sizeInstancia = Problema<void*>::eleccionSizeInstancia();
  std::vector<double> tiempos_por_instancia;
  std::vector<std::string> nombres_algoritmos;
  if (kEleccion == "1") {
    AlgoritmoDyV<std::vector<int>, std::vector<int>>* mergesort = new MergeSort();
    Problema<std::vector<int>>* cada_problema = new ProblemaVectorial(sizeInstancia, true);
    Solucion<std::vector<int>>* cada_solucion = new SolucionVectorial;    
    calcularMergeSort(mergesort, cada_problema, cada_solucion,
                      tiempos_por_instancia, nombres_algoritmos);
    std::cout << "Instancia: ";
    cada_problema->mostrarProblema();
    std::cout << std::endl;
    cada_solucion->mostrarInfoSolucion("MergeSort", mergesort->Recurrence());
    std::cout << std::endl;
  } else if (kEleccion == "2") {
    AlgoritmoDyV<std::vector<int>, std::vector<int>>* quicksort = new QuickSort();
    Problema<std::vector<int>>* cada_problema = new ProblemaVectorial(sizeInstancia, true);
    Solucion<std::vector<int>>* cada_solucion = new SolucionVectorial;    
    calcularQuickSort(quicksort, cada_problema, cada_solucion,
                      tiempos_por_instancia, nombres_algoritmos);
    std::cout << "Instancia: ";
    cada_problema->mostrarProblema();
    std::cout << std::endl;
    cada_solucion->mostrarInfoSolucion("QuickSort", quicksort->Recurrence());
    std::cout << std::endl;
  } else if (kEleccion == "3") {
    AlgoritmoDyV<std::vector<int>, std::vector<int>>* mergesort = new MergeSort();
    Problema<std::vector<int>>* cada_problema = new ProblemaVectorial(sizeInstancia, true);
    Solucion<std::vector<int>>* cada_solucion = new SolucionVectorial;    
    cada_solucion = mergesort->Solve(cada_problema, cada_problema->getProblema().size());
    cada_problema->setProblema() = cada_solucion->getSolucion();
    std::cout << "Instancia: ";
    cada_problema->mostrarProblema();
    std::cout << std::endl;
    const int kNumeroABuscar = BusquedaBinaria::numeroABuscar();
    AlgoritmoDyV<std::vector<int>, int>* busquedaBinaria =
        new BusquedaBinaria(cada_problema->getProblema().size(), kNumeroABuscar); 
    Solucion<int>* cada_solucion_integer = new SolucionInteger;        
    calcularBusquedaBinaria(busquedaBinaria, cada_problema, cada_solucion_integer,
                            tiempos_por_instancia, nombres_algoritmos);
    cada_solucion_integer->mostrarInfoSolucion("BusquedaBinaria", busquedaBinaria->Recurrence());
    std::cout << std::endl;
  } else if (kEleccion == "4") {
    AlgoritmoDyVAccion<std::vector<std::stack<int>>, std::stack<int>>* hanoi = new Hanoi();
    const int kNumeroPilas = ProblemaVectorPilas::cantidadPilas();
    Problema<std::vector<std::stack<int>>>* cada_problema = new ProblemaVectorPilas(kNumeroPilas,
        sizeInstancia, true);
    Solucion<std::stack<int>>* cada_solucion = new SolucionPila;
    calcularHanoi(hanoi, cada_problema, cada_solucion,
        tiempos_por_instancia, nombres_algoritmos);
    std::cout << "Instancia: ";
    cada_problema->mostrarProblema();
    std::cout << std::endl;
    cada_solucion->mostrarInfoSolucion("Hanoi", hanoi->Recurrence());
    std::cout << std::endl;    
  } else if (kEleccion == "5") {
    AlgoritmoDyV<std::vector<std::vector<std::vector<int>>>, std::vector<std::vector<int>>>* strassen =
        new Strassen();
    const int kNumeroMatrices = ProblemaVectorMatricial::cantidadMatrices();
    const int kFilas = ProblemaVectorMatricial::cantidadFilas();
    int columnas = ProblemaVectorMatricial::cantidadColumnas();  
    while (columnas != kFilas) {
      std::cout << "Las matrices para el algoritmo de strassen tienen que ser cuadradas.\n";
      columnas = ProblemaVectorMatricial::cantidadColumnas();
    }
    std::vector<std::pair<int, int>> vectorDimensiones(kNumeroMatrices);
    // Llenar el vector con las mismas dimensiones para todas las matrices
    for (int i = 0; i < kNumeroMatrices; ++i) {
      vectorDimensiones[i] = std::make_pair(kFilas, columnas);
    }
    Problema<std::vector<std::vector<std::vector<int>>>>* cada_problema =
        new ProblemaVectorMatricial(kNumeroMatrices, vectorDimensiones, true);
    Solucion<std::vector<std::vector<int>>>* cada_solucion = new SolucionMatricial;
    calcularStrassen(strassen, cada_problema, cada_solucion,
        tiempos_por_instancia, nombres_algoritmos);
    std::cout << "\nInstancia:\n";
    cada_problema->mostrarProblema();
    std::cout << std::endl;
    cada_solucion->mostrarInfoSolucion("Strassen", strassen->Recurrence());
    std::cout << std::endl;
  } else if (kEleccion == "6") {
    Problema<int>* problema = new ProblemaInteger();
    Solucion<int>* solucion = new SolucionInteger();
    AlgoritmoDyV<int, int>* fibonacci = new Fibonacci();
    for (int i = 0; i <= sizeInstancia; i++) {
      problema->setProblema() = i;
      solucion = fibonacci->Solve(problema, 0);
      solucion->mostrarSolucion();
      std::cout << std::endl;
    }  
  }
  const std::string kParaLanzamientoDatosATabla = "Se lanza excepción para no mostrar tabla de tiempos.\n";
  throw (kParaLanzamientoDatosATabla);
}