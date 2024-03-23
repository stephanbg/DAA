#include "./algoritmo_constructivo_voraz_TCT.h"

const std::vector<Maquina> AlgoritmoConstructivoVoraz::ejecutar(
  const int kNumeroMaquinas,
  const GrafoDirigidoCompleto& kGrafo
) const {
  std::vector<Maquina> maquinas(kNumeroMaquinas); // m Maquinas
  std::vector<bool> tareas_realizadas(kGrafo.getGrafo().size() - 1, false);
  // Seleccionar las m tareas con menores valores de t0j
  seleccionarTareasInciales(maquinas, kGrafo, tareas_realizadas);
  while (contieneFalso(tareas_realizadas)) {
    std::vector<Maquina> maquinas_copia = maquinas;
    minimizarIncrementoTCT(kNumeroMaquinas, maquinas, maquinas_copia, tareas_realizadas, kGrafo);
    maquinas = maquinas_copia;
  }
  return maquinas;
}

void AlgoritmoConstructivoVoraz::seleccionarTareasInciales(
  std::vector<Maquina>& maquinas,
  const GrafoDirigidoCompleto& kGrafo,
  std::vector<bool>& tareas_realizadas
) const {
const int kNumeroMaquinas = maquinas.size();
for (int i = 0; i < kNumeroMaquinas; ++i) {
    auto& vecinos = kGrafo.getGrafo()[0]->getNodosVecinos(); // Nodo ficticio 0
    // Buscar mínima tarea no realizada
    auto min_t0j = std::min_element(vecinos.begin() + 1, vecinos.end(),
        [&tareas_realizadas](const Arco& kArco1, const Arco& kArco2) { 
            const int kId1 = stoi(kArco1.getNodoDestino()->getId());
            const int kId2 = stoi(kArco2.getNodoDestino()->getId());
            const bool kVisitado1 = tareas_realizadas[kId1];
            const bool kVisitado2 = tareas_realizadas[kId2];
            if (kVisitado1 && !kVisitado2) return false;
            if (!kVisitado1 && kVisitado2) return true;
            return kArco1.getCoste() < kArco2.getCoste();
        });
    int min_t0j_indice = std::distance(vecinos.begin(), min_t0j);
    // Marcar la tarea como realizada y añadirla a una máquina
    tareas_realizadas[min_t0j_indice - 1] = true;
    maquinas[i].crearPrimeraTarea(min_t0j->getNodoDestino());
  }
}

void AlgoritmoConstructivoVoraz::minimizarIncrementoTCT(
  const int kNumeroMaquinas,
  const std::vector<Maquina>& kMaquinas,
  std::vector<Maquina>& maquinas_copia,
  const std::vector<bool>& kTareasRealizadas,
  const GrafoDirigidoCompleto& kGrafo
) const {
  int mejor_maquina = -1;
  int mejor_posicion = -1;
  int mejor_incremento = std::numeric_limits<int>::max();
  for (int i = 0; i < kNumeroMaquinas; ++i) {
    const int kNumTareas = kMaquinas[i].getTareas().size(); 
    for (int j = 0; j < kNumTareas; ++j) {
      const int kIncrementoTct = calcularFuncionObjetivo(kMaquinas, i, j);
      // Actualizar si encontramos una mejor tarea-maquina-posición
      if (kIncrementoTct < mejor_incremento) {
        mejor_maquina = i;
        mejor_posicion = j;
        mejor_incremento = kIncrementoTct;
      }
    }
  }
  const Nodo* kTareaNueva = encontrarMejorTarea(kGrafo, kTareasRealizadas, mejor_posicion);
  maquinas_copia[mejor_maquina].insertarTarea(kTareaNueva, mejor_posicion);
}

const int AlgoritmoConstructivoVoraz::calcularFuncionObjetivo(
  const std::vector<Maquina>& kMaquinas,
  const int kMaquinaIndice,
  const int kTareaIndice
) const {
  int funcion_objetivo = 0;
  const std::vector<const Nodo*>& kTareas = kMaquinas[kMaquinaIndice].getTareas();
  const int kNumTareas = kTareas.size();
  for (int i = kTareaIndice; i < kNumTareas - 1; ++i) {
    // El coeficiente (kr - i + 1) indica el número de nodos después del nodo en la posición i
    int coeficiente = kNumTareas - i + 1;
    funcion_objetivo += coeficiente * kTareas[i]->getCosteHaciaVecino(kTareas[i + 1]);
  }
  return funcion_objetivo;
}

const Nodo* AlgoritmoConstructivoVoraz::encontrarMejorTarea(
  const GrafoDirigidoCompleto& kGrafo,
  const std::vector<bool>& kTareasRealizadas,
  const int kIndiceMejorTarea
) const {
  const auto& kVecinos = kGrafo.getGrafo()[kIndiceMejorTarea]->getNodosVecinos();
  int mejor_tarea_indice = -1;
  int mejor_costo = std::numeric_limits<int>::max();
  // Recorremos los vecinos para encontrar la mejor tarea disponible
  const int kCantidadVecinos = kVecinos.size();
  for (int i = 0; i < kCantidadVecinos; ++i) {
    const int kNodoDestinoId = stoi(kVecinos[i].getNodoDestino()->getId());
    if (!kTareasRealizadas[kNodoDestinoId]) { // Verificar si la tarea no ha sido realizada
      if (kVecinos[i].getCoste() < mejor_costo) { // Verificar si el costo es mejor que el actual
        mejor_tarea_indice = i;
        mejor_costo = kVecinos[i].getCoste();
      }
    }
  }
  // Retornamos la mejor tarea encontrada
  if (mejor_tarea_indice != -1) return kVecinos[mejor_tarea_indice].getNodoDestino();
  return nullptr;
}