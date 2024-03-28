/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Marzo de 2024
 * @file sintaxis_fichero_grafo.cc
 * @brief Implementación de la clase SintaxisFicheroGrafo
 * que comrpueba la sintaxis de los ficheros que contienen descripciones de grafos
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p06/src}
 * @see {@link https://docs.google.com/document/d/1a691HPtHQL4qBtI2qaTMTp23wxZvU8-CCIbGOyNJRQo/edit}
 */

#include "sintaxis_fichero_grafo.h"

void SintaxisFicheroGrafo::comprobarSintaxisFichero(const std::string& kNombreDirYFichero) {
  fs::path ruta_actual = fs::current_path();
  fs::path ruta_completa = ruta_actual / kNombreDirYFichero; 
  std::ifstream archivo(ruta_completa);
  std::string cada_linea = "", error = "(sintaxis) ";
  std::pair<int, int> rango_setup;
  int contador_lineas = 0, contador_setup = 0;
  while (getline(archivo, cada_linea)) {
    if (contador_lineas == 0 && !SintaxisFicheroGrafo::numeroNodosValido(cada_linea)) {
      error += "número de nodos";
    } else if (contador_lineas == 1 && !SintaxisFicheroGrafo::numeroMaquinasValido(cada_linea)) {
      error += "número de máquinas";
    } else if (contador_lineas == 2 && !SintaxisFicheroGrafo::tiemposProcesamientoValidos(cada_linea)) {
      error += "los rangos de los tiempos de procesamiento";
    } else if (contador_lineas == 3 && !SintaxisFicheroGrafo::rangosSetUpValidos(cada_linea, rango_setup)) {
      error += "rango de los tiempos de setup no válidos";
    } else if (
      contador_lineas > 3 &&
      !SintaxisFicheroGrafo::tiemposSetUpValidos(cada_linea, rango_setup, contador_setup++)
    ) {       
        error += "rango de los tiempos de setup no están dentro del rango [" + std::to_string(rango_setup.first)
        + "-" + std::to_string(rango_setup.second) + "], o las diagonales no son 0";
    }
    if (error != "(sintaxis) ") throw(error);
    contador_lineas++;    
  }
}

const bool SintaxisFicheroGrafo::numeroNodosValido(const std::string& kCadaLinea) {
  std::regex regex_num_nodos("n:\\s+[1-9][0-9]*\\s*");
  return std::regex_match(kCadaLinea, regex_num_nodos);
}

const bool SintaxisFicheroGrafo::numeroMaquinasValido(const std::string& kCadaLinea) {
  std::regex regex_num_maquinas("m:\\s+[1-9][0-9]*\\s*");
  return std::regex_match(kCadaLinea, regex_num_maquinas);
}

const bool SintaxisFicheroGrafo::tiemposProcesamientoValidos(const std::string& kCadaLinea) {
  std::stringstream ss(kCadaLinea);
  std::string palabra = "";
  std::pair<int, int> rango_procesamientos;
  ss >> palabra;
  if (!rangosProcesamientosValidos(palabra, rango_procesamientos)) return false;
  while (ss >> palabra) {
    if (!esNumeroEnteroSinSigno(palabra)) return false;
    else if (
      stoi(palabra) < rango_procesamientos.first || stoi(palabra) > rango_procesamientos.second
    ) return false;
  }
  return true;
}

const bool SintaxisFicheroGrafo::rangosProcesamientosValidos(
  const std::string& kPalabra,
  std::pair<int, int>& rango_procesamientos
) {
  std::regex regex_rangos_procesamientos("^Pi:?U?\\[(\\d+)-([1-9]\\d*|0[1-9]\\d*)\\]");
  if (!std::regex_match(kPalabra, regex_rangos_procesamientos)) return false;
  const size_t kPosCorcheteInicio = kPalabra.find('[');
  const size_t kPosGuion = kPalabra.find('-', kPosCorcheteInicio);
  const size_t kPosCorcheteFin = kPalabra.find(']', kPosGuion);
  rango_procesamientos.first = stoi(kPalabra.substr(kPosCorcheteInicio + 1, kPosGuion));
  rango_procesamientos.second = stoi(kPalabra.substr(kPosGuion + 1, kPosCorcheteFin));
  return true;
}

const bool SintaxisFicheroGrafo::rangosSetUpValidos(
  const std::string& kCadaLinea,
  std::pair<int, int>& rango_setup
) {
  std::regex regex_rangos_setup("^Sij:?U?\\[(\\d+)-([1-9]\\d*|0[1-9]\\d*)\\]\\s*");
  if (!std::regex_match(kCadaLinea, regex_rangos_setup)) return false;
  const size_t kPosCorcheteInicio = kCadaLinea.find('[');
  const size_t kPosGuion = kCadaLinea.find('-', kPosCorcheteInicio);
  const size_t kPosCorcheteFin = kCadaLinea.find(']', kPosGuion);
  rango_setup.first = stoi(kCadaLinea.substr(kPosCorcheteInicio + 1, kPosGuion));
  rango_setup.second = stoi(kCadaLinea.substr(kPosGuion + 1, kPosCorcheteFin));
  return true;
}

const bool SintaxisFicheroGrafo::tiemposSetUpValidos(
  const std::string& kCadaLinea,
  const std::pair<int, int>& kRangoSetup,
  const int kContadorLineas
) {
  std::stringstream ss(kCadaLinea);
  std::string palabra = "";
  int contador_palabras = 0;
  while (ss >> palabra) {
    if (!esNumeroEnteroSinSigno(palabra)) return false;
    else if (contador_palabras == kContadorLineas) {
      if (stoi(palabra) != 0) return false;
    } else {
      if (stoi(palabra) < kRangoSetup.first || stoi(palabra) > kRangoSetup.second) return false;
    }
    contador_palabras++;
  }
  return true;
}