/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file funciones_necesarias.cc
 * @brief Implementación de funciones necesarias para todo el programa
 * 
 * @see {@link https://docs.google.com/document/d/1zf_w2HtS4zJX3iqr9yPm6f7rRNsrBxL7afCsMapujMQ/edit#heading=h.5bq8rsdy1ujx}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p03}
 */

#include "funciones_necesarias.h"

/**
 * @brief Cuenta el número de dígitos decimales en un número de punto flotante.
 * 
 * @param kNumero El número de punto flotante del cual contar los dígitos decimales.
 * @return El número de dígitos decimales.
 */
int ContarDecimales(const long double kNumero) {
  // Convertir el número a una cadena
  const std::string kCadena = std::to_string(kNumero);
  // Buscar el punto decimal en la cadena
  const size_t kPosPunto = kCadena.find('.');
  // Contar los dígitos después de él sin incluir ceros a la derecha
  const size_t kPosNoCero = kCadena.find_last_not_of('0');
  if (kPosNoCero != std::string::npos && kPosNoCero > kPosPunto) {
    return kPosNoCero - kPosPunto;
  }
  // Si no se encuentra el punto decimal, o todos los dígitos a la derecha
  // son ceros, no hay decimales
  return 0;
}

/**
 * @brief Verifica si una cadena representa un número válido.
 * 
 * @param kCadena La cadena que se va a verificar.
 * @return true si la cadena representa un número válido, false en caso contrario.
 */
bool EsNumero(const std::string& kCadena) {
  const std::regex kPatron("^[+-]?\\d*[.,]?\\d+$");
  return std::regex_match(kCadena, kPatron);
}

/**
 * @brief Convierte una cadena a mayúsculas.
 * 
 * @param kCadena La cadena que se va a convertir a mayúsculas.
 * @return La cadena convertida a mayúsculas.
 */
const std::string ConvertirAMayusculas(const std::string& kCadena) {
  std::string palabras_en_mayusculas = kCadena;
  // Convertir a mayúsculas usando std::transform
  std::transform(palabras_en_mayusculas.begin(), palabras_en_mayusculas.end(),
                 palabras_en_mayusculas.begin(), ::toupper);
  return palabras_en_mayusculas;  
}

/**
 * @brief Elimina los espacios en blanco de una cadena.
 * 
 * @param kCadena La cadena de la cual se eliminarán los espacios en blanco.
 * @return La cadena sin espacios en blanco.
 */
const std::string QuitarEspacios(const std::string& kCadena) {
  std::string resultado = kCadena;
  resultado.erase(std::remove_if(resultado.begin(), resultado.end(), ::isspace), resultado.end());
  return resultado;
}

/**
 * @brief Elimina las coincidencias de una lista de cadenas de otra cadena.
 * 
 * @param kVectorCoincidencias El vector que contiene las cadenas a eliminar.
 * @param linea La cadena de la cual se eliminarán las coincidencias.
 */
void EliminarCoincidencias(const std::vector<std::string>& kVectorCoincidencias,
                           std::string& linea) {
  const int kSizeVectorCoincidencias = kVectorCoincidencias.size();
  size_t pos;
  for (int i = 0; i < kSizeVectorCoincidencias; ++i) {
    pos = linea.find(kVectorCoincidencias[i]);
    if (pos != std::string::npos) linea.erase(pos, kVectorCoincidencias[i].size()); 
  }
}

/**
 * @brief Verifica si una cadena contiene solo dígitos.
 * 
 * @param kCadena La cadena que se va a verificar.
 * @return true si la cadena contiene solo dígitos, false en caso contrario.
 */
bool sonTodoDigitos(const std::string& kCadena) {
  // Verificar si todos los caracteres en operando son dígitos
  for (char c : kCadena) {
    if (!std::isdigit(c)) {
      return false;
    }
  }
  return true;
}

bool esOperandoVectorial(const std::string& kCadena) {
  const std::regex kPatron("^\\d+\\[\\d+\\]$");
  return std::regex_match(kCadena, kPatron);
}