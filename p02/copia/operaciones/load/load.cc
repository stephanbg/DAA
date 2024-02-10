#include "load.h"

bool Load::ValidarInstruccion(const Instruccion& kInstruccion) const {
  if (kInstruccion.get_tipo_operando()->compruebaPatron(kInstruccion.get_instruccion()[1])) return true;
  return false;
}

void Load::EjecutarInstruccion(const Instruccion& kInstruccion, MemoriaDatos& memoria_datos, CintaIn& cinta_entrada,
                               CintaOut& cinta_salida, int& pc) const {
  try {
    const long double kValor = kInstruccion.ObtenerConstante();
    //long double resultado = 0;
    const long double kResultado = kInstruccion.get_tipo_operando()->get_valor(kInstruccion, memoria_datos, kValor);
    /*if (kInstruccion.get_instruccion()[1][0] == '=') { 
      resultado = kValor;
    } else {
      resultado = kInstruccion.get_tipo_operando()->get_registro(memoria_datos, kValor);
      resultado = memoria_datos.obtenerDato(resultado);
    }*/
    memoria_datos.almacenarDato(kResultado, 0);
    pc++;
  } catch (const std::string& kErrorAccesoFueraDeMemoria) {
    throw (kErrorAccesoFueraDeMemoria);
  }
}