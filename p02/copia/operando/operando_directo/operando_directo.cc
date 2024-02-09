#include "operando_directo.h"

bool OperandoDirecto::compruebaPatron(const std::string& kOperando) const {
  const std::regex kPatronDirecto{"^\\d+$"}; // permite cualquier número de dígitos sin signo 
  if (std::regex_match(kOperando, kPatronDirecto)) return true;
  return false;
}

const long double OperandoDirecto::get_valor(const MemoriaDatos& kMemoriaDatos, const long double kValor) const {
  const std::string kErrorAccesoFueraDeMemoria = "Accediendo fuera de rango.";
  if (kValor < 0 || kValor >= kMemoriaDatos.get_registros().size()) throw (kErrorAccesoFueraDeMemoria);
  return kMemoriaDatos.obtenerDato(kValor);
}

const int OperandoDirecto::get_registro(const MemoriaDatos& kMemoriaDatos, const int kNumRegistro) const {
  const std::string kErrorAccesoFueraDeMemoria = "Accediendo fuera de rango.";
  if (kNumRegistro < 0 || kNumRegistro >= kMemoriaDatos.get_registros().size()) throw (kErrorAccesoFueraDeMemoria);
  return kNumRegistro;
}