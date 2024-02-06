#include "write.h"

void WRITE::EjecutarInstruccion(MemoriaDatos& memoria_datos, const CintaIn& cinta_entrada,
                                CintaOut& cinta_salida, int& pc) const {
  std::cout << "SOY WRITE EJECUTAR" <<std::endl;
}

bool WRITE::ValidarInstruccion(const Instruccion& kInstruccion) const {
  std::cout << "SOY WRITE VALIDAR" <<std::endl;
  return true;
}