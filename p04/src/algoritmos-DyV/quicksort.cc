#include "quicksort.h"

bool QuickSort::Small(const Instancia& kProblema) const {
  return (kProblema.size() <= 1) ? true : false;
}

const Instancia QuickSort::SolveSmall(const Instancia& kProblema) const {
  return kProblema;
}

const std::vector<Instancia> QuickSort::Divide(Instancia& problema,
    const int kSize) const {
  std::cout << "ResultadoIni: " << std::endl;
  std::cout << problema << std::endl;  
  Instancia menores;
  Instancia mayores;
  const int kPivote = problema[kSize - 1];
  for (int i = 0; i < kSize - 1; i++) {
    if (problema[i] < kPivote) menores.setInstancia().push_back(problema[i]);
    else mayores.setInstancia().push_back(problema[i]);
  }
  problema = menores;
  problema.setInstancia().push_back(kPivote);
  for (auto a : mayores.getInstancia()) {
    problema.setInstancia().push_back(a);
  }
  std::vector<Instancia> resultado;
  resultado.push_back(menores);
  resultado.push_back(mayores);

  std::cout << "Pivote: " << kPivote << std::endl;
  std::cout << "Menores a pivote: " << std::endl;
  std::cout << menores << std::endl;
  std::cout << "Mayores a pivote: " << std::endl;
  std::cout << mayores << std::endl;
  std::cout << "Resultado: " << std::endl;
  std::cout << problema << std::endl;
  
  return resultado;
}