/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 20 de Marzo de 2024
 * @file tabla.cc
 * @brief Implementación de la clase Tabla
 * que almacena datos de los algoritmos utilizados para resolver el problema
 * Parallel Machine Scheduling Problem with Dependent Setup Times
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07_parcial_1/src}
 */

#include "tabla.h"

std::string Tabla::nombre_fichero_ = "";
std::vector<std::string> Tabla::nombres_algoritmos_ = {};
int Tabla::numero_nodos_ = 0;
int Tabla::numero_maquinas_ = 0;
std::vector<int> Tabla::funcion_objetivo_ = {};
std::vector<int> Tabla::tiempos_ = {};

/**
 * @brief Inserta el nombre de un archivo en la tabla de resultados.
 * 
 * @param kNombreFichero Nombre del archivo.
 */
void Tabla::insertarNombreFichero(const std::string& kNombreFichero) {
  nombre_fichero_ = kNombreFichero;
}

/**
 * @brief Inserta el nombre de un algoritmo en la tabla de resultados.
 * 
 * @param kNombreAlgoritmo Nombre del algoritmo.
 */
void Tabla::insertarNombreAlgoritmo(const std::string& kNombreAlgoritmo) {
  nombres_algoritmos_.push_back(kNombreAlgoritmo);
}

/**
 * @brief Inserta el número de nodos en la tabla de resultados.
 * 
 * @param kNumeroNodos número de nodos.
 */
void Tabla::insertarNumeroNodos(const int kNumeroNodos) {
  numero_nodos_ = kNumeroNodos;
}

/**
 * @brief Inserta el número de máquinas en la tabla de resultados.
 * 
 * @param kNumeroMaquinas número de máquinas.
 */
void Tabla::insertarNumeroMaquinas(const int kNumeroMaquinas) {
  numero_maquinas_ = kNumeroMaquinas;
}

/**
 * @brief Inserta el tiempo de ejecución en la tabla de resultados
 * 
 * @param kTiempo el tiempo de ejecución
 */
void Tabla::insertarTiempo(const int kTiempo) {
  tiempos_.push_back(kTiempo);
}

/**
 * @brief Inserta la función objetivo en la tabla de resultados
 * 
 * @param kFuncionObjetivo la función objetivo
 */
void Tabla::insertarFuncionObjetivo(const int kFuncionObjetivo) {
  funcion_objetivo_.push_back(kFuncionObjetivo);
}

/**
 * @brief Muestra la tabla de resultados en la consola.
 */
void Tabla::mostrarTablaEnPantalla() {
  // Encabezados de la tabla
  std::cout << std::left << std::setw(28) << "Nombre del Archivo"
            << std::setw(22) << "Nombre del Algoritmo"
            << std::setw(17) << "Numero de Nodos"
            << std::setw(20) << "Numero de Maquinas"
            << std::setw(13) << "Tiempo (µs)"
            << "Funcion Objetivo" << std::endl;
  std::cout << std::string(115, '-') << std::endl;
  // Escribir datos
  for (size_t i = 0; i < nombres_algoritmos_.size(); ++i) {
    std::cout << std::left << std::setw(28) << nombre_fichero_
              << std::setw(22) << nombres_algoritmos_[i]
              << std::setw(17) << numero_nodos_
              << std::setw(20) << numero_maquinas_
              << std::setw(12) << tiempos_[i]
              << funcion_objetivo_[i] << std::endl;
  }
}

/**
 * @brief Guarda la tabla de resultados en un archivo llamado "resultados.txt".
 */
void Tabla::mostrarTablaEnFichero() {
  std::ofstream archivo("resultados.txt", std::ios::app); // Abre el archivo en modo append
  if (!archivo.is_open()) {
    std::cerr << "Error al abrir el archivo." << std::endl;
    return;
  }
  // Escribir encabezados solo si el archivo está vacío
  if (archivo.tellp() == 0) {
  // Encabezados de la tabla
  archivo << std::left << std::setw(28) << "Nombre del Archivo"
          << std::setw(22) << "Nombre del Algoritmo"
          << std::setw(17) << "Numero de Nodos"
          << std::setw(20) << "Numero de Maquinas"
          << std::setw(13) << "Tiempo (µs)"
          << "Funcion Objetivo" << std::endl;
  archivo << std::string(115, '-') << std::endl;
  }
  // Escribir datos
  for (size_t i = 0; i < nombres_algoritmos_.size(); ++i) {
    archivo << std::left << std::setw(28) << nombre_fichero_
            << std::setw(22) << nombres_algoritmos_[i]
            << std::setw(17) << numero_nodos_
            << std::setw(20) << numero_maquinas_
            << std::setw(12) << tiempos_[i]
            << funcion_objetivo_[i] << std::endl;
  }
  archivo.close();
}