#include "add.h"

bool Add::ValidarInstruccion(const Instruccion& kInstruccion) const {
  if (kInstruccion.get_tipo_operando()->compruebaPatron(kInstruccion.get_instruccion()[1])) return true;
  return false;
}

void Add::EjecutarInstruccion(const Instruccion& kInstruccion, MemoriaDatos& memoria_datos, CintaIn& cinta_entrada,
                              CintaOut& cinta_salida, int& pc) const {
  try {
    const long double kValor = kInstruccion.ObtenerConstante();
    const long double kResultado = kInstruccion.get_tipo_operando()->get_valor(kInstruccion, memoria_datos, kValor); 
    const long double R0 = memoria_datos.obtenerDato(0) + kResultado;
    memoria_datos.almacenarDato(R0, 0);
    pc++;
  } catch (const std::string& kErrorAccesoFueraDeMemoria) {
    throw (kErrorAccesoFueraDeMemoria);
  }
}