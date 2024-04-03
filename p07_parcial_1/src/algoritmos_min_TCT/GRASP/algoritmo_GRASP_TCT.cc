/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 20 de Marzo de 2024
 * @file algoritmo_GRASP_TCT.h
 * @brief Implementación de la clase AlgoritmoGRASP que hereda de
 * la clase abstracta AlgoritmoMinimizarTCT para minimizar el TCT mediante un algoritmo GRASP
 * solo haciendo la fase constructiva
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07_parcial_1/src}
 */

#include "./algoritmo_GRASP_TCT.h"

/**
 * @brief Ejecuta el algoritmo GRASP para asignar tareas a las máquinas de manera aleatoria.
 * 
 * @param kNumeroMaquinas Número de máquinas disponibles.
 * @param kGrafo Grafo que representa las tareas y sus dependencias.
 * @return Vector que contiene las asignaciones de tareas a las máquinas.
 */
const std::vector<Solucion> AlgoritmoGRASP::ejecutar(
  const int kNumeroMaquinas,
  const Problema& kGrafo
) {
  std::vector<Solucion> maquinas;
  int contador = 0, funcion_objetivo = std::numeric_limits<int>::max();
  const Nodo* kNodoRaiz = kGrafo.getGrafo()[0];
  do {
    std::vector<Solucion> maquinas_aux(kNumeroMaquinas); // m Maquinas
    const std::vector<const Nodo*> kTareasAleatorias = faseConstructiva(kGrafo);
    const int kSizeNodosAleatorios = kTareasAleatorias.size();
    // Distribuir los nodos por las maquinas
    for (int i = 0; i < kSizeNodosAleatorios; i++) {
      maquinas_aux[i % maquinas_aux.size()].añadirTarea(kTareasAleatorias[i]);   
    }
    // Calcula el TCT de cada máquina
    for (int i = 0; i < kNumeroMaquinas; ++i) {
      maquinas_aux[i].setTCT() = maquinas_aux[i].calcularTCT(kNodoRaiz);
    }
    // Calcula función objetivo
    calcularFuncionObjetivo(maquinas_aux);
    if (this->funcion_objetivo_ < funcion_objetivo) {
      maquinas = maquinas_aux;
      for (int i = 0; i < maquinas_aux.size(); ++i) {
        maquinas[i].setTCT() = maquinas_aux[i].getTCT();
      }      
      funcion_objetivo = this->funcion_objetivo_;
    }
    contador++;
  } while (contador != 100);
  this->funcion_objetivo_ = funcion_objetivo;
  std::cout << "ANTES DE LA BÚSQUEDA LOCAL\n";
  std::cout << "funcion_objetivo_: " << this->funcion_objetivo_ << std::endl;
  std::cout << "TCT 1: " << maquinas[0].getTCT() << std::endl;  
  std::cout << "TCT 2: " << maquinas[1].getTCT() << std::endl;   
  Solucion::mostrarTareasDeTodasLasMaquinas(maquinas);
  BusquedaLocal* algoritmoBusquedaLocal = new MovimientoReInsercionInterGRASP(maquinas);
  maquinas = algoritmoBusquedaLocal->busquedaLocal(kNodoRaiz);
  calcularFuncionObjetivo(maquinas);
  std::cout << "DESPUES DE LA BÚSQUEDA LOCAL\n";
  std::cout << "funcion_objetivo_: " << this->funcion_objetivo_ << std::endl;  
  std::cout << "TCT 1: " << maquinas[0].getTCT() << std::endl;  
  std::cout << "TCT 2: " << maquinas[1].getTCT() << std::endl;
  Solucion::mostrarTareasDeTodasLasMaquinas(maquinas);

  return maquinas;
}

/**
 * @brief Realiza la fase constructiva del algoritmo GRASP para generar soluciones iniciales.
 * 
 * @param kGrafo Grafo que representa las tareas y sus dependencias.
 * @return Vector que contiene las tareas seleccionadas para formar soluciones iniciales.
 */
const std::vector<const Nodo*> AlgoritmoGRASP::faseConstructiva(
  const Problema& kGrafo 
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

/**
 * @brief Calcula la heurística para evaluar la calidad de una solución parcial.
 * 
 * @param kNodos Vector que contiene las tareas seleccionadas en una solución parcial.
 * @return Valor que representa la calidad de la solución parcial.
 */
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

/**
 * @brief Identifica las tareas que superan cierto umbral de calidad según la heurística.
 * 
 * @param kNodos Vector que contiene las tareas seleccionadas en una solución parcial.
 * @param kHeuristica Valor que define el umbral de calidad.
 * @return Vector que contiene las tareas que superan el umbral de calidad.
 */
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