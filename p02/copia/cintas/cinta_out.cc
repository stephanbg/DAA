#include "cinta_out.h"

void CintaOut::MeterEnFichero(const std::string& kNombreFichero) {
  std::ofstream archivoSalida(kNombreFichero);
  const std::string kErrorApertura = "Apertura de archivo de salida.";
  const std::string kErrorCierre = "Cierre de archivo de salida.";
  if (!archivoSalida.is_open()) throw (kErrorApertura);
  const int kSizeCintaOut = this->cinta_.size();
  for (int i = 0; i < kSizeCintaOut; ++i) {
    archivoSalida << this->cinta_[i];
    if (i < kSizeCintaOut - 1) archivoSalida << " ";
  }
  archivoSalida.close();
  if (archivoSalida.is_open()) throw (kErrorCierre);
}

std::ostream& operator<<(std::ostream& os, const CintaOut& kCinta) {
  int numero_decimales = 0;
  const int kSizeCintaOut = kCinta.cinta_.size();
  for (int i = 0; i < kSizeCintaOut; ++i) {
    numero_decimales = ContarDecimales(kCinta.cinta_[i]);
    os << std::fixed << std::setprecision(numero_decimales) << kCinta.cinta_[i];
    if (i < kSizeCintaOut - 1) os << " ";
  }
  return os;
}