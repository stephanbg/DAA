/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 19 de Abril de 2024
 * @file problema.cc
 * @brief Implementación de la clase Problema para representar un problema
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p08/src}
 */

#include "problema.h"

/**
 * @brief Construye un nuevo objeto Problema a partir de un archivo.
 * 
 * @param kNombreFichero El nombre del archivo que contiene los datos del problema.
 */
Problema::Problema(const std::string& kNombreFichero) {
  std::ifstream fichero(kNombreFichero);
  construirMatrices(fichero);
  rellenarDatosCoordenadas(fichero);
  rellenarDatosDistancias();
  fichero.close();
}

/**
 * @brief Construye las matrices de coordenadas y distancias del problema.
 * 
 * @param fichero El archivo que contiene los datos del problema.
 */
void Problema::construirMatrices(std::ifstream& fichero) {
  std::string cada_linea = "";
  getline(fichero, cada_linea);
  const int kNumElementos = std::stoi(cada_linea);
  getline(fichero, cada_linea);
  const int kDimensiones = std::stoi(cada_linea);
  coordenadas_ = Matriz(kNumElementos, kDimensiones);
  distancias_ = Matriz(kNumElementos, kNumElementos);
}

/**
 * @brief Rellena los datos de coordenadas a partir de un archivo.
 * 
 * @param fichero El archivo que contiene los datos de coordenadas del problema.
 */
void Problema::rellenarDatosCoordenadas(std::ifstream& fichero) {
  std::string linea;
  int filas = 0, columnas = 0;
  while (getline(fichero, linea)) {
    std::stringstream ss(linea);
    std::string palabra;
    columnas = 0;
    while (ss >> palabra) {
      coordenadas_[filas][columnas++] = stod(reemplazarComaDecimalPorPunto(palabra));
    }
    filas++;
  }
}

/**
 * @brief Calcula y rellena la matriz de distancias basada en la matriz de coordenadas.
 */
void Problema::rellenarDatosDistancias() {
  const int kNumFilas = distancias_.getMatriz().size();
  for (int filas = 0; filas < kNumFilas; ++filas) {
    const int kNumColumnas = distancias_.getMatriz()[0].size();
    for (int columnas = filas + 1; columnas < kNumColumnas; ++columnas) {
      const int kNumDimensiones = coordenadas_.getMatriz()[0].size();
      double distancia = 0.0;
      for (int i = 0; i < kNumDimensiones; ++i) {
        distancia += (
          (coordenadas_[filas][i] - coordenadas_[columnas][i]) * (coordenadas_[filas][i] - coordenadas_[columnas][i])
        );
      }
      const double kSqrtDistancias = sqrt(distancia);
      distancias_[filas][columnas] = kSqrtDistancias;
      distancias_[columnas][filas] = kSqrtDistancias;
    }
  }
}

/**
 * @brief Obtiene los índices de los elementos del problema.
 * 
 * @return Un vector que contiene los índices de los elementos del problema.
 */
const std::vector<int> Problema::getIndicesProblema() const {
  std::vector<int> indices;
  const int kSizeMatriz = coordenadas_.size();
  for (int indice = 0; indice < kSizeMatriz; ++indice) indices.push_back(indice);
  return indices;
}

/**
 * @brief Sobrecarga del operador de inserción para imprimir los detalles del problema.
 * 
 * @param salida El flujo de salida donde se imprimirán los detalles del problema.
 * @param kProblema El problema que se desea imprimir.
 * @return El flujo de salida modificado después de imprimir los detalles del problema.
 */
std::ostream& operator<<(std::ostream& salida, const Problema& kProblema) {
  salida << "Matriz coordenadas de cada elemento" << std::endl;
  salida << "-----------------------------------" << std::endl;
  salida << kProblema.getCoordenadas();
  salida << std::endl;
  salida << "Matriz distancias de cada elemento" << std::endl;
  salida << "----------------------------------" << std::endl;
  salida << kProblema.getDistancias();
  salida << std::endl;
  return salida;
}