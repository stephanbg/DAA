#include "load.h"

void LOAD::EjecutarInstruccion(MemoriaDatos& memoria_datos, const CintaIn& cinta_entrada,
                               CintaOut& cinta_salida, int& pc) const {
  std::cout << "SOY LOAD EJECUTAR" <<std::endl;
}

bool LOAD::ValidarInstruccion(const Instruccion& kInstruccion) const {
  std::cout << "SOY LOAD VALIDAR" <<std::endl;
  return true;
}