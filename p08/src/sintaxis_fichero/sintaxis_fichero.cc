/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 20 de Marzo de 2024
 * @file sintaxis_fichero.cc
 * @brief Implementación de la clase SintaxisFichero
 * que comprueba la sintaxis de los ficheros que contienen descripciones para
 * el problema Parallel Machine Scheduling Problem with Dependent Setup Times
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07/src}
 */

#include "sintaxis_fichero.h"

/**
 * @brief Comprueba la sintaxis del archivo especificado.
 * 
 * @param kNombreDirYFichero Nombre del directorio y archivo que contiene la información.
 */
void SintaxisFichero::comprobarSintaxisFichero(const std::string& kNombreDirYFichero) {
  std::ifstream archivo(kNombreDirYFichero);
  std::string cada_linea = "", error = "(sintaxis) ";
  int contador_lineas = 0, numero_de_puntos, numero_de_dimensiones;
  while (getline(archivo, cada_linea)) {
    // Ignorar líneas vacías
    if (contador_lineas >= 0 && ((contador_lineas - 2) < numero_de_puntos)) {
      if (std::all_of(cada_linea.begin(), cada_linea.end(), [](char c) { return std::isspace(c); })) {
        error += "línea " + std::to_string(contador_lineas + 1) + " vacía";
        throw (error);
      }
    } else break;
    if (contador_lineas == 0 && !SintaxisFichero::numeroPuntosValidos(cada_linea, numero_de_puntos)) {
      error += "número de puntos en el espacio > 0";
    } else if (contador_lineas == 1 && !SintaxisFichero::numeroDimensionesValidas(cada_linea, numero_de_dimensiones)) {
      error += "número de dimensiones del espacio > 0";
    } else if (contador_lineas > 1 && !SintaxisFichero::coordenadasValidas(cada_linea, numero_de_dimensiones)) {
      error += "coordenadas no válidas";
    }
    if (error != "(sintaxis) ") throw(error);
    contador_lineas++;   
  }
  if ((contador_lineas - 2) > numero_de_puntos) error += "número de puntos por encima de " + std::to_string(numero_de_puntos);
  else if ((contador_lineas - 2) < numero_de_puntos) error += "número de puntos por debajo de " + std::to_string(numero_de_puntos);
  if (error != "(sintaxis) ") throw(error);
}

bool SintaxisFichero::numeroPuntosValidos(const std::string& kCadaLinea, int& numero_de_puntos) {
  try {
    numero_de_puntos = std::stoi(kCadaLinea);
    return (numero_de_puntos > 0);
  } catch (const std::invalid_argument& kError) {
    return false; // No se pudo convertir a número
  } catch (const std::out_of_range& kError) {
    return false; // Número fuera de rango
  }
}

bool SintaxisFichero::numeroDimensionesValidas(const std::string& kCadaLinea, int& numero_de_dimensiones) {
  try {
    numero_de_dimensiones = std::stoi(kCadaLinea);
    return (numero_de_dimensiones > 0);
  } catch (const std::invalid_argument& kError) {
    return false; // No se pudo convertir a número
  } catch (const std::out_of_range& kError) {
    return false; // Número fuera de rango
  }
}

bool SintaxisFichero::coordenadasValidas(
  const std::string& kCadaLinea, const int kNumDimensiones
) {
  std::istringstream iss(kCadaLinea);
  std::vector<std::string> palabras(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());
  if (palabras.size() != kNumDimensiones) return false; // Número incorrecto de coordenadas
  for (std::string& palabra : palabras) {
    if (!tieneCaracteresNumericosYUnPuntoDecimal(palabra)) return false;
  }
  return true; // Todas las palabras son coordenadas válidas
}
