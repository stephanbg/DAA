#include "load.h"

bool LOAD::ValidarInstruccion(const Instruccion& kInstruccion) const {
  const std::string operando = kInstruccion.get_instruccion()[1];
  if (std::regex_match(operando, patron_.get_patron_constante()) ||
      std::regex_match(operando, patron_.get_patron_directo()) ||
      std::regex_match(operando, patron_.get_patron_indirecto())) return true;
  return false;
}

void LOAD::EjecutarInstruccion(const Instruccion& kInstruccion, MemoriaDatos& memoria_datos, const CintaIn& cinta_entrada,
                               CintaOut& cinta_salida, int& pc) const {
  std::cout << "SOY LOAD EJECUTAR" <<std::endl;
}