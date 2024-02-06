#include "jgtz.h"

void JGTZ::EjecutarInstruccion(MemoriaDatos& memoria_datos, const CintaIn& cinta_entrada,
                               CintaOut& cinta_salida, int& pc) const {
  std::cout << "SOY JGTZ EJECUTAR" <<std::endl;
}

bool JGTZ::ValidarInstruccion(const Instruccion& kInstruccion) const {
  std::cout << "SOY JGTZ VALIDAR" <<std::endl;
  return true;
}