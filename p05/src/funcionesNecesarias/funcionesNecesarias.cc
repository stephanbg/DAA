#include "funcionesNecesarias.h"

bool esNumero(const std::string& str) {
  return std::regex_match(str, std::regex("[+-]?\\d+"));
}

bool contieneSoloDigitos(const std::string& str) {
  return std::regex_match(str, std::regex("\\d+"));
}