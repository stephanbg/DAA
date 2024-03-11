#include "strassen.h"


bool Strassen::Small(const Problema<std::vector<std::vector<std::vector<int>>>>* kProblema) const {
  // Verificar si la matriz es lo suficientemente pequeña para usar el algoritmo de Strassen
  return (kProblema->getProblema().size() <= 2);
}

Solucion<std::vector<std::vector<int>>>* Strassen::SolveSmall(const Problema<std::vector<std::vector<std::vector<int>>>>* kProblema) const {
  // Resolver el problema pequeño directamente
  Solucion<std::vector<std::vector<int>>>* solucion = new SolucionMatricial();
  //solucion->setSolucion() = StrassenAlgorithm(kProblema->getProblema()[0], kProblema->getProblema()[1]);
  return solucion;
}

const std::vector<Problema<std::vector<std::vector<std::vector<int>>>>*> Strassen::Divide(
    const Problema<std::vector<std::vector<std::vector<int>>>>* kProblema,
    const int kSize) const {

}

Solucion<std::vector<std::vector<int>>>* Strassen::Combine(
    const std::vector<const Solucion<std::vector<std::vector<int>>>*>& kSoluciones) const {
  // Combinar las soluciones de los subproblemas
  Solucion<std::vector<std::vector<int>>>* solucion = new SolucionMatricial();
  const std::vector<std::vector<int>>& solucionA = kSoluciones[0]->getSolucion();
  const std::vector<std::vector<int>>& solucionB = kSoluciones[1]->getSolucion();
  // Combinar las soluciones en una sola matriz
  for (int i = 0; i < solucionA.size(); ++i) {
    std::vector<int> fila;
    for (int j = 0; j < solucionA[i].size(); ++j) {
      fila.push_back(solucionA[i][j]);
    }
    for (int j = 0; j < solucionB[i].size(); ++j) {
      fila.push_back(solucionB[i][j]);
    }
    solucion->setSolucion().push_back(fila);
  }
  return solucion;
}