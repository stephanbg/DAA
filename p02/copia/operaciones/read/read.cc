#include "read.h"

void READ::EjecutarInstruccion(MemoriaDatos& memoria_datos, const CintaIn& cinta_entrada,
                               CintaOut& cinta_salida, int& pc) const {
  std::cout << "SOY READ EJECUTAR" <<std::endl;
}

bool READ::ValidarInstruccion(const Instruccion& kInstruccion) const {
  std::cout << "SOY READ VALIDAR" <<std::endl;
  return true;
}