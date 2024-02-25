#include "instancia.h"

void Instancia::generadorInstanciaAleatoria() {
  const int kSizeInstancia = rand() % 10000 + 1;
  instancia_.resize(kSizeInstancia);
  for (int pos = 0; pos < kSizeInstancia; ++pos) {
    instancia_[pos] = rand() % 1000 + 1;
  }
}

std::ostream& operator<<(std::ostream& os, const Instancia& instancia) {
  os << "{ ";
  const int kSize = instancia.size();
  for (int i = 0; i < kSize; ++i) {
    os << instancia[i];
    if (i < kSize - 1) os << ", ";
  }
  os << " }";
  return os;
}