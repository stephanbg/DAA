#include <iostream>
#include "matriz.h"
#include "matrizPorFilas.h"
#include "matrizPorColumnas.h"

int main() {
  MatrizPorFilas matrizFilas1;
  MatrizPorFilas matrizFilas2;
  //MatrizPorColumnas matrizColumnas1;
  //MatrizPorColumnas matrizColumnas2;  

  /*Matriz* matriz1 = &matrizFilas1;
  Matriz* matriz2 = &matrizFilas2;
  // Utilizar la sobrecarga del operador de inserción para imprimir ambas matrices
  std::cout << "Matriz1:\n";
  matriz1->imprimirMatriz();
  std::cout << "Matriz2:\n";
  matriz2->imprimirMatriz();*/
  matrizFilas1.imprimirMatriz();
  matrizFilas2.imprimirMatriz();
}