#include "matriz.h"

std::ostream& operator<<(std::ostream& salida, const Matriz& kMatriz) {
  const int kNumFilas = kMatriz.getMatriz().size();
  for (int i = 0; i < kNumFilas; ++i) {
    salida << "Elemento " << i + 1 << ": ";
    const std::vector<double> kCadaFila = kMatriz.getMatriz()[i];
    const int kNumColumnas = kCadaFila.size();
    for (int j = 0; j < kNumColumnas; ++j) {
      const int kNumDecimales = contarDecimales(kCadaFila[j], 2);
      salida << std::fixed << std::setprecision(kNumDecimales) << kCadaFila[j];
      if (j < (kNumColumnas - 1)) salida << ", ";
    }
    salida << std::endl;
  }
  return salida;
}

void Matriz::eliminarElemento(const std::vector<double>& kElementoAEliminar) {
  auto it = std::find(matriz_.begin(), matriz_.end(), kElementoAEliminar);
  if (it != matriz_.end()) matriz_.erase(it);
}