/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 20 de Marzo de 2024
 * @file maquina.cc
 * @brief Implementación de la clase Maquina que se encarga
 * de realizar tareas
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07_parcial_1/src}
 */

#include "maquina.h"

/**
 * @brief Determina el número de máquinas a crear a partir de un archivo.
 * 
 * @param kNombreDirYFichero Nombre del directorio y archivo que contiene la información.
 * @return Número de máquinas a crear.
 */
const int Maquina::cuantasMaquinasACrear(const std::string& kNombreDirYFichero) {
  fs::path ruta_actual = fs::current_path();
  fs::path ruta_completa = ruta_actual / kNombreDirYFichero; 
  std::ifstream archivo(ruta_completa);
  std::string cada_linea = "";
  getline(archivo, cada_linea);
  getline(archivo, cada_linea);
  std::stringstream ss(cada_linea);
  std::string palabra = "";
  ss >> palabra; // Descartar La primera palabra
  ss >> palabra;
  return stoi(palabra);
}

/**
 * @brief Calcula el tiempo de ciclo total (TCT) de la máquina.
 * 
 * @param kNodoRaiz Nodo raíz del grafo.
 * @return const int Tiempo de ciclo total (TCT) de la máquina.
 */
const int Maquina::calcularTCT(
  const Nodo* kNodoRaiz
) const {
  const std::vector<const Nodo*> kTareas = getTareas();
  const int kNumTareas = kTareas.size();
  int tct = kNumTareas * kNodoRaiz->getCosteHaciaVecino(kTareas[0]);
  for (int i = 1; i < kNumTareas; ++i) {
    const int kCoeficiente = kNumTareas - i;
    tct += kCoeficiente * kTareas[i - 1]->getCosteHaciaVecino(kTareas[i]);
  }
  return tct;
}

/**
 * @brief Añade una tarea a la máquina.
 * 
 * @param kTarea Tarea a añadir.
 */
void Maquina::añadirTarea(const Nodo* kTarea) { 
  tareas_.push_back(kTarea);
}

/**
 * @brief Inserta una tarea en una posición específica en la máquina.
 * 
 * @param kTarea Tarea a insertar.
 * @param kPos Posición en la que insertar la tarea.
 */
void Maquina::insertarTarea(const Nodo* kTarea, const int kPos) {
  if (kPos >= 0 && kPos <= tareas_.size()) tareas_.insert(tareas_.begin() + kPos, kTarea);
  else {
    std::string error = "La posición de inserción está fuera del rango válido";
    throw (error);
  }
}

/**
 * @brief Muestra las tareas de todas las máquinas.
 * 
 * @param kMaquinas Vector de máquinas.
 */
void Maquina::mostrarTareasDeTodasLasMaquinas(const std::vector<Maquina>& kMaquinas) {
  const int kNumeroMaquinas = kMaquinas.size();
  for (int i = 0; i < kNumeroMaquinas; ++i) {
    std::cout << "Maquina " << i + 1 << " tiene asignadas las siguientes tareas: ";
    const auto& tareas = kMaquinas[i].getTareas();
    for (const auto& tarea : tareas) {
      std::cout << tarea->getId() << " ";
    }
    std::cout << std::endl;
  }
}