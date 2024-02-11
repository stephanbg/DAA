#include "read.h"

void Read::EjecutarInstruccion(const Instruccion& kInstruccion, MemoriaDatos& memoria_datos, CintaIn& cinta_entrada,
                                CintaOut& cinta_salida, int& pc) const {
  try {
    const std::string kErrorAccesoFueraDeCinta = "No quedan elementos en la cinta de entrada";
    const std::string kErrorReadEnCero = "No se puede guardar un elemento en R0 mediante READ";
    const int kPuntero = cinta_entrada.get_puntero();
    if (kPuntero >= cinta_entrada.get_cinta().size()) throw (kErrorAccesoFueraDeCinta);
    const long double kValorCintaEntrada = cinta_entrada.get_cinta()[kPuntero];
    const long double kValor = kInstruccion.ObtenerConstante();
    const int kRegistro = kInstruccion.get_tipo_operando()->get_valor(kInstruccion, memoria_datos, kValor);
    if (kRegistro == 0) throw (kErrorReadEnCero);
    memoria_datos.almacenarDato(kValorCintaEntrada, kRegistro);
    cinta_entrada.set_puntero() = cinta_entrada.get_puntero() + 1;
    pc++;
  } catch (const std::string& kError) {
    throw (kError);
  }
}