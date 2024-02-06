#include "store.h"

void STORE::EjecutarInstruccion(MemoriaDatos& memoria_datos, const CintaIn& cinta_entrada,
                                CintaOut& cinta_salida, int& pc) const {
  std::cout << "SOY STORE EJECUTAR" <<std::endl;
}

bool STORE::ValidarInstruccion(const Instruccion& kInstruccion) const {
  std::cout << "SOY STORE VALIDAR" <<std::endl;
  return true;
}