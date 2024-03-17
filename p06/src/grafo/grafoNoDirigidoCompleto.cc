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

#include "grafoNoDirigidoCompleto.h"

/**
 * @brief Constructor de la clase GrafoNoDirigidoCompleto.
 * 
 * @param kNombreDir Directorio donde se encuentra el archivo.
 * @param kNombreFichero Nombre del archivo que contiene la descripción del grafo.
 * @throws Excepción que indica un error al cargar el grafo.
 */
GrafoNoDirigidoCompleto::GrafoNoDirigidoCompleto(
  const std::string kNombreDir,
  const std::string kNombreFichero
) {
  fs::path ruta_actual = fs::current_path();
  fs::path ruta_completa = ruta_actual / kNombreDir / kNombreFichero; 
  std::ifstream archivo(ruta_completa);
  std::string cada_linea = "", error = "";
  int contador_linea = 1;
  int num_nodos = 0;
  while (getline(archivo, cada_linea)) {
    if (contador_linea == 1) {
      if (!SintaxisFicheroGrafo::numeroNodosValido(cada_linea)) {
        error = "Número de nodos inválido ";
        error += "'" + cada_linea + "'";
        throw (error);
      }
      num_nodos = stoi(cada_linea);
    }
    else {
      // Usar stringstream para dividir la cadena en substrings
      std::stringstream ss(cada_linea);
      std::vector<std::string> cada_elemento;
      std::string palabra;    
      // Leer cada substring y agregarlo al vector
      while (ss >> palabra) {
        cada_elemento.push_back(palabra);
      }
      if (!SintaxisFicheroGrafo::tresElementosPorLineaNodo1Nodo2Coste(cada_elemento)) {
        error = "Número de elementos inválidos o algún error en la línea '";
        const int kSizeElementos = cada_elemento.size();
        for (int i = 0; i < kSizeElementos; ++i) {
          error += cada_elemento[i];
          if (i < kSizeElementos - 1) error += ", ";
        }
        error += "'";
        throw (error);        
      }
      // Buscar los índices de los nodos para saber si crearlos o ya estaban
      int indice_nodo1 = getIndiceNodo(cada_elemento[0]);
      int indice_nodo2 = getIndiceNodo(cada_elemento[1]);
      Nodo* nodo1; Nodo* nodo2;
      if (indice_nodo1 == -1) {
        nodo1 = new Nodo(cada_elemento[0]);
        grafo_.push_back(nodo1);
      }
      else nodo1 = grafo_[indice_nodo1];
      if (indice_nodo2 == -1) {
        nodo2 = new Nodo(cada_elemento[1]);
        grafo_.push_back(nodo2);
      }
      else nodo2 = grafo_[indice_nodo2];
      // Añadirle vecinos con el precio de la arista
      cada_elemento[2] = sustituirComasPorPunto(cada_elemento[2]);
      nodo1->insertarNodoVecino(nodo2, stold(cada_elemento[2]));
      nodo2->insertarNodoVecino(nodo1, stold(cada_elemento[2]));
    }
    contador_linea++;
  }
  if (!esCompleto()) error = "Este grafo no es completo";
  if (!esCorrectaCantidadNodos(num_nodos)) {
    error = "El fichero indicaba " + std::to_string(num_nodos) +
      " nodos, pero el grafo tiene " + std::to_string(grafo_.size());
  }
  if (error != "") throw (error);
}

/**
 * @brief Obtiene el índice del nodo con el nombre especificado en el grafo.
 * 
 * @param nombre_nodo Nombre del nodo a buscar.
 * @return Índice del nodo si se encuentra, -1 si no se encuentra.
 */
const int GrafoNoDirigidoCompleto::getIndiceNodo(const std::string& nombre_nodo) const {
  const int kNumeroNodos = grafo_.size();
  for (int i = 0; i < kNumeroNodos; ++i) {
    if (grafo_[i] != nullptr && grafo_[i]->getId() == nombre_nodo) return i;
  }
  return -1;
}

/**
 * @brief Verifica si la cantidad de nodos del grafo es la esperada.
 * 
 * @param kNumNodos Número de nodos esperados.
 * @return true Si la cantidad de nodos coincide.
 * @return false Si la cantidad de nodos no coincide.
 */
const bool GrafoNoDirigidoCompleto::esCorrectaCantidadNodos(const int kNumNodos) const {
  return (grafo_.size() == kNumNodos);
}

/**
 * @brief Verifica si el grafo es completo.
 * 
 * @return true Si el grafo es completo.
 * @return false Si el grafo no es completo.
 */
const bool GrafoNoDirigidoCompleto::esCompleto() const {
  const int kNumNodos = grafo_.size();
  for (int i = 0; i < kNumNodos; ++i) {
    for (int j = i + 1; j < kNumNodos; ++j) {
      // Verificar si existe una arista entre los nodos i y j
      // Si no hay arista, el grafo no es completo
      if (!existeArista(grafo_[i], grafo_[j])) return false;
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
const bool GrafoNoDirigidoCompleto::existeArista(const Nodo* nodo1, const Nodo* nodo2) const {
  bool enlace_nodo1_nodo2 = false, enlace_nodo2_nodo1 = false;
  for (const auto& vecinos: nodo1->getNodosVecinos()) {
    if (vecinos.getNodoDestino()->getId() == nodo2->getId()) {
      enlace_nodo1_nodo2 = true;
    }
  }
  for (const auto& vecinos: nodo2->getNodosVecinos()) {
    if (vecinos.getNodoDestino()->getId() == nodo1->getId()) {
      enlace_nodo2_nodo1 = true;
    }
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
std::ostream& operator<<(std::ostream& out, const GrafoNoDirigidoCompleto& grafo) {
  out << "Grafo No Dirigido Completo:" << std::endl;
  out << "-----------------" << std::endl;
  for (const auto& nodo : grafo.getGrafo()) {
    out << "Nodo " << nodo->getId() << ":" << std::endl;
    const auto& vecinos = nodo->getNodosVecinos();
    if (!vecinos.empty()) {
      out << "  Vecinos:" << std::endl;
      for (const auto& arista : vecinos) {
        out << "  " << arista.getNodoDestino()->getId()
        << " con valor: " << arista.getPeso() << std::endl;
      }
    } else out << "  (sin vecinos)" << std::endl;
  }
  return out;
}