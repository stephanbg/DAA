#include "halt.h"

bool Halt::ValidarInstruccion(const Instruccion& kInstruccion) const {
  if (kInstruccion.get_instruccion().size() == 1) return true;
  return false;
}

void Halt::EjecutarInstruccion(const Instruccion& kInstruccion, MemoriaDatos& memoria_datos, CintaIn& cinta_entrada,
                               CintaOut& cinta_salida, int& pc) const {
  pc = -1;
}