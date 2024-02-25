#include <set>
#include <chrono>

#include "instancia/instancia.h"
#include "framework/algoritmoDyV.h"
#include "algoritmos-DyV/mergesort.h"
#include "algoritmos-DyV/quicksort.h"
#include "tablaAlgoritmos/tablaAlgoritmos.h"

// Definición de códigos de colores ANSI
#define RESET   "\033[0m"
#define BLUE    "\033[34m"
#define RED     "\033[31m"

int main() {
  // Genere un conjunto de instancias aleatorias de diferentes tamaños.
  srand(time(nullptr));
  std::set<std::vector<int>> conjunto;
  do {
    Instancia cadaInstancia(true);
    conjunto.insert(cadaInstancia.getInstancia());
  } while (rand() % 10 != 0);
  AlgoritmoDyV* mergesort = new MergeSort();
  AlgoritmoDyV* quicksort = new QuickSort();
  TablaAlgoritmos tabla;
  // Para cada instancia, ejecute los algoritmos MergeSort y QuickSort.
  Instancia cada_instancia;
  for (const std::vector<int> instancia : conjunto) {
    std::vector<double> tiempos_por_instancia;
    std::vector<std::string> nombres_algoritmos;    
    tabla.setSizeInstancias().push_back(instancia.size()); 
    // MergeSort
    cada_instancia = instancia;
    auto start_time = std::chrono::steady_clock::now();
    cada_instancia = mergesort->Solve(cada_instancia, cada_instancia.size());
    auto end_time = std::chrono::steady_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    tiempos_por_instancia.push_back(elapsed_time.count());
    nombres_algoritmos.push_back("MergeSort");
    std::cout << "Problema: " << cada_instancia << std::endl << std::endl;
    std::cout << RED << "Mergesort: " << cada_instancia << std::endl;
    std::cout << "Fórmula recurrencia: " << mergesort->Recurrence() << RESET << std::endl << std::endl;
    // QuickSort
    cada_instancia = instancia;
    start_time = std::chrono::steady_clock::now();
    cada_instancia = quicksort->Solve(cada_instancia, cada_instancia.size());
    end_time = std::chrono::steady_clock::now();
    elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    tiempos_por_instancia.push_back(elapsed_time.count());
    nombres_algoritmos.push_back("QuickSort");   
    std::cout << BLUE << "QuickSort: " << cada_instancia << std::endl;
    std::cout << "Fórmula recurrencia: " << quicksort->Recurrence() << RESET << std::endl;
    std::cout << std::endl;
    tabla.setTiempoAlgoritmos().push_back(tiempos_por_instancia);
    tabla.setNombresAlgoritmos().push_back(nombres_algoritmos);
  }
  /* Muestre por pantalla (y opcionalmente por fichero) una tabla con
  la comparación de tiempos de ejecución de los algoritmos para diferentes tamaños de instancia.*/
  tabla.peticionUsuario();
  return 0;
}