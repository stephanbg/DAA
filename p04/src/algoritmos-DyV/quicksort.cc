#include "quicksort.h"

bool QuickSort::Small(const Instancia&) const {
  return false;
}

const Instancia QuickSort::SolveSmall(const Instancia&) const {

}

const std::vector<Instancia> QuickSort::Divide(const Instancia& kProblema,
    const int kSize) const {
  Instancia menores;
  Instancia mayores;
  const int kPivote = kProblema.getInstancia()[kSize - 1];
  for (int i = 0; i < kSize - 1; i++) {
    if (kProblema.getInstancia()[i] < kPivote) {
      menores.setInstancia().push_back(kProblema.getInstancia()[i]);
    } else {
      mayores.setInstancia().push_back(kProblema.getInstancia()[i]);
    }
  }
  std::vector<Instancia> resultado;
  resultado.push_back(menores);
  resultado.push_back(mayores);
  return resultado;
}

const Instancia QuickSort::Combine(const Instancia&, const Instancia&) const {
  
}