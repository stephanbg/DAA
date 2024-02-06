#include "jump.h"

void JUMP::EjecutarInstruccion(MemoriaDatos& memoria_datos, const CintaIn& cinta_entrada,
                               CintaOut& cinta_salida, int& pc) const {
  std::cout << "SOY JUMP EJECUTAR" <<std::endl;
}

bool JUMP::ValidarInstruccion(const Instruccion& kInstruccion) const {
  std::cout << "SOY JUMP VALIDAR" <<std::endl;
  return true;
}