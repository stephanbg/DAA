#include "instruccion.h"

const std::string& Instruccion::TipoOperador() const {
  return instruccion_[0];
}

const std::string Instruccion::TipoInstruccion() const {
  const std::regex kPatron1("^=.+"); // Operación constante
  const std::regex kPatron2("^\\*.+"); // Operación indirecta
  if (std::regex_match(instruccion_[1], kPatron1)) return "Constante";
  else if (std::regex_match(instruccion_[1], kPatron2)) return "Indirecta";
  return "Directa";
}

std::ostream& operator<<(std::ostream& os, const Instruccion& kInstruccion) {
  const int kSizeInstruccion = kInstruccion.instruccion_.size();
  for (int i = 0; i < kSizeInstruccion; ++i) {
    os << kInstruccion.instruccion_[i];
    if (i < kSizeInstruccion - 1) os << " ";
  }
  return os;
}