#include "algoritmoDyV.h"

const Instancia AlgoritmoDyV::Solve(const Instancia& problema, const int size) {
  if (Small(problema)) return SolveSmall(problema);
  else {
    const std::vector<Instancia> kProblemaDividido = Divide(problema, size);
    //const Instancia kSolucion1 = Solve(kProblemaDividido, size/2);
    //const Instancia kSolucion2 = Solve(kProblemaDividido, size/2);
    //const Instancia kSolucion = Combine(kSolucion1, kSolucion2);
    //return kSolucion;
  }
}