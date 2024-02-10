#include "operando_directo.h"

bool OperandoDirecto::compruebaPatron(const std::string& kOperando) const {
  const std::regex kPatronDirecto{"^\\d+$"}; // permite cualquier número de dígitos sin signo 
  if (std::regex_match(kOperando, kPatronDirecto)) return true;
  return false;
}

const long double OperandoDirecto::get_valor(const Instruccion& kInstruccion, const MemoriaDatos& kMemoriaDatos,
                                             const long double kNumRegistro) const {
  const std::string kOperador = kInstruccion.get_instruccion()[0];
  const std::string kErrorAccesoFueraDeMemoria = "Accediendo fuera de rango.";
  const std::string kErrorLecturaEscritura = "Este operador no es de escritura, ni de lectura.";
  const std::string kErrorWriteEnCero = "No se puede escribir en la cinta de salida con WRITE desde R0";
  if (kNumRegistro < 0 || kNumRegistro >= kMemoriaDatos.get_registros().size()) throw (kErrorAccesoFueraDeMemoria);
  if (lecturaOEscritura_ == "Lectura") return kMemoriaDatos.obtenerDato(kNumRegistro);
  else if (lecturaOEscritura_ == "Escritura") {
    if (kInstruccion.get_instruccion()[0] == "WRITE" && kNumRegistro == 0) throw (kErrorWriteEnCero);
    return kNumRegistro;
  }
  throw (kErrorLecturaEscritura);
  return EXIT_FAILURE; /// Por si no es escritura ni lectura
}