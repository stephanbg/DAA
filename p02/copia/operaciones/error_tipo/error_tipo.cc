#include "error_tipo.h"

void ErrorTipo::EjecutarInstruccion(MemoriaDatos& memoria_datos, const CintaIn& cinta_entrada,
                                    CintaOut& cinta_salida, int& pc) const {
  std::cout << "SOY ERROR TIPO EJECUTAR" <<std::endl;
}

bool ErrorTipo::ValidarInstruccion(const Instruccion& kInstruccion) const {
  std::cout << "SOY ErrorTipo VALIDAR" <<std::endl;
  return true;
}