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
  for (auto instancia : conjunto) {
    Instancia cada_instancia1(instancia);
    std::cout << "Instancia inicial" << cada_instancia1 << std::endl;
    Instancia fin1 = mergesort->Solve(cada_instancia1, cada_instancia1.size());
    std::cout << "Mergesort" << fin1 << std::endl;
    Instancia cada_instancia2(instancia);
    Instancia fin2 = quicksort->Solve(cada_instancia2, cada_instancia2.size());
    std::cout << "QuickSort" << fin2 << std::endl;    
    
    exit(EXIT_FAILURE);
  }
  /* Muestre por pantalla (y opcionalmente por fichero) una tabla con
  la comparación de tiempos de ejecución de los algoritmos para diferentes tamaños de instancia.*/

  return 0;
}