/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Marzo de 2024
 * @file tablaResultados.cc
 * @brief Implementación de la clase TablaResultadosTSP
 * que almacena datos de los algoritmos utilizados para resolver el problema TSP
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p06/src}
 * @see {@link https://docs.google.com/document/d/1a691HPtHQL4qBtI2qaTMTp23wxZvU8-CCIbGOyNJRQo/edit}
 */

#include "tablaResultadosTSP.h"

std::vector<std::string> TablaResultadosTSP::nombres_ficheros_;
std::vector<std::string> TablaResultadosTSP::nombres_algoritmos_;
std::vector<std::vector<std::pair<const long double, const long double>>> TablaResultadosTSP::matriz_datos_;
std::vector<std::vector<const Nodo*>> TablaResultadosTSP::caminos_minimos;

/**
 * @brief Inserta el nombre de un archivo en la tabla de resultados.
 * 
 * @param kNombreFichero Nombre del archivo.
 */
void TablaResultadosTSP::insertarDatoNombreFichero(const std::string& kNombreFichero) {
  nombres_ficheros_.push_back(kNombreFichero);
}

/**
 * @brief Inserta el nombre de un algoritmo en la tabla de resultados.
 * 
 * @param kNombreAlgoritmo Nombre del algoritmo.
 */
void TablaResultadosTSP::insertarDatoNombreAlgoritmo(const std::string& kNombreAlgoritmo) {
  nombres_algoritmos_.push_back(kNombreAlgoritmo);
}

/**
 * @brief Inserta una fila de datos de resultados en la matriz de datos.
 * 
 * @param kCosteYTiempoEjecucionCadaFila Vector que contiene los pares de coste y tiempo de ejecución.
 */
void TablaResultadosTSP::insertarFilaMatrizDatos(
  const std::vector<std::pair<const long double, const long double>>& kCosteYTiempoEjecucionCadaFila
) {
  matriz_datos_.push_back(kCosteYTiempoEjecucionCadaFila);
}

/**
 * @brief Inserta una fila de caminos mínimos en la matriz de caminos mínimos.
 * 
 * @param kCaminoMinimo Vector que contiene los nodos del camino mínimo.
 */
void TablaResultadosTSP::insertarFilaMatrizCaminosMinimos(
  const std::vector<const Nodo*>& kCaminoMinimo
) {
  caminos_minimos.push_back(kCaminoMinimo);
}

/**
 * @brief Muestra la tabla de resultados en la consola.
 */
void TablaResultadosTSP::mostrarTablaEnPantalla() {
  // Mostrar encabezados
  const int kSizeMatrizDatos = matriz_datos_.size();
  int contador_caminos = -1;
  std::cout << std::endl;
  for (int i = 0; i < kSizeMatrizDatos; ++i) {
    std::cout << "Instancia: " << nombres_ficheros_[i] << std::endl;
    for (int j = 0; j < matriz_datos_[i].size(); ++j) {
      std::cout << "Valor " << nombres_algoritmos_[j] << ": " << matriz_datos_[i][j].first << std::endl;
      std::cout << "Tiempo " << nombres_algoritmos_[j] << " (µs) : ";
      if (matriz_datos_[i][j].second == -1) std::cout << "EXCESIVO";
      else std::cout << matriz_datos_[i][j].second;
      std::cout << "\nCamino mínimo: ";
      contador_caminos++;
      for (int k = 0; k < caminos_minimos[contador_caminos].size(); ++k) {
        std::cout << caminos_minimos[contador_caminos][k]->getId();
        if (k < caminos_minimos[contador_caminos].size() - 1) std::cout << " -> ";
      }
      std::cout << std::endl << std::endl;
    }
  }
}

/**
 * @brief Guarda la tabla de resultados en un archivo llamado "resultados.txt".
 */
void TablaResultadosTSP::mostrarTablaEnFichero() {
  std::ofstream archivo("resultados.txt");
  if (!archivo.is_open()) {
    std::cerr << "Error al abrir el archivo." << std::endl;
    return;
  }
  const int kSizeMatrizDatos = matriz_datos_.size();
  int contador_caminos = -1;
  for (int i = 0; i < kSizeMatrizDatos; ++i) {
    archivo << "Instancia: " << nombres_ficheros_[i] << std::endl;
    for (int j = 0; j < matriz_datos_[i].size(); ++j) {
      archivo << "Valor " << nombres_algoritmos_[j] << ": " << matriz_datos_[i][j].first << std::endl;
      archivo << "Tiempo " << nombres_algoritmos_[j] << " (µs) : ";
      if (matriz_datos_[i][j].second == -1) archivo << "EXCESIVO";
      else archivo << matriz_datos_[i][j].second;
      archivo << "\nCamino mínimo: ";
      contador_caminos++;
      for (int k = 0; k < caminos_minimos[contador_caminos].size(); ++k) {
        archivo << caminos_minimos[contador_caminos][k]->getId();
        if (k < caminos_minimos[contador_caminos].size() - 1) archivo << " -> ";
      }
      archivo << std::endl << std::endl;
    }
  }
  archivo.close();
}