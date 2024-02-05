#include "memoria_datos.h"

std::ostream& operator<<(std::ostream& os, const MemoriaDatos& kMemoria) {
  const int kSizeMemoria = kMemoria.registros_.size();
  for (int i = 0; i < kSizeMemoria; ++i) {
    os << "R" << i << ": " << kMemoria.registros_[i];
    if (i < kSizeMemoria - 1) os << std::endl;
  }
  return os;
}