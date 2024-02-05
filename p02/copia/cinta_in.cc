#include "cinta_in.h"
#include "funciones_necesarias.h"

CintaIn::CintaIn(const std::string& kNombreFicheroCintaIn) {
  std::ifstream archivo(kNombreFicheroCintaIn);
  std::string cinta_in = "";
  std::getline(archivo, cinta_in);
  RellenarCola(cinta_in);
  archivo.close();  
}

void CintaIn::RellenarCola(const std::string& kCintaIn) {
  std::string cintaReemplazada = kCintaIn;
  std::replace(cintaReemplazada.begin(), cintaReemplazada.end(), ',', '.');
  std::istringstream iss(cintaReemplazada);
  const std::string kError = "Los datos de la cinta de entrada "
                             "tienen que ser números reales";
  std::string numero;
  while (iss >> numero) {
    if (!EsNumero(numero)) throw kError;
    else {
      cinta_.push(stold(numero));
    }
  }  
}

std::ostream& operator<<(std::ostream& os, const CintaIn& kCinta) {
  std::queue<long double> cinta_copia = kCinta.get_cinta();
  int numero_decimales = 0;
  while (!cinta_copia.empty()) {
    numero_decimales = ContarDecimales(cinta_copia.front());
    os << std::fixed << std::setprecision(numero_decimales) << cinta_copia.front() << " ";
    cinta_copia.pop();
  }
  return os;
}