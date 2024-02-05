#include "instruccion.h"

std::ostream& operator<<(std::ostream& os, const Instruccion& kInstruccion) {
  const int kSizeInstruccion = kInstruccion.instruccion_.size();
  for (int i = 0; i < kSizeInstruccion; ++i) {
    os << kInstruccion.instruccion_[i];
    if (i < kSizeInstruccion - 1) os << " ";
  }
  return os;
}