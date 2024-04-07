/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 1 de Abril de 2024
 * @file solucion.cc
 * @brief Implementación de la clase Solucion que se encarga
 * de realizar tareas
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07/src}
 */

#include "solucion.h"

int Solucion::funcion_objetivo_ = 0;

/**
 * @brief Determina el número de máquinas a crear a partir de un archivo.
 * 
 * @param kNombreDirYFichero Nombre del directorio y archivo que contiene la información.
 * @return Número de máquinas a crear.
 */
const int Solucion::cuantasMaquinasACrear(const std::string& kNombreDirYFichero) {
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
 * @brief Calcula la función objetivo basada en las asignaciones de tareas a las máquinas.
 * 
 * @param kMaquinas Vector que contiene las asignaciones de tareas a las máquinas.
 */
void Solucion::calcularFuncionObjetivo(const std::vector<Solucion>& kMaquinas) {
  funcion_objetivo_ = 0;
  const int kNumMaquinas  = kMaquinas.size();
  for (int i = 0; i < kNumMaquinas; ++i) {
    funcion_objetivo_ += kMaquinas[i].getTCT();
  }
}

/**
 * @brief Calcula el tiempo de ciclo total (TCT) de la máquina.
 * 
 * @param kNodoRaiz Nodo raíz del grafo.
 * @return const int Tiempo de ciclo total (TCT) de la máquina.
 */
const int Solucion::calcularTCT(
  const Nodo* kNodoRaiz
) {
  const std::vector<const Nodo*> kTareas = getTareas();
  const int kNumTareas = kTareas.size();
  tct_ = kNumTareas * kNodoRaiz->getCosteHaciaVecino(kTareas[0]);
  for (int i = 1; i < kNumTareas; ++i) {
    const int kCoeficiente = kNumTareas - i;
    tct_ += kCoeficiente * kTareas[i - 1]->getCosteHaciaVecino(kTareas[i]);
  }
  return tct_;
}

/**
 * @brief Añade una tarea a la máquina.
 * 
 * @param kTarea Tarea a añadir.
 */
void Solucion::añadirTarea(const Nodo* kTarea) { 
  tareas_.push_back(kTarea);
}

/**
 * @brief Inserta una tarea en una posición específica en la máquina.
 * 
 * @param kTarea Tarea a insertar.
 * @param kPos Posición en la que insertar la tarea.
 */
void Solucion::insertarTarea(const Nodo* kTarea, const int kPos) {
  if (kPos >= 0 && kPos <= tareas_.size()) tareas_.insert(tareas_.begin() + kPos, kTarea);
  else {
    std::string error = "La posición de inserción está fuera del rango válido";
    throw (error);
  }
}

/**
 * @brief Mueve una tarea dentro de la misma máquina.
 * 
 * @param kPosTarea La posición de la tarea que se moverá.
 * @param kPos La posición a la que se moverá la tarea.
 */
void Solucion::moverTarea(const int kPosTarea, const int kPos) {
  if (kPosTarea < 0 || kPosTarea >= tareas_.size()) {
    throw std::invalid_argument("Posición origen de la tarea, inválida");
  }
  if (kPos < 0 || kPos >= tareas_.size()) {
    throw std::invalid_argument("Posición destino de la tarea, inválida");
  }  
  const Nodo* kTarea = tareas_[kPosTarea];
  tareas_.erase(tareas_.begin() + kPosTarea);
  insertarTarea(kTarea, kPos);
}

/**
 * @brief Mueve una tarea de la máquina actual a otra máquina.
 * 
 * @param kPosTareaSolucion1 La posición de la tarea en la solución actual.
 * @param kPosSolucion2 La posición en la otra solución donde se insertará la tarea.
 * @param solucion2 La solución a la que se moverá la tarea.
 */
void Solucion::moverTareaEntreMaquinas(
  const int kPosTareaSolucion1,
  const int kPosSolucion2,
  Solucion& solucion2
) {
  if (kPosTareaSolucion1 < 0 || kPosTareaSolucion1 >= tareas_.size()) {
    throw std::invalid_argument("Posición de tarea inválida en la primera solución");
  }
  if (kPosSolucion2 < 0 || kPosSolucion2 > solucion2.tareas_.size()) {
    throw std::invalid_argument("Posición de tarea inválida en la segunda solución");
  }
  const Nodo* kTarea = tareas_[kPosTareaSolucion1];
  tareas_.erase(tareas_.begin() + kPosTareaSolucion1);
  solucion2.insertarTarea(kTarea, kPosSolucion2);
}

/**
 * @brief Intercambia dos tareas dentro de la misma máquina.
 * 
 * @param kPosAnterior La posición de la primera tarea a intercambiar.
 * @param kPosSiguiente La posición de la segunda tarea a intercambiar.
 */
void Solucion::swapTarea(const int kPosAnterior, const int kPosSiguiente) {
  if (kPosAnterior < 0 || kPosAnterior >= tareas_.size()) {
    throw std::out_of_range("La posición inicial no se encuentra en el vector");
  }
  if (kPosSiguiente < 0 || kPosSiguiente >= tareas_.size()) {
    throw std::out_of_range("La posición siguiente no se encuentra en el vector");
  }
  std::swap(tareas_[kPosAnterior], tareas_[kPosSiguiente]);
}

/**
 * @brief Intercambia una tarea entre dos máquinas.
 * 
 * @param kPosTareaSolucion1 La posición de la tarea en la primera solución.
 * @param kPosTareaSolucion2 La posición de la tarea en la segunda solución.
 * @param solucion2 La otra solución con la que se intercambiará la tarea.
 */
void Solucion::swapTareaEntreMaquinas(
  const int kPosTareaSolucion1,
  const int kPosTareaSolucion2,
  Solucion& solucion2
) {
  if (kPosTareaSolucion1 < 0 || kPosTareaSolucion1 >= tareas_.size()) {
    throw std::out_of_range("La posición inicial no se encuentra en el vector");
  }
  if (kPosTareaSolucion2 < 0 || kPosTareaSolucion2 >= solucion2.getTareas().size()) {
    throw std::out_of_range("La posición siguiente no se encuentra en el vector");
  }
  std::swap(tareas_[kPosTareaSolucion1], solucion2.setTareas()[kPosTareaSolucion2]);  
}

/**
 * @brief Muestra las tareas de todas las máquinas.
 * 
 * @param kMaquinas Vector de máquinas.
 */
void Solucion::mostrarTareasDeTodasLasMaquinas(const std::vector<Solucion>& kMaquinas) {
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