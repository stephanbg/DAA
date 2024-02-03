#include "funciones_necesarias.h"

int ContarDecimales(const long double kNumero) {
  // Convertir el número a una cadena
  const std::string kCadena = std::to_string(kNumero);
  // Buscar el punto decimal en la cadena
  const size_t kPosPunto = kCadena.find('.');
  // Contar los dígitos después de él sin incluir ceros a la derecha
  const size_t kPosNoCero = kCadena.find_last_not_of('0');
  if (kPosNoCero != std::string::npos && kPosNoCero > kPosPunto) {
    return kPosNoCero - kPosPunto;
  }
  // Si no se encuentra el punto decimal, o todos los dígitos a la derecha
  // son ceros, no hay decimales
  return 0;
}

bool EsNumero(const std::string& kCadena) {
  const std::regex kPatron("^[+-]?\\d*[.,]?\\d+$");
  return std::regex_match(kCadena, kPatron);
}

std::string ConvertirAMayusculas(const std::string& kCadena) {
  std::string palabras_en_mayusculas = kCadena;
  // Convertir a mayúsculas usando std::transform
  std::transform(palabras_en_mayusculas.begin(), palabras_en_mayusculas.end(),
                 palabras_en_mayusculas.begin(), ::toupper);
  return palabras_en_mayusculas;  
}