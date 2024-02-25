#include <set>

#include "instancia/instancia.h"
#include "framework/algoritmoDyV.h"
#include "algoritmos-DyV/mergesort.h"
#include "algoritmos-DyV/quicksort.h"

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
  // Para cada instancia, ejecute los algoritmos MergeSort y QuickSort.
  Instancia cada_instancia;
  for (const std::vector<int> instancia : conjunto) {
    cada_instancia = instancia;
    std::cout << "Problema: " << cada_instancia << std::endl;
    std::cout << "Mergesort: " << mergesort->Solve(cada_instancia, cada_instancia.size()) << std::endl;
    cada_instancia = instancia;
    std::cout << "QuickSort: " << quicksort->Solve(cada_instancia, cada_instancia.size()) << std::endl;
    std::cout << std::endl;
  }
  /* Muestre por pantalla (y opcionalmente por fichero) una tabla con
  la comparación de tiempos de ejecución de los algoritmos para diferentes tamaños de instancia.*/

  return 0;
}