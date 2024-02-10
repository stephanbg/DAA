#include "operando_indirecto.h"

bool OperandoIndirecto::compruebaPatron(const std::string& kOperando) const {
  const std::regex kPatronIndirecto{"^\\*\\d+$"}; // permite cualquier número de dígitos sin signo empieza por *  
  if (std::regex_match(kOperando, kPatronIndirecto)) return true;
  return false;
}

/*const int OperandoIndirecto::get_registro(const MemoriaDatos& kMemoriaDatos, const int kNumRegistro) const {
  const std::string kErrorAccesoFueraDeMemoria = "Accediendo fuera de rango.";
  if (kNumRegistro < 0 || kNumRegistro >= kMemoriaDatos.get_registros().size()) throw (kErrorAccesoFueraDeMemoria);
  const int kRegistroAlQueSaltar = kMemoriaDatos.obtenerDato(kNumRegistro);
  if (kRegistroAlQueSaltar < 0 || kRegistroAlQueSaltar >= kMemoriaDatos.get_registros().size()) throw (kErrorAccesoFueraDeMemoria);
  return kRegistroAlQueSaltar;
}*/

const long double OperandoIndirecto::get_valor(const Instruccion& kInstruccion, const MemoriaDatos& kMemoriaDatos,
                                               const long double kNumRegistro) const {
  const std::string kOperador = kInstruccion.get_instruccion()[0];
  const std::string kErrorAccesoFueraDeMemoria = "Accediendo fuera de rango.";
  const std::string kErrorWriteEnCero = "No se puede escribir en la cinta de salida con WRITE desde R0";
  const std::string kErrorReadEnCero = "No se puede guardar un elemento en R0 mediante READ";
  int registro = kNumRegistro;
  if (registro < 0 || registro >= kMemoriaDatos.get_registros().size()) throw (kErrorAccesoFueraDeMemoria);
  registro = kMemoriaDatos.obtenerDato(registro);
  if (registro < 0 || registro >= kMemoriaDatos.get_registros().size()) throw (kErrorAccesoFueraDeMemoria);
  if (kOperador == "LOAD" || kOperador == "ADD" || kOperador == "SUB" || kOperador == "MUL" || kOperador == "DIV" || kOperador == "WRITE") {
    if (registro == 0 && kOperador == "WRITE") throw(kErrorWriteEnCero);
    return kMemoriaDatos.obtenerDato(registro);
  } else if (kOperador == "STORE" || kOperador == "READ") {
    if (registro == 0 && kOperador == "READ") throw(kErrorReadEnCero);
    return registro;  
  }
}