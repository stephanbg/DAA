#include "jzero.h"

bool Jzero::ValidarInstruccion(const Instruccion& kInstruccion) const {
  if (kInstruccion.get_tipo_operando()->compruebaPatron(kInstruccion.get_instruccion()[1])) return true;
  return false;
}

void Jzero::EjecutarInstruccion(const Instruccion& kInstruccion, MemoriaDatos& memoria_datos, CintaIn& cinta_entrada,
                                CintaOut& cinta_salida, int& pc) const {
  const std::string kErrorSalto = "Salto a etiqueta inexistente.";
  const int kSalto = kInstruccion.ObtenerConstante();
  if (kSalto == -1) throw (kErrorSalto);
  if (memoria_datos.obtenerDato(0) == 0) pc = kSalto;
  else pc++;
}