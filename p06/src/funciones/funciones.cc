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

const bool esNumeroSinSigno(const std::string& kNumeroEnCadena) {
  if (kNumeroEnCadena.empty()) return false;
  bool haHabidoPunto = false;
  for (char c : kNumeroEnCadena) {
    if (c == '.' || c == ',') {
      // Si ya ha habido un punto o coma, significa que hay más de uno en la cadena
      if (haHabidoPunto) return false;
      haHabidoPunto = true;
    } else if (c < '0' || c > '9') return false;
  }
  return true;
}

const std::string sustituirComasPorPunto(const std::string& kCadena) {
  std::string cadena_resultante = kCadena;
  for (char& caracter : cadena_resultante) {
    if (caracter == ',') caracter = '.';
  }
  return cadena_resultante;
}

const std::string formatearNumero(const long double numero) {
  std::stringstream stream;
  stream << std::fixed << numero; // Fijar la precisión decimal
  std::string resultado = stream.str();
  // Eliminar los ceros innecesarios después del punto decimal
  size_t pos = resultado.find_last_not_of('0');
  if (pos != std::string::npos && resultado[pos] == '.') resultado.erase(pos);
  else if (pos != std::string::npos) resultado.erase(pos + 1);
  return resultado;
}
