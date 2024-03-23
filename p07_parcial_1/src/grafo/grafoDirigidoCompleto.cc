/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Marzo de 2024
 * @file grafoNoDirigidoCompleto.cc
 * @brief Implementación de la clase GrafoNoDirigidoCompleto
 * que generará grafos no dirigidos completos
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p06/src}
 * @see {@link https://docs.google.com/document/d/1a691HPtHQL4qBtI2qaTMTp23wxZvU8-CCIbGOyNJRQo/edit}
 */

#include "grafoDirigidoCompleto.h"

/**
 * @brief Constructor de la clase GrafoNoDirigidoCompleto.
 * 
 * @param kNombreDir Directorio donde se encuentra el archivo.
 * @param kNombreFichero Nombre del archivo que contiene la descripción del grafo.
 * @throws Excepción que indica un error al cargar el grafo.
 */
GrafoDirigidoCompleto::GrafoDirigidoCompleto(
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

const int GrafoDirigidoCompleto::calculaNumeroNodos(const std::string& kCadaLinea) const {
  std::stringstream ss(kCadaLinea);
  std::string palabra = "";
  ss >> palabra; // Descartar La primera palabra
  ss >> palabra;
  return stoi(palabra) + 1;
}

void GrafoDirigidoCompleto::calculaTiemposProcesamientos(
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

void GrafoDirigidoCompleto::calculaTiemposSetUp(
  const std::string& kCadaLinea,
  std::vector<std::vector<int>>& tiempos_setup
) const {
  std::stringstream ss(kCadaLinea);
  std::string palabra = "";
  std::vector<int> tiempos_setup_por_linea;
  while (ss >> palabra) tiempos_setup_por_linea.push_back(stoi(palabra));
  tiempos_setup.push_back(tiempos_setup_por_linea); 
}

void GrafoDirigidoCompleto::rellenarCostesArcos(
  const std::vector<std::vector<int>>& kTiemposSetup,
  const std::vector<int>& kTiemposProcesamiento
) {
  const int kFilas = kTiemposSetup.size();
  for (int i = 0; i < kFilas; ++i) {
    const int kColumnas = kTiemposSetup[i].size();
    for (int j = 0; j < kColumnas; ++j) {
      //if (std::to_string(i) == grafo_[j]->getId()) continue;
      grafo_[i]->insertarNodoVecino(grafo_[j], kTiemposSetup[i][j] + kTiemposProcesamiento[j]);
    }
  }  
}

/**
 * @brief Verifica si la cantidad de nodos del grafo es la esperada.
 * 
 * @param kNumNodos Número de nodos esperados.
 * @return true Si la cantidad de nodos coincide.
 * @return false Si la cantidad de nodos no coincide.
 */
const bool GrafoDirigidoCompleto::esCorrectaCantidadNodos(const int kNumNodos) const {
  return (grafo_.size() == kNumNodos);
}

/**
 * @brief Verifica si el grafo es completo.
 * 
 * @return true Si el grafo es completo.
 * @return false Si el grafo no es completo.
 */
const bool GrafoDirigidoCompleto::esCompleto() const {
  const int kNumNodos = grafo_.size();
  for (int i = 0; i < kNumNodos; ++i) {
    for (int j = 0; j < kNumNodos; ++j) {
      // Verificar si existe una arista entre los nodos i y j
      // Si no hay arco, el grafo no es completo
      if (!existeArco(grafo_[i], grafo_[j])) return false;
    }
  }
  return true;
}

/**
 * @brief Comprueba si existe una arista entre dos nodos en el grafo.
 * 
 * @param nodo1 Puntero al primer nodo.
 * @param nodo2 Puntero al segundo nodo.
 * @return true si existe una arista entre los dos nodos, false en caso contrario.
 */
const bool GrafoDirigidoCompleto::existeArco(const Nodo* nodo1, const Nodo* nodo2) const {
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
 * @param out Flujo de salida donde se imprime el grafo.
 * @param grafo Grafo no dirigido completo a imprimir.
 * @return El flujo de salida modificado.
 */
std::ostream& operator<<(std::ostream& out, const GrafoDirigidoCompleto& grafo) {
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