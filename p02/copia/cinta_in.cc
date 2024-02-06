#include "cinta_in.h"
#include "funciones_necesarias.h"

CintaIn::CintaIn(const std::string& kNombreFicheroCintaIn) {
  std::ifstream archivo(kNombreFicheroCintaIn);
  std::string cinta_in = "";
  std::getline(archivo, cinta_in);
  puntero_ = 0;
  RellenarVector(cinta_in);
  archivo.close();  
}

void CintaIn::RellenarVector(const std::string& kCintaIn) {
  std::string cintaReemplazada = kCintaIn;
  std::replace(cintaReemplazada.begin(), cintaReemplazada.end(), ',', '.');
  std::istringstream iss(cintaReemplazada);
  const std::string kError = "Los datos de la cinta de entrada "
                             "tienen que ser números reales";
  std::string numero;
  while (iss >> numero) {
    if (!EsNumero(numero)) throw kError;
    else {
      cinta_.push_back(stold(numero));
    }
  }  
}

std::ostream& operator<<(std::ostream& os, const CintaIn& kCinta) {
  std::vector<long double> cinta_copia = kCinta.get_cinta();
  int numero_decimales = 0;
  const int kSizeCinta = cinta_copia.size();
  for (int i = 0; i < kSizeCinta; ++i) {
    numero_decimales = ContarDecimales(cinta_copia[i]);
    os << std::fixed << std::setprecision(numero_decimales) << cinta_copia[i];
    if (i < kSizeCinta - 1) os << " ";
  }
  return os;
}