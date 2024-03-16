#include "funciones.h"

const bool contieneFalso(const std::vector<bool>& booleanos) {
  for (bool b : booleanos) {
    if (!b) return true;
  }
  return false;
}

const bool esNumeroEnteroSinSigno(const std::string& kNumeroEnCadena) {
  if (kNumeroEnCadena[0] == '+' || kNumeroEnCadena[0] == '-') return false;
  const int kSizeNumero = kNumeroEnCadena.size();
  for (int i = 0; i < kSizeNumero; ++i) {
    if (kNumeroEnCadena[i] < '0' ||  kNumeroEnCadena[i] > '9') return false;
  }
  return true;
}