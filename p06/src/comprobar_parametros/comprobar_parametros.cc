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
  std::cout << "Este programa lee todos los ficheros del directorio ejemplos, que contienen\n";
  std::cout << "la descripción de los grafos, y se ejecutan los algoritmos de TSP con fuerza bruta,\n";
  std::cout << "voraz y programación dinámica dentro del límite de tiempo especificado.\n";
  std::cout << "Posteriormente dichos datos se pueden mandar a pantalla o a un fichero según requiera el usuario.\n\n";
  std::cout << "Parámetros:\n";
  std::cout << "<directorio_ejemplos>: Ruta al directorio de ejemplos.\n";
  std::cout << "<tiempo_limite>: Límite de tiempo en minutos para realizar las operaciones.\n";
}