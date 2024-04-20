/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 19 de Abril de 2024
 * @file peticionesUsuario.cc
 * @brief Implementación de funciones que hacen solicitudes al usuario
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p08/src}
 */

#include "peticionesUsuario.h"

/**
 * @brief Solicita al usuario la cantidad de archivos que desea ejecutar.
 * 
 * @param kNombreDir El nombre del directorio donde se encuentran los archivos.
 * @return La cantidad de archivos a ejecutar.
 */
const int cuantosFicherosAEjecutar(const std::string& kNombreDir) {
  const int kNumMaximoFicheros = cantidadMaximaFicheros(kNombreDir);
  int cantidad;
  std::cout << "¿Cuántos ficheros quieres ejecutar? ";
  do {
    std::string input;
    std::getline(std::cin, input);
    if (input.empty()) return cantidadMaximaFicheros(kNombreDir);
    std::stringstream ss(input);
    if (!(ss >> cantidad)) std::cout << "Por favor, introduce un número válido: ";
    else if (cantidad < 1) std::cout << "Por favor, introduce un número mayor que 0: ";
    else {
      if (cantidad > kNumMaximoFicheros) {
        std::cout << "El número debe ser como máximo " << kNumMaximoFicheros << ": ";
      } else return cantidad;
    }
  } while (true);
}

/**
 * @brief Solicita al usuario la cantidad de elementos que desea incluir en la solución.
 * 
 * @param kNombreFichero El nombre del archivo del cual se extrae el número máximo posible de elementos.
 * @return La cantidad de elementos para la solución.
 */
const int cuantosElementosParaSolucion(const std::string& kNombreFichero) {
  std::ifstream archivo(kNombreFichero);
  int numero_maximo_posible, cantidad;
  archivo >> numero_maximo_posible;
  archivo.close();
  std::cout <<
      "¿Cuántos elementos quieres ingresar para la solución? (num > 0 y num <= " << numero_maximo_posible << "): ";
  do {
    std::string input;
    std::getline(std::cin, input);
    if (input.empty()) return numero_maximo_posible;
    std::stringstream ss(input);
    if (!(ss >> cantidad)) std::cout << "Por favor, introduce un número válido: ";
    else if (cantidad < 1 || cantidad > numero_maximo_posible) {
      std::cout << "Por favor, introduce un número > 0 y <= " << numero_maximo_posible << ": ";
    } else return cantidad;
  } while (true);
}

/**
 * @brief Pregunta al usuario si desea mostrar las tablas por pantalla o por fichero.
 * @return La respuesta del usuario (P para pantalla, F para fichero).
 */
const std::string peticionUsuarioTablaPantallaOFichero() {
  std::cout << "Quieres mostrar las tablas por pantalla o por fichero [P|F]: ";
  std::string opcion = "";
  while (std::cin >> opcion && opcion != "P" && opcion != "F") {
    std::cout << "Tiene que escribir [P|F]: ";
  }
  return opcion;
}