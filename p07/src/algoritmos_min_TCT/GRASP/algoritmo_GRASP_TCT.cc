/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 1 de Abril de 2024
 * @file algoritmo_GRASP_TCT.h
 * @brief Implementación de la clase AlgoritmoGRASP que hereda de
 * la clase abstracta AlgoritmoMinimizarTCT para minimizar el TCT mediante un algoritmo GRASP
 * solo haciendo la fase constructiva
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07/src}
 */

#include "./algoritmo_GRASP_TCT.h"

/**
 * @brief Ejecuta el algoritmo GRASP. Realiza una fase ontructiva y posteriormente
 * realiza la búsqueda local para mejorar los resultados y los compara en 100 iteraciones
 * 
 * @param kNumeroMaquinas Número de máquinas disponibles.
 * @param kGrafo Grafo que representa las tareas y sus dependencias.
 * @return Devuelve la máquina con la mejor solución
 */
const std::vector<Solucion> AlgoritmoGRASP::ejecutar(
  const int kNumeroMaquinas,
  const Problema& kGrafo
) {
  const Nodo* kNodoRaiz = kGrafo.getGrafo()[0];
  std::vector<Solucion> solucion_inicial = faseConstructiva(kGrafo, kNumeroMaquinas),
  mejor_solucion = busquedaLocal(solucion_inicial, kNodoRaiz), solucion_actual, mejor_solucion_aux;
  int contador = 0, mejor_funcion_objetivo = Solucion::getFuncionObjetivo(), funcion_objetivo_actual;
  do {
    solucion_actual = faseConstructiva(kGrafo, kNumeroMaquinas);
    mejor_solucion_aux = busquedaLocal(solucion_actual, kNodoRaiz);
    funcion_objetivo_actual = Solucion::getFuncionObjetivo();
    if (funcion_objetivo_actual < mejor_funcion_objetivo) {
      mejor_solucion = mejor_solucion_aux;
      mejor_funcion_objetivo = funcion_objetivo_actual;
    }
  } while (++contador <= 100);
  Solucion::setFuncionObjetivo() = mejor_funcion_objetivo;
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
  for (int i = 0; i < kSizeNodosAleatorios; i++) maquinas[i % maquinas.size()].añadirTarea(nodos_aleatorios[i]);
  // Calcula el TCT de cada máquina
  const Nodo* kNodoRaiz = kGrafo.getGrafo()[0];
  const int kNumeroMaquinas = maquinas.size();
  for (int i = 0; i < kNumeroMaquinas; ++i) maquinas[i].calcularTCT(kNodoRaiz);
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
 * @brief Calcula la Lista Restringida de Candidatos (LRC) utilizando una heurística dada.
 * 
 * @param kNodos El conjunto de nodos del problema.
 * @param kHeuristica El valor de la heurística utilizado para calcular la LRC.
 * @return Un vector que contiene punteros a los nodos que forman parte de la LRC.
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
  for (int i = 0; i < contador; ++i) lista_restringida_candidatos.push_back(kNodos[i]);
  return lista_restringida_candidatos;
}