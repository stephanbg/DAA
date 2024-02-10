#include "operando_directo.h"

bool OperandoDirecto::compruebaPatron(const std::string& kOperando) const {
  const std::regex kPatronDirecto{"^\\d+$"}; // permite cualquier número de dígitos sin signo 
  if (std::regex_match(kOperando, kPatronDirecto)) return true;
  return false;
}

/*const int OperandoDirecto::get_registro(const MemoriaDatos& kMemoriaDatos, const int kNumRegistro) const {
  const std::string kErrorAccesoFueraDeMemoria = "Accediendo fuera de rango.";
  if (kNumRegistro < 0 || kNumRegistro >= kMemoriaDatos.get_registros().size()) throw (kErrorAccesoFueraDeMemoria);
  return kNumRegistro;
}*/

const long double OperandoDirecto::get_valor(const Instruccion& kInstruccion, const MemoriaDatos& kMemoriaDatos,
                                             const long double kNumRegistro) const {
  const std::string kOperador = kInstruccion.get_instruccion()[0];
  const std::string kErrorAccesoFueraDeMemoria = "Accediendo fuera de rango.";
  const std::string kErrorWriteEnCero = "No se puede escribir en la cinta de salida con WRITE desde R0";
  const std::string kErrorReadEnCero = "No se puede guardar un elemento en R0 mediante READ";
  if (kNumRegistro < 0 || kNumRegistro >= kMemoriaDatos.get_registros().size()) throw (kErrorAccesoFueraDeMemoria);
  if (kOperador == "LOAD" || kOperador == "ADD" || kOperador == "SUB" || kOperador == "MUL" || kOperador == "DIV" || kOperador == "WRITE") {
    if (kNumRegistro == 0 && kOperador == "WRITE") throw(kErrorWriteEnCero);
    return kMemoriaDatos.obtenerDato(kNumRegistro);
  } else if (kOperador == "STORE" || kOperador == "READ") {
    if (kNumRegistro == 0 && kOperador == "READ") throw(kErrorReadEnCero);
    return kNumRegistro;  
  }
}