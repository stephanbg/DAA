#include "cinta_out.h"

void CintaOut::MeterEnFichero(const std::string& kNombreFichero) {
  std::ofstream archivoSalida(kNombreFichero);
  const int kSizeCintaOut = this->cinta_.size();
  for (int i = 0; i < kSizeCintaOut; ++i) {
    archivoSalida << this->cinta_[i];
    if (i < kSizeCintaOut - 1) archivoSalida << " ";
  }
  archivoSalida.close();
}

std::ostream& operator<<(std::ostream& os, const CintaOut& kCinta) {
  const int kSizeCintaOut = kCinta.cinta_.size();
  for (int i = 0; i < kSizeCintaOut; ++i) {
    os << kCinta.cinta_[i];
    if (i < kSizeCintaOut - 1) os << " ";
  }
  return os;
}