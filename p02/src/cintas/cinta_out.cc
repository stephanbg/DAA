/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file cinta_out.cc
 * @brief Implementación de la clase CintaOut para representar la cinta de salida de la Máquina RAM.
 *        La cinta de salida es utilizada para almacenar los datos que se han obtenido al ejecutar el programa.
 * 
 * @see {@link https://docs.google.com/document/d/1n6iua2wSG2UVns-mTA4YdMBVKfKIazkJi4HRzKVKS78/edit}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p02}
 */

#include "cinta_out.h"

/**
 * @brief Guarda los datos de la cinta de salida en un archivo.
 * 
 * @param kNombreFichero Nombre del archivo donde se guardarán los datos.
 * @throw Lanza una excepción si no se pudo abrir el fichero o cerrar. 
 */
void CintaOut::MeterEnFichero(const std::string& kNombreFichero) {
  std::ofstream archivo_salida(kNombreFichero);
  const std::string kErrorApertura = "Apertura de archivo de salida.";
  const std::string kErrorCierre = "Cierre de archivo de salida.";
  if (!archivo_salida.is_open()) throw (kErrorApertura);
  const int kSizeCintaOut = cinta_.size();
  for (int i = 0; i < kSizeCintaOut; ++i) {
    archivo_salida << cinta_[i];
    if (i < kSizeCintaOut - 1) archivo_salida << " ";
  }
  archivo_salida.close();
  if (archivo_salida.is_open()) throw (kErrorCierre);
}

/**
 * @brief Sobrecarga del operador de inserción para imprimir los datos de la cinta de salida en un flujo de salida.
 * 
 * @param os Flujo de salida donde se imprimirán los datos.
 * @param kCinta Objeto de tipo CintaOut que contiene los datos a imprimir.
 * @return Referencia al flujo de salida para permitir la concatenación de operaciones de salida.
 */
std::ostream& operator<<(std::ostream& os, const CintaOut& kCinta) {
  // Determina el número de decimales necesario para cada número en la cinta
  int numero_decimales = 0;
  const int kSizeCintaOut = kCinta.cinta_.size();
  // Imprime cada número de la cinta con el número adecuado de decimales
  for (int i = 0; i < kSizeCintaOut; ++i) {
    numero_decimales = ContarDecimales(kCinta.cinta_[i]);
    os << std::fixed << std::setprecision(numero_decimales) << kCinta.cinta_[i];
    if (i < kSizeCintaOut - 1) os << " ";
  }
  return os;
}