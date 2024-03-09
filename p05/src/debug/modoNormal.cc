#include "modoNormal.h"

void ModoNormal::ejecutar(TablaAlgoritmos& tabla) const {
  std::cout << "\nHa elegido el modo Normal" << std::endl << std::endl;
  const std::string kEleccion = this->eleccionDeAlgoritmo();
  std::set<void*> conjunto;
  // Genere un conjunto de instancias aleatorias de diferentes tamaños. 
  if (kEleccion == "1" || kEleccion == "2" || kEleccion == "3") { // Merge Quick Binary
    introducirDatosRandEnConjunto(conjunto, "Vectorial");
    AlgoritmoDyV<std::vector<int>, std::vector<int>>* mergesort = new MergeSort();
    AlgoritmoDyV<std::vector<int>, std::vector<int>>* quicksort = new QuickSort();
    Problema<std::vector<int>>* cada_problema = new ProblemaVectorial;
    Solucion<std::vector<int>>* cada_solucion = new SolucionVectorial;
    //std::cout << std::endl;
    for (auto &ptr : conjunto) {
      cada_problema = static_cast<Problema<std::vector<int>>*>(ptr);
      std::vector<double> tiempos_por_instancia;
      std::vector<std::string> nombres_algoritmos;
      if (kEleccion == "1") {
        calcularMergeSort(mergesort, cada_problema, cada_solucion,
            tiempos_por_instancia, nombres_algoritmos);
      } else if (kEleccion == "2") {
        calcularQuickSort(quicksort, cada_problema, cada_solucion,
            tiempos_por_instancia, nombres_algoritmos);
      } else if (kEleccion == "3") {
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
      }
      tabla.setSizeInstancias().push_back(cada_problema->getProblema().size()); 
      tabla.setTiempoAlgoritmos().push_back(tiempos_por_instancia);
      tabla.setNombresAlgoritmos().push_back(nombres_algoritmos);      
    }
  } else if (kEleccion == "4") {
    introducirDatosRandEnConjunto(conjunto, "Pilas");
    AlgoritmoDyVAccion<std::vector<std::stack<int>>, std::stack<int>>* hanoi = new Hanoi();
    Problema<std::vector<std::stack<int>>>* cada_problema = new ProblemaVectorPilas;
    Solucion<std::stack<int>>* cada_solucion = new SolucionPila;    
    for (auto &ptr : conjunto) {
      cada_problema = static_cast<Problema<std::vector<std::stack<int>>>*>(ptr);
      std::vector<double> tiempos_por_instancia;
      std::vector<std::string> nombres_algoritmos;      
      calcularHanoi(hanoi, cada_problema, cada_solucion,
          tiempos_por_instancia, nombres_algoritmos);
      tabla.setSizeInstancias().push_back(cada_problema->getProblema()[0].size()); 
      tabla.setTiempoAlgoritmos().push_back(tiempos_por_instancia);
      tabla.setNombresAlgoritmos().push_back(nombres_algoritmos);                     
    }
  } else if (kEleccion == "5") {
    introducirDatosRandEnConjunto(conjunto, "Matrices");
    std::cout << "Strassen: [5]" << std::endl;
  }
}