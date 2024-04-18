#include "problema.h"

Problema::Problema(const std::string& kNombreDir) {
  const std::vector<std::string> kNombreFicheros = extraerFicherosEjemplo(kNombreDir);
  for (auto a : kNombreFicheros) {
    std::cout << a << std::endl;
  }
}