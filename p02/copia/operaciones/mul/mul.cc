#include "mul.h"

void MUL::EjecutarInstruccion(MemoriaDatos& memoria_datos, const CintaIn& cinta_entrada,
                              CintaOut& cinta_salida, int& pc) const {
  std::cout << "SOY MUL EJECUTAR" <<std::endl;
}

bool MUL::ValidarInstruccion(const Instruccion& kInstruccion) const {
  std::cout << "SOY MUL VALIDAR" <<std::endl;
  return true;
}