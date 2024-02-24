#include "instancia/instancia.h"
#include "framework/algoritmoDyV.h"
#include "algoritmos-DyV/mergesort.h"
#include "algoritmos-DyV/quicksort.h"

int main() {
  // Genere un conjunto de instancias aleatorias de diferentes tamaños.
  do {
    Instancia cadaInstancia;
  } while (rand() % 10 != 0);
  AlgoritmoDyV* mergesort = new MergeSort();
  AlgoritmoDyV* quicksort = new QuickSort();
  // Para cada instancia, ejecute los algoritmos MergeSort y QuickSort.
  /*for (auto it = Instancia::getConjuntos().begin(); it != Instancia::getConjuntos().end(); ++it) {
    //mergesort->Solve(*it, it->size());
    //quicksort->Solve(*it, it->size());
  }*/
  /* Muestre por pantalla (y opcionalmente por fichero) una tabla con
  la comparación de tiempos de ejecución de los algoritmos para diferentes tamaños de instancia.*/

  return 0;
}