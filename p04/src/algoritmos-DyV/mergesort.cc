#include "mergesort.h"

bool MergeSort::Small(const Instancia& kProblema) const {
  return (kProblema.size() <= 1) ? true : false;
}

const Instancia MergeSort::SolveSmall(const Instancia& kProblema) const {
  return kProblema;
}

const std::vector<Instancia> MergeSort::Divide(const Instancia& kProblema,
    const int kSize) const {
  Instancia elementos_izquierda;
  Instancia elementos_derecha;
  const size_t kMitad = kSize / 2;
  for (int i = 0; i < kSize; ++i) {
    if (i < kMitad) elementos_izquierda.setInstancia().push_back(kProblema[i]);
    else elementos_derecha.setInstancia().push_back(kProblema[i]);
  }
  std::vector<Instancia> resultado; 
  resultado.push_back(elementos_izquierda);
  resultado.push_back(elementos_derecha);
  return resultado;
}

void MergeSort::Combine(Instancia& problema, const std::vector<Instancia>& kSoluciones) const {
  Instancia resultado;
  Instancia kProblemaIzq = kSoluciones[0];
  Instancia kProblemaDerech = kSoluciones[1];
  size_t indice_izquierda = 0;
  size_t indice_derecha = 0;
  while (indice_izquierda < kProblemaIzq.size() &&
      indice_derecha < kProblemaDerech.size()) {
    if (kProblemaIzq[indice_izquierda] <= kProblemaDerech[indice_derecha]) {
      resultado.setInstancia().push_back(kProblemaIzq[indice_izquierda++]);
    } else {
      resultado.setInstancia().push_back(kProblemaDerech[indice_derecha++]);
    }
  }
  // Agregar los elementos restantes de izquierda a resultado
  while (indice_izquierda < kProblemaIzq.size()) {
    resultado.setInstancia().push_back(kProblemaIzq[indice_izquierda++]);
  }
  // Agregar los elementos restantes de derecha a resultado
  while (indice_derecha < kProblemaDerech.size()) {
    resultado.setInstancia().push_back(kProblemaDerech[indice_derecha++]);
  }
  problema = resultado;
}