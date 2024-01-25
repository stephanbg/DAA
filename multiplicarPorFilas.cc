#include "multiplicarPorFilas.h"

Matriz MultiplicarPorFilas::multiplicar(const Matriz& matriz1, const Matriz& matriz2) const {
  // Obtén el tamaño de las filas y columnas de la matriz original y la traspuesta
  const size_t filas = matriz1.getMatriz().size();
  const size_t columnas = matriz2.getMatriz()[0].size();
  // Inicializa la matriz resultado con el tamaño adecuado y todos los elementos establecidos en 0
  std::vector<std::vector<long int>> resultado(filas, std::vector<long int>(columnas, 0));
  for (int i = 0; i < matriz1.getMatriz().size(); ++i) {
    for (int j = 0; j < matriz2.getMatriz()[0].size(); ++j) {
      for (int k = 0; k < matriz2.getMatriz().size(); ++k) {
        resultado[i][j] += matriz1.getMatriz()[i][k] * matriz2.getMatriz()[k][j];
      }
    }
  }
  return Matriz(resultado);
}