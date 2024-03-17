/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Marzo de 2024
 * @file comprobar_aprametros.cc
 * @brief Implementación de la clase ComprobarParametros, que comprueba la línea de comandos
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p06/src}
 * @see {@link https://docs.google.com/document/d/1a691HPtHQL4qBtI2qaTMTp23wxZvU8-CCIbGOyNJRQo/edit}
 */

#include "comprobar_parametros.h"

/**
 * @brief Comprueba los parámetros de entrada del programa.
 * 
 * @param argc Cantidad de argumentos de línea de comandos.
 * @param argv Vector de argumentos de línea de comandos.
 * @throws Mensaje de error si los parámetros no son correctos.
 */
void ComprobarParametros::comprobar(const int argc, char *argv[]) {
  std::string mensaje_error = "";
  if (!ComprobarParametros::cantidadParametrosCorrecta(argc)) {
    mensaje_error = "Tienen que ser 3 parámetros";
  } else {
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

/**
 * @brief Comprueba si la cantidad de parámetros es correcta.
 * 
 * @param kNumParametros Cantidad de argumentos de línea de comandos.
 * @return Verdadero si la cantidad de parámetros es correcta, falso en caso contrario.
 */
bool ComprobarParametros::cantidadParametrosCorrecta(const int kNumParametros) {
  return (kNumParametros == 3);
}

/**
 * @brief Comprueba si existe el directorio especificado.
 * 
 * @param kNombreDirectorio Ruta del directorio a comprobar.
 * @return Verdadero si el directorio existe, falso en caso contrario.
 */
bool ComprobarParametros::existeDirectorio(const std::string& kNombreDirectorio) {
  return fs::is_directory(kNombreDirectorio);
}

/**
 * @brief Comprueba si el directorio especificado es el directorio de ejemplos.
 * 
 * @param kNombreDirectorio Ruta del directorio a comprobar.
 * @return Verdadero si el directorio es el directorio de ejemplos, falso en caso contrario.
 */
bool ComprobarParametros::esDirectorioEjemplos(const std::string& kNombreDirectorio) {
  return kNombreDirectorio == "ejemplos";
}

/**
 * @brief Comprueba si el valor de minutos es correcto.
 * 
 * @param kTiempoLimite Valor de minutos a comprobar.
 * @return Verdadero si el valor de minutos es correcto, falso en caso contrario.
 */
bool ComprobarParametros::valorMinutosCorrecto(const std::string& kTiempoLimite) {
  if (!esNumeroEnteroSinSigno(kTiempoLimite)) return false;
  return stoi(kTiempoLimite) >= 1;
}

/**
 * @brief Muestra la ayuda del programa.
 */
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