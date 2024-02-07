#include "jump.h"

bool JUMP::ValidarInstruccion(const Instruccion& kInstruccion) const {
  const std::string operando = kInstruccion.get_instruccion()[1];
  if (std::regex_match(operando, patron_.get_patron_etiquetas())) return true;
  return false;
}

void JUMP::EjecutarInstruccion(const Instruccion& kInstruccion, MemoriaDatos& memoria_datos, const CintaIn& cinta_entrada,
                               CintaOut& cinta_salida, int& pc) const {
  std::cout << "SOY JUMP EJECUTAR" <<std::endl;
}