#include "operando_indirecto.h"

bool OperandoIndirecto::compruebaPatron(const std::string& kOperando) const {
  const std::regex kPatronIndirecto{"^\\*\\d+$"}; // permite cualquier número de dígitos sin signo empieza por *  
  if (std::regex_match(kOperando, kPatronIndirecto)) return true;
  return false;
}

const long double OperandoIndirecto::get_valor(const Instruccion& kInstruccion, const MemoriaDatos& kMemoriaDatos,
                                               const long double kNumRegistro) const {
  const std::string kOperador = kInstruccion.get_instruccion()[0];
  const std::string kErrorAccesoFueraDeMemoria = "Accediendo fuera de rango.";
  const std::string kErrorLecturaEscritura = "Este operador no es de escritura, ni de lectura.";
  const std::string kErrorWriteEnCero = "No se puede escribir en la cinta de salida con WRITE desde R0";
  int registro = kNumRegistro;
  if (registro < 0 || registro >= kMemoriaDatos.get_registros().size()) throw (kErrorAccesoFueraDeMemoria);
  registro = kMemoriaDatos.obtenerDato(registro);
  if (registro < 0 || registro >= kMemoriaDatos.get_registros().size()) throw (kErrorAccesoFueraDeMemoria);
  if (lecturaOEscritura_ == "Lectura") return kMemoriaDatos.obtenerDato(registro);
  else if (lecturaOEscritura_ == "Escritura") {
    if (kInstruccion.get_instruccion()[0] == "WRITE" && registro == 0) throw (kErrorWriteEnCero);
    return registro;
  }
  throw (kErrorLecturaEscritura);
  return EXIT_FAILURE; /// Por si no es escritura ni lectura
}