#include "algoritmoDyV.h"

const Instancia AlgoritmoDyV::Solve(Instancia& problema, const int kSize) {
  if (Small(problema)) return SolveSmall(problema);
  else {
    std::vector<Instancia> kProblemaDividido = Divide(problema, kSize);
    const int kSizeProblemaDividido = kProblemaDividido.size();
    std::vector<Instancia> kSoluciones;
    for (int n = 0; n < kSizeProblemaDividido; ++n) {
      kSoluciones.push_back(Solve(kProblemaDividido[n], kProblemaDividido[n].size()));
    }
    Combine(problema, kSoluciones);
    return problema;
  }
}