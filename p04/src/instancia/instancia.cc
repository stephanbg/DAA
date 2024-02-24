#include "instancia.h"

std::set<std::vector<int>> Instancia::conjuntos_;

const std::vector<int> Instancia::generadorInstanciaAleatoria() {
  srand(time(nullptr));
  const int kSizeInstancia = rand() % 10 + 1;
  std::vector<int> instancia;
  instancia.resize(kSizeInstancia);
  do {
    for (int pos = 0; pos < kSizeInstancia; ++pos) {
      instancia[pos] = rand() % 100 + 1;
    }
  } while (Instancia::conjuntos_.find(instancia) != Instancia::conjuntos_.end());
  Instancia::conjuntos_.insert(instancia);
  return instancia;
}

std::ostream& operator<<(std::ostream& os, const Instancia& instancia) {
  os << "{ ";
  auto it = Instancia::conjuntos_.find(instancia.instancia_);
  for (auto elemento = it->begin(); elemento != it->end(); ++elemento) {
    os << *elemento;
    if (std::next(elemento) != it->end()) os << ", ";
  }
  os << " }";
  return os;
}