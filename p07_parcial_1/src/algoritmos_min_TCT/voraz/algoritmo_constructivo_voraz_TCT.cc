/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 20 de Marzo de 2024
 * @file algoritmo_constructivo_voraz_TCT.h
 * @brief Implementación de la clase AlgoritmoConstructivoVoraz que hereda de
 * la clase abstracta AlgoritmoMinimizarTCT para minimizar el TCT mediante un algoritmo Voraz
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07_parcial_1/src}
 */

#include "./algoritmo_constructivo_voraz_TCT.h"

/**
 * @brief Ejecuta el algoritmo constructivo voraz para asignar tareas a las máquinas.
 * 
 * @param kNumeroMaquinas Número de máquinas disponibles.
 * @param kGrafo Grafo que representa las tareas y sus dependencias.
 * @return Vector que contiene las asignaciones de tareas a las máquinas.
 */
const std::vector<Solucion> AlgoritmoConstructivoVoraz::ejecutar(
  const int kNumeroMaquinas,
  const Problema& kGrafo
) {
  std::vector<Solucion> maquinas(kNumeroMaquinas); // m Maquinas
  std::vector<int> tareas_a_realizar(kGrafo.getGrafo().size() - 1);
  std::iota(tareas_a_realizar.begin(), tareas_a_realizar.end(), 1);
  seleccionarTareasInciales(maquinas, kGrafo, tareas_a_realizar);
  std::vector<Solucion> maquinas_copia = maquinas;
  while (!tareas_a_realizar.empty()) {
    const TareaMaquinaPosicion kMejorEleccion = obtenerTareaMaquinaPosicion(
      kNumeroMaquinas, maquinas_copia, tareas_a_realizar, kGrafo
    );
    maquinas_copia[kMejorEleccion.indice_maquina].insertarTarea(
      kMejorEleccion.tarea, kMejorEleccion.posicion
    );
    auto it = std::find(
      tareas_a_realizar.begin(), tareas_a_realizar.end(), stoi(kMejorEleccion.tarea->getId())
    );
    tareas_a_realizar.erase(it);
    maquinas = maquinas_copia;
  }
  for (int i = 0; i < kNumeroMaquinas; ++i) {
    maquinas[i].setTCT() = maquinas[i].calcularTCT(kGrafo.getGrafo()[0]);
  }
  calcularFuncionObjetivo(maquinas);
  return maquinas;
}

/**
 * @brief Selecciona las tareas iniciales para cada máquina basándose en un criterio voraz.
 * 
 * @param maquinas Vector que contiene las máquinas disponibles.
 * @param kGrafo Grafo que representa las tareas y sus dependencias.
 * @param tareas_a_realizar Vector que contiene las tareas que aún no han sido asignadas.
 */
void AlgoritmoConstructivoVoraz::seleccionarTareasInciales(
  std::vector<Solucion>& maquinas,
  const Problema& kGrafo,
  std::vector<int>& tareas_a_realizar
) const {
  const int kNumeroMaquinas = maquinas.size();
  for (int i = 0; i < kNumeroMaquinas; ++i) {
    if (tareas_a_realizar.empty()) return;
    const int kSizeTareasARealizar = tareas_a_realizar.size();
    int indice_minima_tarea = tareas_a_realizar[0];
    int indice_a_eliminar = 0;
    const Arco& kVecino1 = kGrafo.getGrafo()[0]->getVecino(indice_minima_tarea);
    int min_coste = kVecino1.getCoste();
    for (int j = 1; j < kSizeTareasARealizar; ++j) {
      const Arco& kVecino2 = kGrafo.getGrafo()[0]->getVecino(tareas_a_realizar[j]);
      if (kVecino2.getCoste() < min_coste) {
        min_coste = kVecino2.getCoste();
        indice_minima_tarea = tareas_a_realizar[j];
        indice_a_eliminar = j;
      }
    }
    maquinas[i].añadirTarea(kGrafo.getGrafo()[indice_minima_tarea]);
    tareas_a_realizar.erase(tareas_a_realizar.begin() + indice_a_eliminar);
  }
}

/**
 * @brief Obtiene la siguiente tarea a asignar a una máquina en una posición específica
 * utilizando un criterio voraz.
 * 
 * @param kNumeroMaquinas Número de máquinas disponibles.
 * @param maquinas_copia Vector que contiene las máquinas disponibles.
 * @param kTareasARealizar Vector que contiene las tareas que aún no han sido asignadas.
 * @param kGrafo Grafo que representa las tareas y sus dependencias.
 * @return Estructura que contiene la tarea, la máquina y la posición.
 */
const TareaMaquinaPosicion AlgoritmoConstructivoVoraz::obtenerTareaMaquinaPosicion(
  const int kNumeroMaquinas,
  std::vector<Solucion>& maquinas_copia,
  const std::vector<int>& kTareasARealizar,
  const Problema& kGrafo
) const {
  const Nodo* kNodoRaiz = kGrafo.getGrafo()[0];
  TareaMaquinaPosicion mejor_eleccion;
  mejor_eleccion.tarea = maquinas_copia[0].getTareas()[0];
  mejor_eleccion.indice_maquina = 0;
  mejor_eleccion.posicion = 1;
  int mejor_incremento = std::numeric_limits<int>::max();
  const int kSizeTareasARealizar = kTareasARealizar.size();
  for (int i = 0; i < kSizeTareasARealizar; ++i) {
    Nodo* tarea = kGrafo.getGrafo()[kTareasARealizar[i]];
    for (int j = 0; j < kNumeroMaquinas; ++j) {  
      const int kNumTareas = maquinas_copia[j].getTareas().size();
      for (int k = 1; k <= kNumTareas; ++k) {
        Solucion cada_maquina = maquinas_copia[j];
        cada_maquina.insertarTarea(tarea, k);             
        int incremento_tct = cada_maquina.calcularTCT(kNodoRaiz);
        if (incremento_tct < mejor_incremento) {
          mejor_eleccion.tarea = tarea;
          mejor_eleccion.indice_maquina = j;
          mejor_eleccion.posicion = k;
          mejor_incremento = incremento_tct;
        }
      }
    }
  }
  return mejor_eleccion;
}