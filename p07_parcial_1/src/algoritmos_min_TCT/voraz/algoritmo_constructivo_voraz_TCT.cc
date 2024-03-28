#include "./algoritmo_constructivo_voraz_TCT.h"

const std::vector<Maquina> AlgoritmoConstructivoVoraz::ejecutar(
  const int kNumeroMaquinas,
  const GrafoDirigidoCompleto& kGrafo
) {
  std::vector<Maquina> maquinas(kNumeroMaquinas); // m Maquinas
  std::vector<int> tareas_a_realizar(kGrafo.getGrafo().size() - 1);
  std::iota(tareas_a_realizar.begin(), tareas_a_realizar.end(), 1);
  seleccionarTareasInciales(maquinas, kGrafo, tareas_a_realizar);
  std::vector<Maquina> maquinas_copia = maquinas;
  while (!tareas_a_realizar.empty()) {
    const TareaMaquinaPosicion kMejorEleccion = obtenerTareaMaquinaPosicion(
      kNumeroMaquinas, maquinas_copia, tareas_a_realizar, kGrafo
    );
    maquinas_copia[kMejorEleccion.indice_maquina].insertarTarea(kMejorEleccion.tarea, kMejorEleccion.posicion);
    auto it = std::find(tareas_a_realizar.begin(), tareas_a_realizar.end(), stoi(kMejorEleccion.tarea->getId()));
    tareas_a_realizar.erase(it);
    maquinas = maquinas_copia;
  }
  for (int i = 0; i < kNumeroMaquinas; ++i) {
    maquinas[i].setTCT() = calcularTCT(kGrafo.getGrafo()[0], maquinas[i]);
  }
  calcularFuncionObjetivo(maquinas);
  return maquinas;
}

void AlgoritmoConstructivoVoraz::seleccionarTareasInciales(
  std::vector<Maquina>& maquinas,
  const GrafoDirigidoCompleto& kGrafo,
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

const TareaMaquinaPosicion AlgoritmoConstructivoVoraz::obtenerTareaMaquinaPosicion(
  const int kNumeroMaquinas,
  std::vector<Maquina>& maquinas_copia,
  const std::vector<int>& kTareasARealizar,
  const GrafoDirigidoCompleto& kGrafo
) const {
  const Nodo* kNodoRaiz = kGrafo.getGrafo()[0];
  TareaMaquinaPosicion mejor_eleccion;
  mejor_eleccion.tarea = maquinas_copia[0].getTareas()[0];
  mejor_eleccion.indice_maquina = 0;
  mejor_eleccion.posicion = 1;
  long long int mejor_incremento = std::numeric_limits<long long int>::max();
  for (int i = 0; i < kNumeroMaquinas; ++i) {  
    const int kNumTareas = maquinas_copia[i].getTareas().size();
    for (int j = 1; j <= kNumTareas; ++j) {
      Maquina cada_maquina = maquinas_copia[i];
      Nodo* tarea = kGrafo.getGrafo()[kTareasARealizar[0]];
      cada_maquina.insertarTarea(tarea, j);      
      long long int incremento_tct = calcularTCT(kNodoRaiz, cada_maquina); 
      if (incremento_tct < mejor_incremento) {
        mejor_eleccion.tarea = tarea;
        mejor_eleccion.indice_maquina = i;
        mejor_eleccion.posicion = j;
        mejor_incremento = incremento_tct;
      }       
      const int kSizeTareasARealizar = kTareasARealizar.size();
      for (int k = 1; k < kSizeTareasARealizar; ++k) {       
        tarea = kGrafo.getGrafo()[kTareasARealizar[k]];
        cada_maquina.cambiarTarea(tarea, j);
        incremento_tct = calcularTCT(kNodoRaiz, cada_maquina);
        if (incremento_tct < mejor_incremento) {
          mejor_eleccion.tarea = tarea;
          mejor_eleccion.indice_maquina = i;
          mejor_eleccion.posicion = j;
          mejor_incremento = incremento_tct;
        }
      }
    }
  }
  return mejor_eleccion;
}