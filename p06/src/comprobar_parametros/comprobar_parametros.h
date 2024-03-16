#pragma once

#include <iostream>
#include <filesystem>

#include "../funciones/funciones.h"

namespace fs = std::filesystem;

class ComprobarParametros {
 public:
  static void comprobar(const int, char *[]);
  static void ayuda();
 private:
  static bool cantidadParametrosCorrecta(const int);
  static bool existeDirectorio(const std::string&);
  static bool esDirectorioEjemplos(const std::string&);
  static bool valorMinutosCorrecto(const std::string&);
};