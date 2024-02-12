#include "store.h"

bool Store::ValidarInstruccion(const Instruccion& kInstruccion) const {
  if (kInstruccion.get_tipo_operando()->compruebaPatron(kInstruccion.get_instruccion()[1])) return true;
  return false;
}

void Store::EjecutarInstruccion(const Instruccion& kInstruccion, MemoriaDatos& memoria_datos, CintaIn& cinta_entrada,
                                CintaOut& cinta_salida, int& pc) const {
  try {
    const long double kValorR0 = memoria_datos.obtenerDato(0);
    const long double kValor = kInstruccion.ObtenerConstante();
    const int kRegistro = kInstruccion.get_tipo_operando()->get_valor(kInstruccion, memoria_datos, kValor);
    memoria_datos.almacenarDato(kValorR0, kRegistro);
    pc++;
  } catch (const std::string& kErrorAccesoFueraDeMemoria) {
    throw (kErrorAccesoFueraDeMemoria);
  }
}