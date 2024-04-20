/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 19 de Abril de 2024
 * @file comprobar_parametros.cc
 * @brief Implementación de la clase ComprobarParametros, que comprueba la línea de comandos
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p08/src}
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
    mensaje_error = "Tienen que ser 2 parámetros";
  } else {
    if (!ComprobarParametros::existeDirectorio(argv[1])) {
      mensaje_error = "El directorio '" + std::string(argv[1]) + "' no existe";
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
  return (kNumParametros == 2);
}

/**
 * @brief Comprueba si existe el directorio
 * 
 * @param kRuta La ruta hacia el directorio
 * @return Devuelve true si lo encuentra si no false;
 */
bool ComprobarParametros::existeDirectorio(const std::string& kRuta) {
  return fs::exists(kRuta);
}

/**
 * @brief Muestra la ayuda del programa.
 */
void ComprobarParametros::ayuda() {
  std::cout << "Uso: programa <directorio_ejemplo>\n\n";
  std::cout << "Descripción:\n";
  std::cout << "Este programa lee un fichero, que contiene las coordenadas de 'n' puntos en un espacio de 'k' dimensiones\n";
  std::cout << "Se crean dos matrices (coordenadas y distancias) a partir de esa información y se realiza el algoritmo voraz.\n";
  std::cout << "Posteriormente dichos datos se pueden mandar a pantalla o a un fichero según requiera el usuario.\n\n";
  std::cout << "Parámetros:\n";
  std::cout << "<directorio_ejemplo>: Directorio donde se encuentran los ficheros de ejemplo.\n";
}