#include "introducirDatosEnConjunto.h"

void introducirDatosRandEnConjunto(std::set<void*>& conjunto, const std::string& kTipoDatos) {
  if (kTipoDatos == "Vectorial") {
    do {
      Problema<std::vector<int>>* cada_instancia = new ProblemaVectorial(true);     
      conjunto.insert(cada_instancia);
    } while (rand() % 10 != 0);
  } else if (kTipoDatos == "Pilas") {
    std::cout << "Dime la cantidad de Pilas que desea: ";
    std::string numero;
    while (std::cin >> numero) {
      if (contieneSoloDigitos(numero) && numero >= "3") break;
      std::cout << "Tienen que ser mínimo 3 pilas." << std::endl;
      std::cout << "Que número de pilas desea: ";
    }    
    do {
      Problema<std::vector<std::stack<int>>>* cada_instancia = new ProblemaVectorPilas(stoi(numero), true);     
      conjunto.insert(cada_instancia);
    } while (rand() % 10 != 0);
  } else if (kTipoDatos == "Matrices") {
    /*do {
      Problema<std::vector<std::vector<std::vector<int>>>>* cada_instancia = new ProblemaVectorMatricial(true);     
      conjunto.insert(cada_instancia);
    } while (rand() % 10 != 0);*/
  }
}