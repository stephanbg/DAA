#include "memoria_programa.h"

std::ostream& operator<<(std::ostream& os, const MemoriaPrograma& kMemoria) {
  const int kSizeMemoria = kMemoria.programa_.size();
  for (int i = 0; i < kSizeMemoria; ++i) {
    for (int j = 0; j < kMemoria.programa_[i].get_instruccion().size(); ++j) {
      os << kMemoria.programa_[i].get_instruccion()[j];
      if (j < kMemoria.programa_[i].get_instruccion().size() - 1) os << " ";
    }
    if (i < kSizeMemoria - 1) os << std::endl;
  }
  return os;
}