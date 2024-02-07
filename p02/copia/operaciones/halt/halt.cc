#include "halt.h"

bool HALT::ValidarInstruccion(const Instruccion& kInstruccion) const {
  if (kInstruccion.get_instruccion().size() > 1) return false;
  return true;
}

void HALT::EjecutarInstruccion(const Instruccion& kInstruccion, MemoriaDatos& memoria_datos, const CintaIn& cinta_entrada,
                               CintaOut& cinta_salida, int& pc) const {
  std::cout << "SOY HALT EJECUTAR" <<std::endl;
}