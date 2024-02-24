#include "instancia/instancia.h"
#include "framework/algoritmoDyV.h"
#include "algoritmos-DyV/mergesort.h"
#include "algoritmos-DyV/quicksort.h"

int main() {
  // Genere un conjunto de instancias aleatorias de diferentes tamaños.
  do {
    Instancia cadaInstancia(true);
  } while (rand() % 10 != 0);
  AlgoritmoDyV* mergesort = new MergeSort();
  AlgoritmoDyV* quicksort = new QuickSort();
  // Para cada instancia, ejecute los algoritmos MergeSort y QuickSort.
  for (auto instancia : Instancia::getConjuntos()) {
    Instancia cada_instancia;
    cada_instancia.setInstancia() = instancia;
    std::cout << cada_instancia << std::endl;
    quicksort->Solve(cada_instancia, cada_instancia.getInstancia().size());
    exit(EXIT_FAILURE);
  }
  /* Muestre por pantalla (y opcionalmente por fichero) una tabla con
  la comparación de tiempos de ejecución de los algoritmos para diferentes tamaños de instancia.*/

  return 0;
}