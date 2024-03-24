#include "./algoritmo_GRASP_TCT.h"

const std::vector<Maquina> AlgoritmoGRASP::ejecutar(
  const int kNumeroMaquinas,
  const GrafoDirigidoCompleto& kGrafo
) const {
  std::vector<Maquina> maquinas(kNumeroMaquinas); // m Maquinas
  faseConstructiva(kNumeroMaquinas, maquinas, kGrafo);
  return maquinas;
}

void AlgoritmoGRASP::faseConstructiva(
  const int kNumeroMaquinas, std::vector<Maquina>& maquinas, const GrafoDirigidoCompleto& kGrafo 
) const {
  /*std::vector<bool> tareas_realizadas(kGrafo.getGrafo().size() - 1, false); // Sin nodo ficticio
  // Fase constructiva de GRASP
  while (contieneFalso(tareas_realizadas)) {
    for (int i = 0; i < kNumeroMaquinas; ++i) {
      if (!contieneFalso(tareas_realizadas)) break;
      Maquina& maquina = maquinas[i];
      // Construir una solución greedy aleatorizada
      const Nodo* mejorTarea = construirSolucionGreedyAleatorizada(kGrafo, tareas_realizadas);
      // Insertar la tarea en la máquina actual
      maquina.crearPrimeraTarea(mejorTarea);
      // Marcar la tarea como realizada
      tareas_realizadas[stoi(mejorTarea->getId()) - 1] = true;
    }
  }*/
}