#include "algoritmoDyV.h"

const Instancia AlgoritmoDyV::Solve(const Instancia& kProblema, const int kSize) const {
  if (Small(kProblema)) return SolveSmall(kProblema);
  else {
    std::vector<Instancia> kProblemaDividido = Divide(kProblema, kSize);
    const int kSizeProblemaDividido = kProblemaDividido.size();
    std::vector<Instancia> kSoluciones;
    for (int n = 0; n < kSizeProblemaDividido; ++n) {
      kSoluciones.push_back(Solve(kProblemaDividido[n], kProblemaDividido[n].size()));
    }
    const Instancia kSolucion = Combine(kProblema, kSoluciones);
    return kSolucion;
  }
}

const std::string AlgoritmoDyV::Recurrence() const {
  return ("T(n) <= " + getA() + "T(" + getB() + ") + " + getC());
}