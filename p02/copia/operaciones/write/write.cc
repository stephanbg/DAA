#include "write.h"

bool Write::ValidarInstruccion(const Instruccion& kInstruccion) const {
  if (kInstruccion.get_tipo_operando()->compruebaPatron(kInstruccion.get_instruccion()[1])) return true;
  return false;
}

void Write::EjecutarInstruccion(const Instruccion& kInstruccion, MemoriaDatos& memoria_datos, CintaIn& cinta_entrada,
                                CintaOut& cinta_salida, int& pc) const {
  try {
    const long double kValor = kInstruccion.ObtenerConstante();
    long double resultado = kValor;
    if (kInstruccion.get_instruccion()[1][0] != '=') {
      const long double kRegistro = kInstruccion.get_tipo_operando()->get_valor(kInstruccion, memoria_datos, kValor);
      resultado = memoria_datos.obtenerDato(kRegistro);
    }
    cinta_salida.set_cinta().push_back(resultado);
    cinta_salida.set_puntero() = cinta_salida.get_puntero() + 1;
    pc++;
  } catch (const std::string& kError) {
    throw (kError);
  }
}