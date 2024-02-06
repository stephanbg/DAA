#include "add.h"

void ADD::EjecutarInstruccion(MemoriaDatos& memoria_datos, const CintaIn& cinta_entrada,
                              CintaOut& cinta_salida, int& pc) const {
  std::cout << "SOY ADD EJECUTAR" <<std::endl;
}

bool ADD::ValidarInstruccion(const Instruccion& kInstruccion) const {
  std::cout << "SOY ADD VALIDAR" <<std::endl;
  return true;
}