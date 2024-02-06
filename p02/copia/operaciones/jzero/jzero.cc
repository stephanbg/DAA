#include "jzero.h"

void JZERO::EjecutarInstruccion(MemoriaDatos& memoria_datos, const CintaIn& cinta_entrada,
                                CintaOut& cinta_salida, int& pc) const {
  std::cout << "SOY JZERO EJECUTAR" <<std::endl;
}

bool JZERO::ValidarInstruccion(const Instruccion& kInstruccion) const {
  std::cout << "SOY JZERO VALIDAR" <<std::endl;
  return true;
}