#include "write.h"

bool Write::ValidarInstruccion(const Instruccion& kInstruccion) const {
  if (kInstruccion.get_tipo_operando()->compruebaPatron(kInstruccion.get_instruccion()[1])) return true;
  return false;
}

void Write::EjecutarInstruccion(const Instruccion& kInstruccion, MemoriaDatos& memoria_datos, CintaIn& cinta_entrada,
                                CintaOut& cinta_salida, int& pc) const {
  try {
    const std::string kErrorWriteEnCero = "No se puede escribir en la cinta de salida con WRITE desde R0";
    const long double kValor = kInstruccion.ObtenerConstante();
    long double resultado = kValor;
    if (kInstruccion.get_instruccion()[1][0] != '=') {
      resultado = kInstruccion.get_tipo_operando()->get_registro(memoria_datos, kValor);
      if (resultado == 0) throw (kErrorWriteEnCero);
      resultado = memoria_datos.obtenerDato(resultado);
    }
    cinta_salida.set_cinta().push_back(resultado);
    cinta_salida.set_puntero() = cinta_salida.get_puntero() + 1;
    pc++;
  } catch (const std::string& kError) {
    throw (kError);
  }
}