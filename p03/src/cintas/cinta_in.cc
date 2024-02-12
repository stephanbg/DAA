/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file cinta_in.cc
 * @brief Implementación de la clase CintaIn para representar la cinta de entrada de la Máquina RAM.
 *        La cinta de entrada es utilizada para proporcionar datos de entrada al programa en ejecución.
 * 
 * @see {@link https://docs.google.com/document/d/1n6iua2wSG2UVns-mTA4YdMBVKfKIazkJi4HRzKVKS78/edit}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p02}
 */

#include "cinta_in.h"

/**
 * @brief Construye un nuevo objeto de CintaIn.
 * 
 * @param kNombreFicheroCintaIn Nombre del archivo que contiene los datos de la cinta de entrada.
 */
CintaIn::CintaIn(const std::string& kNombreFicheroCintaIn) {
  std::ifstream archivo(kNombreFicheroCintaIn);
  std::string cinta_in = "";
  std::getline(archivo, cinta_in);
  puntero_ = 0;
  RellenarCinta(cinta_in);
  archivo.close();  
}

/**
 * @brief Rellena la cinta de entrada con los datos proporcionados.
 * 
 * @param kCintaIn Cadena que contiene los datos de la cinta de entrada.
 * @throw Lanza una excepción si algún elemento de la cinta de entrada no
 *        es un número real.
 */
void CintaIn::RellenarCinta(const std::string& kCintaIn) {
  // Reemplaza las comas por puntos para asegurar el formato de los números
  std::string cinta_reemplazada = kCintaIn;
  std::replace(cinta_reemplazada.begin(), cinta_reemplazada.end(), ',', '.');
  std::istringstream iss(cinta_reemplazada);
  const std::string kError = "Los datos de la cinta de entrada "
                             "tienen que ser números reales";
  std::string numero;
  while (iss >> numero) {
    // Verifica si el número es válido
    if (!EsNumero(numero)) throw kError;
    else {
      // Convierte el número a tipo long double y lo añade a la cinta de entrada
      cinta_.push_back(stold(numero));
    }
  }  
}

/**
 * @brief Sobrecarga del operador de inserción para imprimir la cinta de entrada en un flujo de salida.
 * 
 * @param os Flujo de salida donde se imprimirá la cinta de entrada.
 * @param kCinta Objeto de tipo CintaIn que se imprimirá.
 * @return Referencia al flujo de salida para permitir encadenamiento de operadores.
 */
std::ostream& operator<<(std::ostream& os, const CintaIn& kCinta) {
  // Determina el número de decimales necesario para cada número en la cinta
  int numero_decimales = 0;
  const int kSizeCinta = kCinta.get_cinta().size();
  // Imprime cada número de la cinta con el número adecuado de decimales
  for (int i = 0; i < kSizeCinta; ++i) {
    numero_decimales = ContarDecimales(kCinta.get_cinta()[i]);
    os << std::fixed << std::setprecision(numero_decimales) << kCinta.get_cinta()[i];
    if (i < kSizeCinta - 1) os << " ";
  }
  return os;
}