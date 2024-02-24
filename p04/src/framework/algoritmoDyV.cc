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
    std::cout << "Problema en Solve: " << problema << std::endl;
    Combine(problema, kSoluciones);
    return problema;
  }
}

/*1 Solve(Problema p, int tamaño) {
2    if (Small(p))
3       return SolveSmall(p)
4    else {
5       Problema m[] = Divide(p, tamaño)
6       Solucion S1 = Solve(m[0], tamaño/2)
7       Solucion S2 = Solve(m[1], tamaño/2)
8       Solucion S = Combine(S1, S2)
9       return S
10   }
11 }
*/