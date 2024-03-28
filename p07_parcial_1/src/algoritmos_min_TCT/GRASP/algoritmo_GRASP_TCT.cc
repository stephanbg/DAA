#include "./algoritmo_GRASP_TCT.h"

const std::vector<Maquina> AlgoritmoGRASP::ejecutar(
  const int kNumeroMaquinas,
  const GrafoDirigidoCompleto& kGrafo
) {
  std::vector<Maquina> maquinas(kNumeroMaquinas); // m Maquinas
  const std::vector<const Nodo*> kTareasAleatorias = faseConstructiva(kGrafo);
  const int kSizeNodosAleatorios = kTareasAleatorias.size();
  // Distribuir los nodos por las maquinas
  for (int i = 0; i < kSizeNodosAleatorios; i++) {
    maquinas[i % maquinas.size()].añadirTarea(kTareasAleatorias[i]);   
  }
  // Calcula el TCT de cada máquina
  for (int i = 0; i < kNumeroMaquinas; ++i) {
    maquinas[i].setTCT() = calcularTCT(kGrafo.getGrafo()[0], maquinas[i]);
  }
  // Calcula función objetivo
  calcularFuncionObjetivo(maquinas);  
  return maquinas;
}

const std::vector<const Nodo*> AlgoritmoGRASP::faseConstructiva(
  const GrafoDirigidoCompleto& kGrafo 
) const {
  // Inicializa variables
  std::vector<Nodo*> nodos = kGrafo.getGrafo();
  std::vector<const Nodo*> nodos_aleatorios;
  nodos.erase(nodos.begin()); // No tiene en cuenta el nodo ficticio
  std::random_device dispositivo_aleatorio;
  std::mt19937 generador(dispositivo_aleatorio());  
  // Mientras hayan candidatos
  while (!nodos.empty()) {
    // Calcula la heurística y de los nodos candidatos extrae los que la superan
    const double kHeuristica = calcularHeurística(nodos);
    const std::vector<const Nodo*> kNodosQueSuperanHeursitica =
        calcularNodosQueSuperanHeuristica(nodos, kHeuristica);
    // De los nodos que la superan escoge uno aleatorio
    std::uniform_int_distribution<> dis(0, kNodosQueSuperanHeursitica.size() - 1);
    const int kIndiceAleatorio = dis(generador);
    const Nodo* kNodoAleatorio = *std::next(kNodosQueSuperanHeursitica.begin(), kIndiceAleatorio);
    // Inserta el nodo y lo elimina de la lista de candidatos
    nodos_aleatorios.push_back(kNodoAleatorio);
    auto it = std::find(nodos.begin(), nodos.end(), kNodoAleatorio);
    nodos.erase(it);
  }
  return nodos_aleatorios; 
}

const double AlgoritmoGRASP::calcularHeurística(const std::vector<Nodo*>& kNodos) const {
  const double kAlfa = 0.5;
  const int kNumeroNodos = kNodos.size();
  int num_maximo_vecinos = kNodos[0]->getNodosVecinos().size();
  for (int i = 1; i < kNumeroNodos; ++i) {
    if (kNodos[i]->getNodosVecinos().size() > num_maximo_vecinos) {
      num_maximo_vecinos = kNodos[i]->getNodosVecinos().size();
    }
  }
  return kAlfa * num_maximo_vecinos;
}

const std::vector<const Nodo*> AlgoritmoGRASP::calcularNodosQueSuperanHeuristica(
  const std::vector<Nodo*>& kNodos, const double kHeuristica
) const {
  // Crear el conjunto nodos_superan_heuristica
  std::vector<const Nodo*> nodos_superan_heuristica;
  for (const auto& kCadaNodo : kNodos) {
    // Si la cantidad de nodos superan la heurística se escoge dicho nodo
    const int kCantidadVecinos = kCadaNodo->getNodosVecinos().size();
    if (kCantidadVecinos >= kHeuristica) nodos_superan_heuristica.push_back(kCadaNodo);
  }
  return nodos_superan_heuristica;
}