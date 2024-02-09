#include "operando_indirecto.h"

bool OperandoIndirecto::compruebaPatron(const std::string& kOperando) const {
  const std::regex kPatronIndirecto{"^\\*\\d+$"}; // permite cualquier número de dígitos sin signo empieza por *  
  if (std::regex_match(kOperando, kPatronIndirecto)) return true;
  return false;
}

const long double OperandoIndirecto::get_valor(const MemoriaDatos& kMemoriaDatos, const long double kValor) const {
  const std::string kErrorAccesoFueraDeMemoria = "Accediendo fuera de rango.";
  if (kValor < 0 || kValor >= kMemoriaDatos.get_registros().size()) throw (kErrorAccesoFueraDeMemoria);
  const int kRegistroAlQueSaltar = kMemoriaDatos.obtenerDato(kValor);
  if (kRegistroAlQueSaltar < 0 || kRegistroAlQueSaltar >= kMemoriaDatos.get_registros().size()) throw (kErrorAccesoFueraDeMemoria);
  return kMemoriaDatos.obtenerDato(kRegistroAlQueSaltar);
}

const int OperandoIndirecto::get_registro(const MemoriaDatos& kMemoriaDatos, const int kNumRegistro) const {
  const std::string kErrorAccesoFueraDeMemoria = "Accediendo fuera de rango.";
  if (kNumRegistro < 0 || kNumRegistro >= kMemoriaDatos.get_registros().size()) throw (kErrorAccesoFueraDeMemoria);
  const int kRegistroAlQueSaltar = kMemoriaDatos.obtenerDato(kNumRegistro);
  if (kRegistroAlQueSaltar < 0 || kRegistroAlQueSaltar >= kMemoriaDatos.get_registros().size()) throw (kErrorAccesoFueraDeMemoria);
  return kRegistroAlQueSaltar;
}