#include "div.h"

void DIV::EjecutarInstruccion(MemoriaDatos& memoria_datos, const CintaIn& cinta_entrada,
                              CintaOut& cinta_salida, int& pc) const {
  std::cout << "SOY DIV EJECUTAR" <<std::endl;
}

bool DIV::ValidarInstruccion(const Instruccion& kInstruccion) const {
  std::cout << "SOY DIV VALIDAR" <<std::endl;
  return true;
}