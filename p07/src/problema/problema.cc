/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 20 de Marzo de 2024
 * @file problema.cc
 * @brief Implementación de la clase Problema que se encarga
 * de leer los datos de un fichero y crear el grafo
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07/src}
 */

#include "problema.h"

/**
 * @brief Constructor de la clase Problema.
 * 
 * @param kNombreDirYFichero Nombre del directorio y fichero del grafo.
 */
Problema::Problema(
  const std::string& kNombreDirYFichero
) {
  fs::path ruta_actual = fs::current_path();
  fs::path ruta_completa = ruta_actual / kNombreDirYFichero; 
  std::ifstream archivo(ruta_completa);
  std::string cada_linea = "", error = "";
  std::vector<int> tiempos_procesamiento;
  std::vector<std::vector<int>> tiempos_setup;
  int contador_lineas = 0, numero_nodos;
  while (getline(archivo, cada_linea)) {
    if (contador_lineas == 0) numero_nodos = calculaNumeroNodos(cada_linea);
    else if (contador_lineas == 2) calculaTiemposProcesamientos(cada_linea, tiempos_procesamiento);
    else if (contador_lineas > 3) calculaTiemposSetUp(cada_linea, tiempos_setup);
    contador_lineas++;
  }
  rellenarCostesArcos(tiempos_setup, tiempos_procesamiento);
  if (!esCorrectaCantidadNodos(numero_nodos)) {
    error = "Tienen que ser " + std::to_string(numero_nodos) + " nodos y son " + std::to_string(grafo_.size());
  } else if (!esCompleto()) error = "Este grafo no es completo";
  archivo.close();
  if (error != "") throw (error);
}

/**
 * @brief Destructor de la clase Problema.
 */
Problema::~Problema() {
  for (auto nodo : grafo_) delete nodo;
}

/**
 * @brief Calcula el número de nodos a partir de una línea del archivo.
 * 
 * @param kCadaLinea Línea del archivo que contiene el número de nodos.
 * @return Número de nodos.
 */
const int Problema::calculaNumeroNodos(const std::string& kCadaLinea) const {
  std::stringstream ss(kCadaLinea);
  std::string palabra = "";
  ss >> palabra;
  ss >> palabra;
  return stoi(palabra) + 1;
}

/**
 * @brief Extrae los tiempos de procesamiento de cada nodo a partir de una línea del archivo.
 * 
 * @param kCadaLinea Línea del archivo que contiene los tiempos de procesamiento.
 * @param tiempos_procesamiento Vector para almacenar los tiempos de procesamiento.
 */
void Problema::calculaTiemposProcesamientos(
  const std::string& kCadaLinea,
  std::vector<int>& tiempos_procesamiento
) {
  std::stringstream ss(kCadaLinea);
  std::string palabra = "";
  int id = 1;
  ss >> palabra; // Leer y descartar la primera palabra
  tiempos_procesamiento.push_back(0);
  grafo_.push_back(new Nodo(std::to_string(0))); // Raíz
  while (ss >> palabra) {
    tiempos_procesamiento.push_back(stoi(palabra));
    grafo_.push_back(new Nodo(std::to_string(id))); // Resto de nodos
    id++;
  } 
}

/**
 * @brief Extrae los tiempos de setup entre nodos a partir de una línea del archivo.
 * 
 * @param kCadaLinea Línea del archivo que contiene los tiempos de setup.
 * @param tiempos_setup Vector para almacenar los tiempos de setup.
 */
void Problema::calculaTiemposSetUp(
  const std::string& kCadaLinea,
  std::vector<std::vector<int>>& tiempos_setup
) const {
  std::stringstream ss(kCadaLinea);
  std::string palabra = "";
  std::vector<int> tiempos_setup_por_linea;
  while (ss >> palabra) tiempos_setup_por_linea.push_back(stoi(palabra));
  tiempos_setup.push_back(tiempos_setup_por_linea); 
}

/**
 * @brief Rellena los costes de los arcos en el grafo a partir de los tiempos de setup y procesamiento.
 * 
 * @param kTiemposSetup Matriz de tiempos de setup entre nodos.
 * @param kTiemposProcesamiento Vector de tiempos de procesamiento de cada nodo.
 */
void Problema::rellenarCostesArcos(
  const std::vector<std::vector<int>>& kTiemposSetup,
  const std::vector<int>& kTiemposProcesamiento
) {
  const int kFilas = kTiemposSetup.size();
  for (int i = 0; i < kFilas; ++i) {
    const int kColumnas = kTiemposSetup[i].size();
    for (int j = 0; j < kColumnas; ++j) {
      grafo_[i]->insertarNodoVecino(grafo_[j], kTiemposSetup[i][j] + kTiemposProcesamiento[j]);
    }
  }  
}

/**
 * @brief Verifica si la cantidad de nodos del grafo es correcta.
 * 
 * @param kNumNodos Número esperado de nodos.
 * @return Verdadero si la cantidad de nodos es correcta, falso en caso contrario.
 */
const bool Problema::esCorrectaCantidadNodos(const int kNumNodos) const {
  return (grafo_.size() == kNumNodos);
}

/**
 * @brief Verifica si el grafo es completo, es decir, si existe un arco entre todos los pares de nodos.
 * 
 * @return Verdadero si el grafo es completo, falso en caso contrario.
 */
const bool Problema::esCompleto() const {
  const int kNumNodos = grafo_.size();
  for (int i = 0; i < kNumNodos; ++i) {
    for (int j = 0; j < kNumNodos; ++j) {
      // Verificar si existe un arco entre los nodos i y j
      // Si no hay arco, el grafo no es completo
      if (!existeArco(grafo_[i], grafo_[j])) return false;
    }
  }
  return true;
}

/**
 * @brief Verifica si existe un arco entre dos nodos.
 * 
 * @param nodo1 Primer nodo.
 * @param nodo2 Segundo nodo.
 * @return Verdadero si existe un arco entre los nodos, falso en caso contrario.
 */
const bool Problema::existeArco(const Nodo* nodo1, const Nodo* nodo2) const {
  bool enlace_nodo1_nodo2 = false, enlace_nodo2_nodo1 = false;
  for (const auto& vecinos: nodo1->getNodosVecinos()) {
    if (vecinos.getNodoDestino()->getId() == nodo2->getId()) enlace_nodo1_nodo2 = true;
  }
  for (const auto& vecinos: nodo2->getNodosVecinos()) {
    if (vecinos.getNodoDestino()->getId() == nodo1->getId()) enlace_nodo2_nodo1 = true;
  }
  return (enlace_nodo1_nodo2 && enlace_nodo2_nodo1);
}

/**
 * @brief Sobrecarga del operador de inserción para imprimir el grafo.
 * 
 * @param out Flujo de salida.
 * @param grafo Grafo a imprimir.
 * @return Referencia al flujo de salida.
 */
std::ostream& operator<<(std::ostream& out, const Problema& grafo) {
  out << "Grafo Dirigido Completo:" << std::endl;
  out << "-----------------" << std::endl;
  for (const auto& nodo : grafo.getGrafo()) {
    out << "Nodo " << nodo->getId() << " conectado a (Vecino|Coste): ";
    const auto& vecinos = nodo->getNodosVecinos();
    if (!vecinos.empty()) {
      for (const auto& vecino : vecinos) {
        out << vecino.getNodoDestino()->getId() << " -> " << vecino.getCoste();
        if (&vecino != &vecinos.back()) out << " | ";
      }
      out << std::endl << std::endl;
    } else out << "  (sin vecinos)" << std::endl;
  }
  return out;
}