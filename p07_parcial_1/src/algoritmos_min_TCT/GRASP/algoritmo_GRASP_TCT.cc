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
  const Nodo* kNodoRaiz = kGrafo.getGrafo()[0];
  std::vector<Solucion> solucion_inicial = faseConstructiva(kGrafo, kNumeroMaquinas),
  mejor_solucion = busquedaLocal(solucion_inicial, kNodoRaiz), solucion_actual, mejor_solucion_aux;
  int contador = 0, funcion_objetivo_anterior = Solucion::getFuncionObjetivo(), funcion_objetivo_actual;
  do {
    solucion_actual = faseConstructiva(kGrafo, kNumeroMaquinas);
    mejor_solucion_aux = busquedaLocal(solucion_actual, kNodoRaiz);
    funcion_objetivo_actual = Solucion::getFuncionObjetivo();
    //std::cout << "funcion_objetivo_anterior: " << funcion_objetivo_anterior << std::endl;
    //std::cout << "funcion_objetivo_actual: " << funcion_objetivo_actual << std::endl;
    if (funcion_objetivo_actual < funcion_objetivo_anterior) {
      mejor_solucion = mejor_solucion_aux;
      funcion_objetivo_anterior = funcion_objetivo_actual;
      //std::cout << "MEJOR: " << funcion_objetivo_anterior << std::endl;
    }
  } while (++contador <= 100);
  Solucion::setFuncionObjetivo() = funcion_objetivo_anterior;
  return mejor_solucion;
}

/**
 * @brief Realiza la fase constructiva del algoritmo GRASP para generar soluciones iniciales.
 * 
 * @param kGrafo Grafo que representa las tareas y sus dependencias.
 * @return Vector que contiene las tareas seleccionadas para formar soluciones iniciales.
 */
const std::vector<Solucion> AlgoritmoGRASP::faseConstructiva(
  const Problema& kGrafo,
  const int kNumMaquinas
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
    const std::vector<const Nodo*> LRC = calcularLRC(nodos, kHeuristica);
    // De los nodos que la superan escoge uno aleatorio
    std::uniform_int_distribution<> dis(0, LRC.size() - 1);
    const int kIndiceAleatorio = dis(generador);
    const Nodo* kNodoAleatorio = *std::next(LRC.begin(), kIndiceAleatorio);
    // Inserta el nodo y lo elimina de la lista de candidatos
    nodos_aleatorios.push_back(kNodoAleatorio);
    auto it = std::find(nodos.begin(), nodos.end(), kNodoAleatorio);
    nodos.erase(it);
  }
  std::vector<Solucion> maquinas(kNumMaquinas);
  // Añadir tareas
  const int kSizeNodosAleatorios = nodos_aleatorios.size();
  for (int i = 0; i < kSizeNodosAleatorios; i++) {
    maquinas[i % maquinas.size()].añadirTarea(nodos_aleatorios[i]);   
  }
  // Calcula el TCT de cada máquina
  const Nodo* kNodoRaiz = kGrafo.getGrafo()[0];
  const int kNumeroMaquinas = maquinas.size();
  for (int i = 0; i < kNumeroMaquinas; ++i) {
    maquinas[i].calcularTCT(kNodoRaiz);
  }
  Solucion::calcularFuncionObjetivo(maquinas);
  return maquinas;
}

/**
 * @brief Calcula la heurística para evaluar la calidad de una solución parcial.
 * 
 * @param kNodos Vector que contiene las tareas seleccionadas en una solución parcial.
 * @return Valor que representa la calidad de la solución parcial.
 */
const double AlgoritmoGRASP::calcularHeurística(const std::vector<Nodo*>& kNodos) const {
  const double kAlfa = 0.5;
  return ceil(kAlfa * kNodos.size());
}

/**
 * @brief Identifica las tareas que superan cierto umbral de calidad según la heurística.
 * 
 * @param kNodos Vector que contiene las tareas seleccionadas en una solución parcial.
 * @param kHeuristica Valor que define el umbral de calidad.
 * @return Vector que contiene las tareas que superan el umbral de calidad.
 */
const std::vector<const Nodo*> AlgoritmoGRASP::calcularLRC(
  const std::vector<Nodo*>& kNodos, const double kHeuristica
) const {
  // Crear el conjunto lista de candidatos
  std::vector<const Nodo*> lista_restringida_candidatos;
  std::random_device dispositivo_aleatorio;
  std::mt19937 generador(dispositivo_aleatorio());  
  std::uniform_int_distribution<> dis(1, kHeuristica);
  int contador = dis(generador);
  for (int i = 0; i < contador; ++i) {
    lista_restringida_candidatos.push_back(kNodos[i]);
  }
  return lista_restringida_candidatos;
}