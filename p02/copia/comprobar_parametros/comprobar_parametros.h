#pragma once

#include <string>
#include <regex>

class ComprobarParametros {
 public:
  static void ComprobarErrores(const int, char* []);
 private:
  static void ComprobarCantidadParametros(const int);
  static void ComprobarFormatoDeNombreFicheroRam(const std::string&);
  static void ComprobarFormatoDeNombreCintaEntrada(const std::string&);
  static void ComprobarFormatoDeNombreCintaSalida(const std::string&); 
};