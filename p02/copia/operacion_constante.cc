#include "operacion_constante.h"

void OperacionConstante::EjecutarInstruccion(MemoriaDatos& memoria_datos, const Instruccion& instruccion,
                                             const CintaIn& kCintaIn, CintaOut& cinta_out, int& pc) const {
  std::cout << "CONST: " << instruccion << std::endl;
}