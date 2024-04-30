/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 19 de Abril de 2024
 * @file busquedaTabu.cc
 * @brief Implementación de la clase BusquedaTabu que hereda de AlgoritmosDiversidadMaxima
 * para resolver el problema de Maximum diversity problem.
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p08/src}
 */

#include "busquedaTabu.h"

/**
 * @brief Ejecuta el algoritmo de Búsqueda Tabú para encontrar una solución al problema dado.
 * 
 * @param kProblema El problema sobre el cual se ejecutará el algoritmo.
 * @param kNumElementosEnSolucion El número de elementos que se desea en la solución.
 * @param kIteraciones No se usa.
 * @return La mejor solución encontrada por el algoritmo.
 */
Solucion BusquedaTabu::ejecutar(const Problema& kProblema, const int kNumElementosEnSolucion, const int kIteraciones) {  
  GRASP algortimoGRASP;
  solucion_ = algortimoGRASP.ejecutar(kProblema, kNumElementosEnSolucion, 1);  
  std::pair<Matriz, std::vector<int>> elementos_restantes = obtenerElementosFueraDeSolucion(kProblema, solucion_);
  const int kTenenciaTabu = 5, kIteracionesTabu = 3;
  double mejor_funcion_objetivo = solucion_.getFuncionObjetivo();
  int iter = 0;
  Solucion mejor_solucion = solucion_;
  const Matriz& kDistancias = kProblema.getDistancias();
  while (++iter < kIteraciones) {
    busquedaTabu(solucion_, elementos_restantes, kDistancias, kTenenciaTabu, kIteracionesTabu);
    const double kFuncionObjetivoCadaIter = solucion_.getFuncionObjetivo();
    if (kFuncionObjetivoCadaIter > mejor_funcion_objetivo) {
      mejor_funcion_objetivo = kFuncionObjetivoCadaIter;
      mejor_solucion = solucion_;
    }
    solucion_ = algortimoGRASP.ejecutar(kProblema, kNumElementosEnSolucion, 1);
    elementos_restantes = obtenerElementosFueraDeSolucion(kProblema, solucion_);
  }
  solucion_ = mejor_solucion;
  solucion_.setFuncionObjetivo() = mejor_funcion_objetivo;  
  return solucion_;
}

/**
 * @brief Realiza la Búsqueda Tabú para mejorar una solución inicial.
 * 
 * @param kSolucionInicial La solución inicial a mejorar mediante Búsqueda Tabú.
 * @param elementos_restantes Los elementos que quedan fuera de la solución inicial.
 * @param kDistancias La matriz de distancias entre los elementos del problema.
 * @param kTenenciaTabu El tamaño de la lista tabú.
 * @param kIteracionesTabu El número máximo de iteraciones que realizará la Búsqueda Tabú.
 */
void BusquedaTabu::busquedaTabu(
  const Solucion& kSolucionInicial,
  std::pair<Matriz, std::vector<int>>& elementos_restantes,
  const Matriz& kDistancias,
  const int kTenenciaTabu,
  const int kIteracionesTabu
) { 
  std::pair<Matriz, std::vector<int>> cada_elementos_restantes = elementos_restantes, mejor_elementos_restantes;
  Solucion mejor_solucion = kSolucionInicial, cada_solucion_inicial = kSolucionInicial;
  double criterio_aspiracion = kSolucionInicial.getFuncionObjetivo(), funcion_objetivo_actual;
  const int kSizeElementosRestantes = elementos_restantes.first.size();
  const int kSizeElementosSolucion = kSolucionInicial.size();
  int mejor_indice_solucion, mejor_indice_entorno, iter = 0, iteraciones_sin_mejorar = 0;
  std::list<std::pair<int, int>> lista_tabu;
  do {
    for (int i = 0; i < kSizeElementosSolucion; ++i) {
      const int kIndiceEnSolucion = cada_solucion_inicial.getIndicesElementosIntroducidos()[i];       
      for (int j = 0; j < kSizeElementosRestantes; ++j) {
        const int kIndiceEnEntorno = cada_elementos_restantes.second[j];      
        if (contienePar(lista_tabu, std::make_pair(kIndiceEnSolucion, kIndiceEnEntorno))) continue;
        solucion_ = cada_solucion_inicial;
        elementos_restantes = cada_elementos_restantes;         
        solucion_.swapPuntoEIndice(i, j, elementos_restantes); 
        funcion_objetivo_actual = calcularFuncionObjetivoParcial(cada_solucion_inicial, i, kDistancias);       
        if (criterio_aspiracion < funcion_objetivo_actual) {   
          criterio_aspiracion = funcion_objetivo_actual;
          mejor_solucion = solucion_;       
          mejor_indice_solucion = kIndiceEnSolucion;
          mejor_indice_entorno = kIndiceEnEntorno;
          mejor_elementos_restantes = elementos_restantes;
        }
      }
    }
    if (criterio_aspiracion > cada_solucion_inicial.getFuncionObjetivo()) {
      cada_solucion_inicial = mejor_solucion;
      cada_elementos_restantes = mejor_elementos_restantes;
      iteraciones_sin_mejorar = 0;
    } else if (++iteraciones_sin_mejorar > 3) break;
    if (lista_tabu.size() == kTenenciaTabu) lista_tabu.pop_front();  
    lista_tabu.push_back(std::make_pair(mejor_indice_solucion, mejor_indice_entorno));    
  } while (++iter <= kIteracionesTabu);
  solucion_ = mejor_solucion;
  solucion_.setFuncionObjetivo() = criterio_aspiracion;
}

/**
 * @brief Obtiene los elementos que están fuera de la solución dada.
 * 
 * @param kProblema El problema sobre el cual se está trabajando.
 * @param kMejorSolucion La mejor solución encontrada hasta el momento.
 * @return Un par que contiene la matriz de elementos fuera de la solución y sus índices.
 */
std::pair<Matriz, std::vector<int>> BusquedaTabu::obtenerElementosFueraDeSolucion(
  const Problema& kProblema,
  const Solucion& kMejorSolucion
) const {
  Matriz cada_elemento_matriz;
  std::vector<int> cada_elemento_indice;
  const std::vector<int>& kIndicesIntroducidos = kMejorSolucion.getIndicesElementosIntroducidos();
  const int kSizeIndicesEnSolucion = kIndicesIntroducidos.size();
  for (const int& kIndiceProblema : kProblema.getIndicesProblema()) {
    bool esta_en_solucion = false;
    for (int i = 0; i < kSizeIndicesEnSolucion; ++i) {
      if (kIndicesIntroducidos[i] == kIndiceProblema) {
        esta_en_solucion = true;
        break;
      }
    }
    if (!esta_en_solucion) {
      cada_elemento_matriz.setMatriz().push_back(kProblema.getCoordenadas()[kIndiceProblema]);
      cada_elemento_indice.push_back(kIndiceProblema);
    }
  }
  return std::make_pair(cada_elemento_matriz, cada_elemento_indice);
}