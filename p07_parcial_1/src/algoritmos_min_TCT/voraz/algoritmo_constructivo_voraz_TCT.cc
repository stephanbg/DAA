#include "./algoritmo_constructivo_voraz_TCT.h"

const std::vector<Maquina> AlgoritmoConstructivoVoraz::ejecutar(
  const int kNumeroMaquinas,
  const GrafoDirigidoCompleto& kGrafo
) const {
  std::vector<Maquina> maquinas(kNumeroMaquinas); // m Maquinas
  std::vector<bool> tareas_realizadas(kGrafo.getGrafo().size() - 1, false); // Sin nodo ficticio
  //std::cout << "Num Maquinas " << kNumeroMaquinas << std::endl;
  // Seleccionar las m tareas con menores valores de t0j
  seleccionarTareasInciales(maquinas, kGrafo, tareas_realizadas);
  /*for (int i = 0; i < tareas_realizadas.size(); ++i) {
    std::cout << "TAREA " << i << ": " << tareas_realizadas[i] << std::endl;
  }*/
  //std::cout << kGrafo << std::endl;
  while (contieneFalso(tareas_realizadas)) {
    std::vector<Maquina> maquinas_copia = maquinas;
    minimizarIncrementoTCT(kNumeroMaquinas, maquinas, maquinas_copia, tareas_realizadas, kGrafo);
    //for (auto a : maquinas) {
    //  std::cout << "MAQUINA: ";
    //  for (auto b : a.getTareas()) {
   //     std::cout << b->getId() << " ";
    //  }     
   //   std::cout <<  std::endl;
   // }
    //std::cout <<  std::endl;
    //exit(EXIT_FAILURE);
    maquinas = maquinas_copia;
  }
  //exit(EXIT_FAILURE);
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
            const bool kVisitado1 = tareas_realizadas[kId1 - 1];
            const bool kVisitado2 = tareas_realizadas[kId2 - 1];
            if (kVisitado1 && !kVisitado2) return false;
            if (!kVisitado1 && kVisitado2) return true;
            return kArco1.getCoste() < kArco2.getCoste();
        });
    //std::cout << "min_t0j: " << min_t0j->getNodoDestino()->getId() << std::endl;
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
  std::vector<bool>& tareas_realizadas,
  const GrafoDirigidoCompleto& kGrafo
) const {
  int mejor_maquina = -1;
  int mejor_posicion = -1;
  int mejor_incremento = std::numeric_limits<int>::max();
  for (int i = 0; i < kNumeroMaquinas; ++i) {
    const int kNumTareas = kMaquinas[i].getTareas().size(); 
    for (int j = 0; j < kNumTareas; ++j) {
      const int kIncrementoTct = calcularTCT(kMaquinas, i, j);
      //exit(EXIT_FAILURE);
      //std::cout << "kIncrementoTct: " << kIncrementoTct << " en la maquina " << i << " con la tarea " << kMaquinas[i].getTareas()[j]->getId()  << std::endl;
      //std::cout << "Indice de la maquina: " << i << std::endl;
      //std::cout << "Indice de tarea: " << j << std::endl;
      // Actualizar si encontramos una mejor tarea-maquina-posición
      if (kIncrementoTct < mejor_incremento) {
        mejor_maquina = i;
        mejor_posicion = j;
        mejor_incremento = kIncrementoTct;
      }
    }
  }
  //std::cout << "mejor_maquina: " << mejor_maquina << std::endl;
  //std::cout << "mejor_posicion: " << mejor_posicion << std::endl;
  //std::cout << "mejor_incremento: " << mejor_incremento << std::endl;
  const Nodo* kTareaNueva = encontrarMejorTarea(
    kGrafo, tareas_realizadas, stoi(kMaquinas[mejor_maquina].getTareas()[mejor_posicion]->getId())
  );
  tareas_realizadas[stoi(kTareaNueva->getId()) - 1] = true;
  maquinas_copia[mejor_maquina].insertarTarea(kTareaNueva, mejor_posicion);
}

int contador = 0;

const int AlgoritmoConstructivoVoraz::calcularTCT(
  const std::vector<Maquina>& kMaquinas,
  const int kMaquinaIndice,
  const int kTareaIndice
) const {
  int tct = 0;
  const auto& kTareas = kMaquinas[kMaquinaIndice].getTareas();
  const int kNumTareas = kTareas.size();
  for (int i = 0; i < kNumTareas - 1; ++i) {
    const int kCoeficiente = kNumTareas - i;
    if (i == kTareaIndice) {
      // Ruta desde la nueva tarea hasta la primera tarea en la secuencia
      tct += kCoeficiente * kTareas[i]->getCosteHaciaVecino(kTareas[0]);
    }
    // Ruta desde la tarea actual hasta la siguiente tarea en la secuencia
    tct += kCoeficiente * kTareas[i]->getCosteHaciaVecino(kTareas[i + 1]);
  }
  if (kTareaIndice == kNumTareas) {
    // Ruta desde la última tarea en la secuencia hasta la nueva tarea
    tct += kTareas[kNumTareas - 1]->getCosteHaciaVecino(kTareas[0]);
  }
  return tct;
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
  for (int i = 1; i < kCantidadVecinos; ++i) {
    const int kNodoDestinoId = stoi(kVecinos[i].getNodoDestino()->getId());
    if (!kTareasRealizadas[kNodoDestinoId - 1]) { // Verificar si la tarea no ha sido realizada
      if (kVecinos[i].getCoste() < mejor_costo) { // Verificar si el costo es mejor que el actual
        mejor_tarea_indice = i; // Almacenar el índice del vecino actual dentro de los vecinos de la tarea
        mejor_costo = kVecinos[i].getCoste();
      }
    }
  }
  //std::cout << "Siguiente mejor tarea: " << kVecinos[mejor_tarea_indice].getNodoDestino()->getId() << std::endl;
  //std::cout << kGrafo << std::endl;
  //exit(EXIT_FAILURE);
  // Retornamos la mejor tarea encontrada
  if (mejor_tarea_indice != -1) return kVecinos[mejor_tarea_indice].getNodoDestino();
  return nullptr;
}