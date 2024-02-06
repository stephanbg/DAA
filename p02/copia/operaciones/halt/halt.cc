#include "halt.h"

void HALT::EjecutarInstruccion(MemoriaDatos& memoria_datos, const CintaIn& cinta_entrada,
                               CintaOut& cinta_salida, int& pc) const {
  std::cout << "SOY HALT EJECUTAR" <<std::endl;
}

bool HALT::ValidarInstruccion(const Instruccion& kInstruccion) const {
  std::cout << "SOY HALT VALIDAR" <<std::endl;
  return true;
}