#include "quicksort.h"

bool QuickSort::Small(const Instancia& kProblema) const {
  return (kProblema.size() <= 1) ? true : false;
}

const Instancia QuickSort::SolveSmall(const Instancia& kProblema) const {
  return kProblema;
}

const std::vector<Instancia> QuickSort::Divide(const Instancia& kProblema,
    const int kSize) const {
  Instancia menores;
  Instancia mayores;
  const int kPivote = kProblema[kSize - 1];
  mayores.setInstancia().push_back(kPivote);
  for (int i = 0; i < kSize - 1; i++) {
    if (kProblema[i] <= kPivote) menores.setInstancia().push_back(kProblema[i]);
    else mayores.setInstancia().push_back(kProblema[i]);
  }
  std::vector<Instancia> resultado;
  resultado.push_back(menores);
  resultado.push_back(mayores);
  return resultado;
}

void QuickSort::Combine(Instancia& problema,
    const std::vector<Instancia>& kSoluciones) const {
  Instancia resultado;
  for (const Instancia subproblema : kSoluciones) {
    for (int elemento : subproblema.getInstancia()) {
      resultado.setInstancia().push_back(elemento);
    }
  }
  problema = resultado;
}