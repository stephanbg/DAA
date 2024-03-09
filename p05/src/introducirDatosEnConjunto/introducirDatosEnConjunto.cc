#include "introducirDatosEnConjunto.h"

void introducirDatosRandEnConjunto(std::set<void*>& conjunto, const std::string& kTipoDatos) {
  if (kTipoDatos == "Vectorial") {
    do {
      Problema<std::vector<int>>* cada_instancia = new ProblemaVectorial(true);     
      conjunto.insert(cada_instancia);
    } while (rand() % 10 != 0);
  } else if (kTipoDatos == "Pilas") {
    const int kNumero = ProblemaVectorPilas::cantidadPilas();
    do {
      Problema<std::vector<std::stack<int>>>* cada_instancia = new ProblemaVectorPilas(kNumero, true);     
      conjunto.insert(cada_instancia);
    } while (rand() % 10 != 0);
  } else if (kTipoDatos == "Matrices") {
    /*do {
      Problema<std::vector<std::vector<std::vector<int>>>>* cada_instancia = new ProblemaVectorMatricial(true);     
      conjunto.insert(cada_instancia);
    } while (rand() % 10 != 0);*/
  }
}