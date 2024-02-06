#include "sub.h"

void SUB::EjecutarInstruccion(MemoriaDatos& memoria_datos, const CintaIn& cinta_entrada,
                              CintaOut& cinta_salida, int& pc) const {
  std::cout << "SOY SUB EJECUTAR" <<std::endl;
}

bool SUB::ValidarInstruccion(const Instruccion& kInstruccion) const {
  std::cout << "SOY SUB VALIDAR" <<std::endl;
  return true;
}