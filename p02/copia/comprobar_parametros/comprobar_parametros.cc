#include "comprobar_parametros.h"

void ComprobarParametros::ComprobarErrores(const int kArgc,
                                           char* argv[]) {
  ComprobarCantidadParametros(kArgc);
  ComprobarFormatoDeNombreFicheroRam(argv[1]);
  ComprobarFormatoDeNombreCintaEntrada(argv[2]);
  ComprobarFormatoDeNombreCintaSalida(argv[3]);
}

void ComprobarParametros::ComprobarCantidadParametros(const int kArgc) {
  const std::string kError = "Cantidad de parámetros.";
  if (kArgc != 4) {
    throw kError;
  }
}

void ComprobarParametros::ComprobarFormatoDeNombreFicheroRam(const std::string& kRam) {
  const std::regex kPatron(".+\\.ram");
  const std::string kError = "Extensión del programa tiene que ser ram";
  if (!std::regex_match(kRam, kPatron)) throw kError;
}

void ComprobarParametros::ComprobarFormatoDeNombreCintaEntrada(const std::string& kCintaIn) {
  const std::string kNombreCintaIn = "cintas/cinta_in.txt";
  const std::string kError = "Nombre de la cinta de entrada";
  if (kCintaIn != kNombreCintaIn) throw kError;
}

void ComprobarParametros::ComprobarFormatoDeNombreCintaSalida(const std::string& kCintaOut) {
  const std::string kNombreCintaOut = "cintas/cinta_out.txt";
  const std::string kError = "Nombre de la cinta de salida";
  if (kCintaOut != kNombreCintaOut) throw kError;
}