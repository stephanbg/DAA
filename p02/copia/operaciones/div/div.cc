#include "div.h"

bool DIV::ValidarInstruccion(const Instruccion& kInstruccion) const {
  const std::string operando = kInstruccion.get_instruccion()[1];
  if (std::regex_match(operando, patron_.get_patron_constante()) ||
      std::regex_match(operando, patron_.get_patron_directo()) ||
      std::regex_match(operando, patron_.get_patron_indirecto())) return true;
  return false;
}

void DIV::EjecutarInstruccion(const Instruccion& kInstruccion, MemoriaDatos& memoria_datos, const CintaIn& cinta_entrada,
                              CintaOut& cinta_salida, int& pc) const {
  const std::string kOperando = kInstruccion.get_instruccion()[1];
  const long double kOperandoNumerico = kInstruccion.ObtenerConstante();
  long double resultado = memoria_datos.obtenerDato(0);
  if (std::regex_match(kOperando, patron_.get_patron_constante())) {
    resultado /= (double) kOperandoNumerico;
  } else if (std::regex_match(kOperando, patron_.get_patron_directo())) {
    resultado /= (double) memoria_datos.obtenerDato(kOperandoNumerico);
  } else { // Patrón indirecto
    const long double kRegistroIndirecto = memoria_datos.obtenerDato(kOperandoNumerico);
    if (kRegistroIndirecto < 0 || kRegistroIndirecto >= memoria_datos.get_registros().size()) throw(pc);
    resultado /= (double) memoria_datos.obtenerDato(kRegistroIndirecto);
  }
  memoria_datos.almacenarDato(resultado, 0);
  pc++;
}