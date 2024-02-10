#include "jump.h"

bool Jump::ValidarInstruccion(const Instruccion& kInstruccion) const {
  if (kInstruccion.get_tipo_operando()->compruebaPatron(kInstruccion.get_instruccion()[1])) return true;
  return false;
}

void Jump::EjecutarInstruccion(const Instruccion& kInstruccion, MemoriaDatos& memoria_datos, CintaIn& cinta_entrada,
                               CintaOut& cinta_salida, int& pc) const {
  const std::string kErrorSalto = "Se accede a etiqueta inexistente o fuera de rango.";
  const int kSalto = kInstruccion.ObtenerConstante();
  if (kSalto == -1) throw (kErrorSalto);
  pc = kSalto;
}