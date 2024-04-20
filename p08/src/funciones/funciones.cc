/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 19 de Abril de 2024
 * @file funciones.cc
 * @brief Implementación de funciones necesarias
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p08/src}
 */

#include "funciones.h"

/**
 * @brief Extrae los nombres de los archivos de ejemplo del directorio especificado.
 * 
 * @param kNombreDir El nombre del directorio del cual se extraen los nombres de los archivos.
 * @return Un vector de cadenas que contiene los nombres de los archivos de ejemplo (ordenados alfabéticamente).
 */
std::vector<std::string> extraerFicherosEjemplo(const std::string& kNombreDir) {
  std::vector<std::string> nombres_ficheros;
  int num_ficheros = 0;
  const int kCantidadFicherosPedidosPorUsr = cuantosFicherosAEjecutar(kNombreDir);
  fs::path directorio_absoluto = fs::absolute(kNombreDir);
  for (const auto& kEntrada : fs::directory_iterator(kNombreDir)) {
    if (kEntrada.is_regular_file()) {
      fs::path ruta_absoluta = directorio_absoluto / kEntrada.path().filename();
      nombres_ficheros.push_back(ruta_absoluta.string());
      if (++num_ficheros == kCantidadFicherosPedidosPorUsr) break;
    }
  }
  std::sort(nombres_ficheros.begin(), nombres_ficheros.end());
  return nombres_ficheros;
}

/**
 * @brief Obtiene la cantidad máxima de archivos en el directorio especificado.
 * 
 * @param kNombreDir El nombre del directorio del cual se desea obtener la cantidad máxima de archivos.
 * @return La cantidad máxima de archivos en el directorio.
 */
const int cantidadMaximaFicheros(const std::string& kNombreDir) {
  int num_ficheros = 0;
  for (const auto& kEntrada : fs::directory_iterator(kNombreDir)) {
    if (kEntrada.is_regular_file()) ++num_ficheros;
  }
  return num_ficheros;
}

/**
 * @brief Reemplaza la primera coma decimal por punto en una cadena dada.
 * 
 * @param kCadena La cadena en la que se desea reemplazar la coma decimal.
 * @return La cadena con la coma decimal reemplazada por punto si es que hubiese.
 */
const std::string reemplazarComaDecimalPorPunto(const std::string& kCadena) {
  std::string cadena = kCadena;
  const size_t kPos = cadena.find(',');
  if (kPos != std::string::npos) cadena[kPos] = '.';
  return cadena;
}

/**
 * @brief Cuenta la cantidad de decimales en un número dado.
 * 
 * @param kNumero El número del cual se desea contar la cantidad de decimales.
 * @param kPrecisionMax La precisión máxima para la cuenta de decimales.
 * @return La cantidad de decimales en el número dado.
 */
const int contarDecimales(const double kNumero, const int kPrecisionMax) {
  std::stringstream ss;
  ss << std::fixed << std::setprecision(kPrecisionMax) << kNumero;
  std::string kNumeroStr = ss.str();
  const size_t puntoPos = kNumeroStr.find('.');
  if (puntoPos == std::string::npos) return 0; // No hay decimales
  const int kSizeNumero = kNumeroStr.size();
  int contador_decimales = 0, contador_ceros = 0;
  for (int i = puntoPos + 1; i < kSizeNumero; ++i) {
    if (kNumeroStr[i] != '0') {
      if (contador_ceros > 0) {
        contador_decimales += contador_ceros;
        contador_ceros = 0;
      }
      contador_decimales++;
    }
    else contador_ceros++;
  } 
  return contador_decimales;
}

/**
 * @brief Extrae el nombre de un archivo de una ruta completa.
 * 
 * @param kRuta La ruta del archivo del cual se desea extraer el nombre.
 * @return El nombre del archivo extraído de la ruta.
 */
std::string extraerNombreFicheroDeRuta(const std::string& kRuta) {
  return std::filesystem::path(kRuta).filename().string();
}

/**
 * @brief Verifica si una palabra contiene solo caracteres numéricos y un único punto decimal.
 * 
 * @param palabra La palabra que se desea verificar.
 * @return true si la palabra contiene solo caracteres numéricos y un único punto decimal, false en caso contrario.
 */
bool tieneCaracteresNumericosYUnPuntoDecimal(const std::string& palabra) {
  bool punto_decimal_encontrado = false;
  for (char caracter : palabra) {
    if (!std::isdigit(caracter)) {
      if ((caracter == '.' ||caracter == ',') && !punto_decimal_encontrado) punto_decimal_encontrado = true;
      else return false; // Caracter no numérico o más de un punto decimal
    }
  }
  return true; // La palabra contiene solo caracteres numéricos y un único punto decimal
}