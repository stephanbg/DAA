/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 20 de Marzo de 2024
 * @file comprobar_aprametros.cc
 * @brief Implementación de la clase ComprobarParametros, que comprueba la línea de comandos
 * @see {@link link https://github.com/stephanbg/DAA/tree/main/p07/src}
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
    if (!ComprobarParametros::existeFichero(argv[1])) {
      mensaje_error = "El fichero '" + std::string(argv[1]) + "' no existe";
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
 * @brief Comprueba si existe el fichero
 * 
 * @param kRuta La ruta hacia el fichero
 * @return Devuelve true si lo encuentra si no false;
 */
bool ComprobarParametros::existeFichero(const std::string& kRuta) {
  return fs::exists(kRuta);
}

/**
 * @brief Muestra la ayuda del programa.
 */
void ComprobarParametros::ayuda() {
  std::cout << "Uso: programa <fichero_ejemplo>\n\n";
  std::cout << "Descripción:\n";
  std::cout << "Este programa lee un fichero, que contiene\n";
  std::cout << "la descripción de los tiempos de procesamiento, los tiempos de setup, el número de nodos y máquinas.\n";
  std::cout << "Se crea el grafo a partir de esa información y se realizan los algoritmos voraz y GRASP.\n";
  std::cout << "Posteriormente dichos datos se pueden mandar a pantalla o a un fichero según requiera el usuario.\n\n";
  std::cout << "Parámetros:\n";
  std::cout << "<fichero_ejemplo>: Fichero ejemplo.\n";
}