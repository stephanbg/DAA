#include "multiplicarPorColumnas.h"

Matriz MultiplicarPorColumnas::multiplicar(const Matriz& matriz1, const Matriz& matriz2) const {
  // Obtén el tamaño de las filas y columnas de la matriz original y la traspuesta
  const size_t filas = matriz1.getMatriz().size();
  const size_t columnas = matriz2.getMatriz()[0].size();
  // Inicializa la matriz resultado con el tamaño adecuado y todos los elementos establecidos en 0
  std::vector<std::vector<long int>> resultado(filas, std::vector<long int>(columnas, 0));
  for (int i = 0; i < matriz2.getMatriz()[0].size(); ++i) {
    for (int j = 0; j < matriz1.getMatriz().size(); ++j) {
      for (int k = 0; k < matriz1.getMatriz()[j].size(); ++k) {
        resultado[j][i] += matriz1.getMatriz()[j][k] * matriz2.getMatriz()[k][i];
      }
    }
  }
  return Matriz(resultado);
}