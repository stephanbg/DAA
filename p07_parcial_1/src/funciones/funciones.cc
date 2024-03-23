/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Marzo de 2024
 * @file funciones.cc
 * @brief Implementación de funciones necesarias para todo el programa
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p06/src}
 * @see {@link https://docs.google.com/document/d/1a691HPtHQL4qBtI2qaTMTp23wxZvU8-CCIbGOyNJRQo/edit}
 */

#include "funciones.h"

/**
 * @brief Verifica si el vector contiene al menos un elemento falso.
 * 
 * @param booleanos Vector de booleanos.
 * @return true si el vector contiene al menos un falso, false en caso contrario.
 */
const bool contieneFalso(const std::vector<bool>& booleanos) {
  for (bool b : booleanos) {
    if (!b) return true;
  }
  return false;
}

/**
 * @brief Verifica si una cadena representa un número entero sin signo.
 * 
 * @param kNumeroEnCadena Cadena que representa el número.
 * @return true si la cadena representa un número entero sin signo, false en caso contrario.
 */
const bool esNumeroEnteroSinSigno(const std::string& kNumeroEnCadena) {
  if (kNumeroEnCadena[0] == '+' || kNumeroEnCadena[0] == '-') return false;
  const int kSizeNumero = kNumeroEnCadena.size();
  for (int i = 0; i < kSizeNumero; ++i) {
    if (kNumeroEnCadena[i] < '0' ||  kNumeroEnCadena[i] > '9') return false;
  }
  return true;
}

/**
 * @brief Verifica si una cadena representa un número sin signo (entero o decimal).
 * 
 * @param kNumeroEnCadena Cadena que representa el número.
 * @return true si la cadena representa un número sin signo, false en caso contrario.
 */
/*const bool esNumeroSinSigno(const std::string& kNumeroEnCadena) {
  if (kNumeroEnCadena.empty()) return false;
  bool haHabidoPunto = false;
  for (char c : kNumeroEnCadena) {
    if (c == '.' || c == ',') {
      // Si ya ha habido un punto o coma, significa que hay más de uno en la cadena
      if (haHabidoPunto) return false;
      haHabidoPunto = true;
    } else if (c < '0' || c > '9') return false;
  }
  return true;
}*/

/**
 * @brief Sustituye las comas por puntos en una cadena.
 * 
 * @param kCadena Cadena de entrada.
 * @return Cadena resultante después de la sustitución.
 */
/*const std::string sustituirComasPorPunto(const std::string& kCadena) {
  std::string cadena_resultante = kCadena;
  for (char& caracter : cadena_resultante) {
    if (caracter == ',') caracter = '.';
  }
  return cadena_resultante;
}*/

/**
 * @brief Formatea un número en notación decimal.
 * 
 * @param numero Número a formatear.
 * @return Cadena que representa el número formateado.
 */
/*const std::string formatearNumero(const long double numero) {
  std::stringstream stream;
  stream << std::fixed << numero; // Fijar la precisión decimal
  std::string resultado = stream.str();
  // Eliminar los ceros innecesarios después del punto decimal
  size_t pos = resultado.find_last_not_of('0');
  if (pos != std::string::npos && resultado[pos] == '.') resultado.erase(pos);
  else if (pos != std::string::npos) resultado.erase(pos + 1);
  return resultado;
}*/
