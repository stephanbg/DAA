#include "operando_constante.h"

bool OperandoConstante::compruebaPatron(const std::string& kOperando) const {
  const std::regex kPatronConstante{"^=[-+]?\\d+([,.]?\\d+|\\d*)$"}; // Empieza por '=' y acaba por uno o más dígitos  
  if (std::regex_match(kOperando, kPatronConstante)) return true;
  return false;
}

const long double OperandoConstante::get_valor(const MemoriaDatos& kMemoriaDatos, const long double kValor) const {
  return kValor;
}