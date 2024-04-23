/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 19 de Abril de 2024
 * @file tabla.cc
 * @brief Implementación de la clase Tabla
 * que almacena datos de los algoritmos utilizados para resolver el Maximum Diversity Problem
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p08/src}
 */

#include "tabla.h"

std::vector<std::string> Tabla::nombre_fichero_ = {};
std::vector<int> Tabla::numero_elementos_problema_ = {};
std::vector<int> Tabla::dimensiones_problema_ = {};
std::vector<int> Tabla::numero_elementos_solucion_ = {};
std::vector<std::string> Tabla::nombres_algoritmos_ = {};
std::vector<int> Tabla::tiempos_ = {};
std::vector<double> Tabla::funcion_objetivo_ = {};

/**
 * @brief Inserta los datos iniciales de la tabla.
 * 
 * @param kNombreFichero El nombre del archivo.
 * @param kNumElementosProblema El número de elementos del problema.
 * @param kDimensionesProblema Las dimensiones del problema.
 * @param kNumElementosSolucion El número de elementos de la solución.
 */
void Tabla::insertarDatosIniciales(
  const std::string& kNombreFichero,
  const int kNumElementosProblema,
  const int kDimensionesProblema,
  const int kNumElementosSolucion
) {
  insertarNombreFichero(kNombreFichero);
  insertarNumeroElementosProblema(kNumElementosProblema);
  insertarDimensionesProblema(kDimensionesProblema);
  insertarNumeroElementosSolucion(kNumElementosSolucion);
}

/**
 * @brief Inserta los datos de un resultado de algoritmo en la tabla.
 * 
 * @param kNombreAlgoritmo El nombre del algoritmo.
 * @param kResultado El resultado del algoritmo.
 */
void Tabla::insertarDatos( 
  const std::string& kNombreAlgoritmo,
  const std::pair<const Solucion&, const int>& kResultado
) {  
  insertarNombreAlgoritmo(kNombreAlgoritmo);    
  insertarFuncionObjetivo(kResultado.first.getFuncionObjetivo());
  insertarTiempo(kResultado.second);
}

/**
 * @brief Inserta el nombre del fichero en la tabla.
 * 
 * @param kNombreFichero El nombre del fichero.
 */
void Tabla::insertarNombreFichero(const std::string& kNombreFichero) {
  nombre_fichero_.push_back(kNombreFichero);
}

/**
 * @brief Inserta el número de elementos del problema en la tabla.
 * 
 * @param kNumElementosProblema El número de elementos del problema.
 */
void Tabla::insertarNumeroElementosProblema(const int kNumElementosProblema) {
  numero_elementos_problema_.push_back(kNumElementosProblema);
}

/**
 * @brief Inserta las dimensiones del problema en la tabla.
 * 
 * @param kDimensionesProblema Las dimensiones del problema.
 */
void Tabla::insertarDimensionesProblema(const int kDimensionesProblema) {
  dimensiones_problema_.push_back(kDimensionesProblema);
}

/**
 * @brief Inserta el número de elementos de la solución en la tabla.
 * 
 * @param kNumElementosSolucion El número de elementos de la solución.
 */
void Tabla::insertarNumeroElementosSolucion(const int kNumElementosSolucion) {
  numero_elementos_solucion_.push_back(kNumElementosSolucion);
}

/**
 * @brief Inserta el nombre del algoritmo en la tabla.
 * 
 * @param kNombreAlgoritmo El nombre del algoritmo.
 */
void Tabla::insertarNombreAlgoritmo(const std::string& kNombreAlgoritmo) {
  nombres_algoritmos_.push_back(kNombreAlgoritmo);
}

/**
 * @brief Inserta la función objetivo en la tabla.
 * 
 * @param kFuncionObjetivo La función objetivo.
 */
void Tabla::insertarFuncionObjetivo(const double kFuncionObjetivo) {
  funcion_objetivo_.push_back(kFuncionObjetivo);
}

/**
 * @brief Inserta el tiempo en la tabla.
 * 
 * @param kTiempo El tiempo.
 */
void Tabla::insertarTiempo(const int kTiempo) {
  tiempos_.push_back(kTiempo);
}

/**
 * @brief Muestra la tabla de resultados en la consola.
 */
void Tabla::mostrarTablaEnPantalla() {
  // Encabezados de la tabla
  std::cout << std::left << std::setw(20) << "Nombre del Archivo"
            << std::setw(22) << "Nombre del Algoritmo"
            << std::setw(23) << "Nº puntos (Problema)"
            << std::setw(22) << "Dimensiones problema"
            << std::setw(24) << "Nº puntos (Solución)"
            << std::setw(14) << "Tiempo (µs)"
            << "Función Objetivo" << std::endl;
  std::cout << std::string(137, '-') << std::endl;
  // Escribir datos
  for (size_t i = 0; i < nombres_algoritmos_.size(); ++i) {
    std::cout << std::left << std::setw(20) << nombre_fichero_[i]
              << std::setw(22) << nombres_algoritmos_[i]
              << std::setw(22) << numero_elementos_problema_[i]
              << std::setw(22) << dimensiones_problema_[i]
              << std::setw(22) << numero_elementos_solucion_[i]
              << std::setw(13) << tiempos_[i]
              << std::fixed << std::setprecision(contarDecimales(funcion_objetivo_[i], 4)) << funcion_objetivo_[i]
              << std::endl;
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
    archivo << std::left << std::setw(20) << "Nombre del Archivo"
            << std::setw(22) << "Nombre del Algoritmo"
            << std::setw(23) << "Nº puntos (Problema)"
            << std::setw(22) << "Dimensiones problema"
            << std::setw(24) << "Nº puntos (Solución)"
            << std::setw(14) << "Tiempo (µs)"
            << "Función Objetivo" << std::endl;
    archivo << std::string(137, '-') << std::endl;
  }
  // Escribir datos
  for (size_t i = 0; i < nombres_algoritmos_.size(); ++i) {
    archivo << std::left << std::setw(20) << nombre_fichero_[i]
            << std::setw(22) << nombres_algoritmos_[i]
            << std::setw(22) << numero_elementos_problema_[i]
            << std::setw(22) << dimensiones_problema_[i]
            << std::setw(22) << numero_elementos_solucion_[i]
            << std::setw(13) << tiempos_[i]
            << std::fixed << std::setprecision(contarDecimales(funcion_objetivo_[i], 4)) << funcion_objetivo_[i]
            << std::endl;
  }
  archivo.close();
}