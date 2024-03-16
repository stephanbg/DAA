#include "comprobar_parametros.h"

void ComprobarParametros::comprobar(const int argc, char *argv[]) {
  std::string mensaje_error = "";
  if (!ComprobarParametros::cantidadParametrosCorrecta(argc)) mensaje_error = "Tienen que ser 3 parámetros";
  else {
    if (!ComprobarParametros::existeDirectorio(argv[1])) {
      mensaje_error = "El directorio '" + std::string(argv[1]) + "' no existe";
    } else if (!ComprobarParametros::esDirectorioEjemplos(argv[1])) {
      mensaje_error = "El directorio '" + std::string(argv[1]) + "' no es el de los ejemplos";
    }  
    if (!ComprobarParametros::valorMinutosCorrecto(argv[2])) {
      mensaje_error = "El límite (en minutos) '" + std::string(argv[2]) + "' no es válido";
    }
  }
  if (mensaje_error != "") throw (mensaje_error);
}

bool ComprobarParametros::cantidadParametrosCorrecta(const int kNumParametros) {
  return (kNumParametros == 3);
}

bool ComprobarParametros::existeDirectorio(const std::string& kNombreDirectorio) {
  return fs::is_directory(kNombreDirectorio);
}

bool ComprobarParametros::esDirectorioEjemplos(const std::string& kNombreDirectorio) {
  return kNombreDirectorio == "ejemplos";
}

bool ComprobarParametros::valorMinutosCorrecto(const std::string& kTiempoLimite) {
  if (!esNumeroEnteroSinSigno(kTiempoLimite)) return false;
  return stoi(kTiempoLimite) >= 1;
}

void ComprobarParametros::ayuda() {
  std::cout << "Uso: programa <directorio_ejemplos> <tiempo_limite>\n\n";
  std::cout << "Descripción:\n";
  std::cout << "Este programa realiza ciertas operaciones en el directorio de ejemplos ";
  std::cout << "dentro del límite de tiempo especificado.\n\n";
  std::cout << "Parámetros:\n";
  std::cout << "<directorio_ejemplos>: Ruta al directorio de ejemplos.\n";
  std::cout << "<tiempo_limite>: Límite de tiempo en minutos para realizar las operaciones.\n";
}