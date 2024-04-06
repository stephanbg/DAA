#include "./ejecutar_algoritmos.h"

std::pair<std::vector<Solucion>, int> ejecutarAlgoritmo(
  AlgoritmoMinimizarTCT* algoritmo,
  int numero_maquinas,
  Problema& grafo
) {
  // Crear un objeto ControladorTiempo con una función lambda como argumento
  ControladorTiempo<std::vector<Solucion>, int, Problema&> tiempo(
    [&](int numeroMaquinas, Problema& grafo) { return algoritmo->ejecutar(numeroMaquinas, grafo); }
  );
  // Medir el tiempo de ejecución y obtener las soluciones
  std::vector<Solucion> maquinas = tiempo.medirTiempoFuncion(std::move(numero_maquinas), grafo);
  // Devolver las soluciones y el tiempo de ejecución
  return std::make_pair(std::move(maquinas), tiempo.getDuracion());
}