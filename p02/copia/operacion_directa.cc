#include "operacion_directa.h"

void OperacionDirecta::EjecutarInstruccion(MemoriaDatos& memoria_datos, const Instruccion& instruccion,
                                           const CintaIn& kCintaIn, CintaOut& cinta_out, int& pc) const {
  std::cout << "DIR: " << instruccion << std::endl;
}