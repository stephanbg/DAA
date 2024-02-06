#include "memoria_datos.h"

MemoriaDatos::MemoriaDatos(const int kNumeroRegistros, EstrategiaAlmacenamiento* estrategia) {
  estrategia_ = estrategia;
  std::vector<int> fila_registro;
  for (int i = 0; i < kNumeroRegistros; ++i) {
    fila_registro.resize(1, 0);
    registros_.push_back(fila_registro);
  }
}

std::ostream& operator<<(std::ostream& os, const MemoriaDatos& kMemoria) {
  const int kSizeMemoria = kMemoria.registros_.size();
  for (int i = 0; i < kSizeMemoria; ++i) {
    os << "R" << i << ": ";
    for (int j = 0; j < kMemoria.registros_[i].size(); ++j) {
      os << kMemoria.registros_[i][j];
      if (j < kSizeMemoria - 1) os << " ";
    }
    if (i < kSizeMemoria - 1) os << std::endl;
  }
  return os;
}