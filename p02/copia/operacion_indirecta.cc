#include "operacion_indirecta.h"

void OperacionIndirecta::EjecutarInstruccion(MemoriaDatos& memoria_datos, const Instruccion& instruccion,
                                             const CintaIn& kCintaIn, CintaOut& cinta_out, int& pc) const {
  std::cout << "INDIR: "  << instruccion << std::endl;
}