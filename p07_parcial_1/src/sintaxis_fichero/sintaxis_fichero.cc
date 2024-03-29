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
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07_parcial_1/src}
 */

#include "sintaxis_fichero.h"

/**
 * @brief Comprueba la sintaxis del archivo especificado.
 * 
 * @param kNombreDirYFichero Nombre del directorio y archivo que contiene la información.
 */
void SintaxisFichero::comprobarSintaxisFichero(const std::string& kNombreDirYFichero) {
  fs::path ruta_actual = fs::current_path();
  fs::path ruta_completa = ruta_actual / kNombreDirYFichero; 
  std::ifstream archivo(ruta_completa);
  std::string cada_linea = "", error = "(sintaxis) ";
  std::pair<int, int> rango_setup;
  int contador_lineas = 0, contador_setup = 0;
  while (getline(archivo, cada_linea)) {
    if (contador_lineas == 0 && !SintaxisFichero::numeroNodosValido(cada_linea)) {
      error += "número de nodos";
    } else if (contador_lineas == 1 && !SintaxisFichero::numeroMaquinasValido(cada_linea)) {
      error += "número de máquinas";
    } else if (contador_lineas == 2 && !SintaxisFichero::tiemposProcesamientoValidos(cada_linea)) {
      error += "los rangos de los tiempos de procesamiento";
    } else if (contador_lineas == 3) extraerRangosSetUp(cada_linea, rango_setup);
    else if (
      contador_lineas > 3 &&
      !SintaxisFichero::tiemposSetUpValidos(cada_linea, rango_setup, contador_setup++)
    ) {
      if (rango_setup.first == -1 && rango_setup.second == -1) {
        error += "Rangos setup, algún elemento en la diagonal no es 0 o algún elemento no es positivo";
      } else if (rango_setup.first != -1 && rango_setup.second == -1) {
        error += "Rangos setup, no están dentro del rango ["
            + std::to_string(rango_setup.first) + "-∞], o las diagonales no son 0";
      } else if (rango_setup.first == -1 && rango_setup.second != -1) {
        error += "Rangos setup, no están dentro del rango [1-"
            + std::to_string(rango_setup.second) + "], o las diagonales no son 0";
      } else {
        error += "Rangos setup, no están dentro del rango [" + std::to_string(rango_setup.first)
            + "-" + std::to_string(rango_setup.second) + "], o las diagonales no son 0";
      }
    }
    if (error != "(sintaxis) ") throw(error);
    contador_lineas++;    
  }
}

/**
 * @brief Verifica si la línea que contiene el número de nodos es válida.
 * 
 * @param kCadaLinea Línea del archivo.
 * @return Devuelve true si el número de nodos es válido, de lo contrario false.
 */
const bool SintaxisFichero::numeroNodosValido(const std::string& kCadaLinea) {
  std::regex regex_num_nodos("n:\\s+[1-9][0-9]*\\s*");
  return std::regex_match(kCadaLinea, regex_num_nodos);
}

/**
 * @brief Verifica si la línea que contiene el número de máquinas es válida.
 * 
 * @param kCadaLinea Línea del archivo.
 * @return Devuelve true si el número de máquinas es válido, de lo contrario false.
 */
const bool SintaxisFichero::numeroMaquinasValido(const std::string& kCadaLinea) {
  std::regex regex_num_maquinas("m:\\s+[1-9][0-9]*\\s*");
  return std::regex_match(kCadaLinea, regex_num_maquinas);
}

/**
 * @brief Verifica si la línea que contiene los tiempos de procesamiento es válida.
 * 
 * @param kCadaLinea Línea del archivo.
 * @return Devuelve true si los tiempos de procesamiento son válidos, de lo contrario false.
 */
const bool SintaxisFichero::tiemposProcesamientoValidos(const std::string& kCadaLinea) {
  std::stringstream ss(kCadaLinea);
  std::string palabra = "";
  std::pair<int, int> rango_procesamientos;
  ss >> palabra;
  extraerRangosProcesamientos(palabra, rango_procesamientos);
  while (ss >> palabra) {
    if (!esNumeroEnteroSinSigno(palabra) || stoi(palabra) == 0) return false;
    else if (rango_procesamientos.first == -1 && rango_procesamientos.second == -1) continue;
    else if (rango_procesamientos.first != -1 && rango_procesamientos.second == -1) {
      if (stoi(palabra) < rango_procesamientos.first) return false;
    } else if (rango_procesamientos.first == -1 && rango_procesamientos.second != -1) {
      if (stoi(palabra) > rango_procesamientos.second) return false;
    } else if (
      stoi(palabra) < rango_procesamientos.first || stoi(palabra) > rango_procesamientos.second
    ) return false;
  }
  return true;
}

/**
 * @brief Extrae los rangos de tiempos de procesamiento de una palabra.
 * 
 * @param kPalabra Palabra que contiene los rangos.
 * @param rango_procesamientos Par que almacenará los rangos de tiempos de procesamiento.
 */
void SintaxisFichero::extraerRangosProcesamientos(
  const std::string& kPalabra,
  std::pair<int, int>& rango_procesamientos
) {
  const size_t kPosInicio = kPalabra.find_first_of("0123456789");
  const size_t kPosGuion = kPalabra.find('-');
  if (kPosInicio == std::string::npos || kPosGuion == std::string::npos) {
    rango_procesamientos.first = -1;
    rango_procesamientos.second = -1;
    return;
  }
  if (kPosInicio < kPosGuion) {
    rango_procesamientos.first = std::stoi(kPalabra.substr(kPosInicio, kPosGuion - kPosInicio));
  } else rango_procesamientos.first = -1;
  const size_t kPosFinal = kPalabra.find_last_of("0123456789", kPalabra.size() - 1);
  if (kPosFinal == std::string::npos || kPosFinal <= kPosGuion) {
    rango_procesamientos.second = -1;
    return;
  }
  rango_procesamientos.second = std::stoi(kPalabra.substr(kPosGuion + 1, kPosFinal - kPosGuion));
}

/**
 * @brief Extrae los rangos de tiempos de setup de una palabra.
 * 
 * @param kPalabra Palabra que contiene los rangos.
 * @param rangos_setup Par que almacenará los rangos de tiempos de setup.
 */
void SintaxisFichero::extraerRangosSetUp(
  const std::string& kPalabra,
  std::pair<int, int>& rangos_setup
) {
  const size_t kPosInicio = kPalabra.find_first_of("0123456789");
  const size_t kPosGuion = kPalabra.find('-');
  if (kPosInicio == std::string::npos || kPosGuion == std::string::npos) {
    rangos_setup.first = -1;
    rangos_setup.second = -1;
    return;
  }
  if (kPosInicio < kPosGuion) {
    rangos_setup.first = std::stoi(kPalabra.substr(kPosInicio, kPosGuion - kPosInicio));
  } else rangos_setup.first = -1;
  const size_t kPosFinal = kPalabra.find_last_of("0123456789", kPalabra.size() - 1);
  if (kPosFinal == std::string::npos || kPosFinal <= kPosGuion) {
    rangos_setup.second = -1;
    return;
  }
  rangos_setup.second = std::stoi(kPalabra.substr(kPosGuion + 1, kPosFinal - kPosGuion));
}

/**
 * @brief Verifica si los tiempos de setup son válidos en una línea.
 * 
 * @param kCadaLinea Línea del archivo.
 * @param kRangoSetup Rango de tiempos de setup permitidos.
 * @param kContadorLineas Número de línea actual.
 * @return Devuelve true si los tiempos de setup son válidos, de lo contrario false.
 */
const bool SintaxisFichero::tiemposSetUpValidos(
  const std::string& kCadaLinea,
  const std::pair<int, int>& kRangoSetup,
  const int kContadorLineas
) {
  std::stringstream ss(kCadaLinea);
  std::string palabra = "";
  int contador_palabras = -1;
  while (ss >> palabra) {
    contador_palabras++;
    if (!esNumeroEnteroSinSigno(palabra)) return false;
    else if (contador_palabras == kContadorLineas && stoi(palabra) != 0) return false;
    else if (contador_palabras != kContadorLineas && stoi(palabra) == 0) return false;
    else if (kRangoSetup.first == -1 && kRangoSetup.second == -1) continue;
    else if (contador_palabras != kContadorLineas) {
      if (kRangoSetup.first != -1 && kRangoSetup.second == -1) {
        if (stoi(palabra) < kRangoSetup.first) return false;
      } else if (kRangoSetup.first == -1 && kRangoSetup.second != -1) {
        if (stoi(palabra) > kRangoSetup.second) return false;      
      } else if (stoi(palabra) < kRangoSetup.first || stoi(palabra) > kRangoSetup.second) return false;
    }
  }
  return true;
}