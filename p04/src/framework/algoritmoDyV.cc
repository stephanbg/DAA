#include "algoritmoDyV.h"

const Instancia AlgoritmoDyV::Solve(const Instancia& kProblema, const int kSize) {
  if (Small(kProblema)) return SolveSmall(kProblema);
  else {
    const std::vector<Instancia> kProblemaDividido = Divide(kProblema, kSize);
    const Instancia kSolucion1 = Solve(kProblemaDividido[0], kProblemaDividido[0].size());
    const Instancia kSolucion2 = Solve(kProblemaDividido[1], kProblemaDividido[1].size());
    const Instancia kSolucion = Combine(kSolucion1, kSolucion2);
    return kSolucion;
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