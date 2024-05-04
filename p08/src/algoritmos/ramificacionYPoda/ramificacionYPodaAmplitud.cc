#include "ramificacionYPodaAmplitud.h"

Solucion RamificacionYPodaAmplitud::ejecutar(
  const Problema& kProblema, const int kNumElementosEnSolucion, const int kIteraciones
) {  
  const Matriz& kDistancias = kProblema.getDistancias();
  GRASP algortimo;
  solucion_ = algortimo.ejecutar(kProblema, kNumElementosEnSolucion, kIteraciones);
  Solucion mejor_solucion = solucion_;
  double cota_inferior = mejor_solucion.getFuncionObjetivo();
  std::cout << "GRASP ini: " << cota_inferior << std::endl;
  std::pair<Matriz, std::vector<int>> elementos_problema = (
    obtenerElementosFueraDeSolucion(kProblema, mejor_solucion)
  );
  ramificacionYPoda(kDistancias, elementos_problema, kNumElementosEnSolucion, mejor_solucion, cota_inferior);
  return solucion_;
}

void RamificacionYPodaAmplitud::ramificacionYPoda(
  const Matriz& kDistancias, const std::pair<Matriz, std::vector<int>>& kElementosProblema,
  const int kNumElementosEnSolucion, Solucion& mejor_solucion, double& cota_inferior
) {
  // Declaración de la cola de prioridades con comparador en la propia declaración
  auto comparador = [](const auto& a, const auto& b) {
    return std::get<2>(a) > std::get<2>(b); // Ordenar por el tercer elemento (double) de la tupla de menor a mayor
  };
  std::priority_queue<std::tuple<Solucion, std::pair<Matriz, std::vector<int>>, double, int>,
                      std::vector<std::tuple<Solucion, std::pair<Matriz, std::vector<int>>, double, int>>,
                      decltype(comparador)> nodos_hoja(comparador);
  nodos_hoja.push(std::make_tuple(mejor_solucion, kElementosProblema, cota_inferior, 0));
  int nivel;
  Solucion cada_solucion_inicial;
  std::pair<Matriz, std::vector<int>> puntos_fuera;
  std::pair<std::vector<double>, int> punto_dentro_antes_de_sacar;
  do {
    // Almacenar cada estructura
    if (!nodos_hoja.empty()) {
      cada_solucion_inicial = std::get<0>(nodos_hoja.top());
      puntos_fuera = std::get<1>(nodos_hoja.top());
      cota_inferior = std::get<2>(nodos_hoja.top());
      nivel = std::get<3>(nodos_hoja.top());
      nodos_hoja.pop();
    }
    if (nivel < kNumElementosEnSolucion) {
      punto_dentro_antes_de_sacar = (
        std::make_pair(cada_solucion_inicial[nivel], cada_solucion_inicial.getIndicesElementosIntroducidos()[nivel])
      );    
    }
    // Recorremos los puntos de fuera del entorno para ramificar
    const int kNumPuntosProblema = puntos_fuera.first.size();
    for (int i = 0; (i < kNumPuntosProblema && nivel < kNumElementosEnSolucion); ++i) { // Cada mismo nivel
      solucion_ = cada_solucion_inicial;
      solucion_.setCoordenadas()[nivel] = puntos_fuera.first[i];
      solucion_.setIndicesElementosIntroducidos()[nivel] = puntos_fuera.second[i];
      double cota_inferior_actual = calcularFuncionObjetivoParcial(cada_solucion_inicial, nivel, kDistancias);
      if (cota_inferior_actual >= cota_inferior) { // Si encuentro mejores soluciones almacenar
        std::pair<Matriz, std::vector<int>> aux_actualizar_puntos_fuera = puntos_fuera;
        aux_actualizar_puntos_fuera.first[i] = punto_dentro_antes_de_sacar.first;
        aux_actualizar_puntos_fuera.second[i] = punto_dentro_antes_de_sacar.second;
        // Almacenar hijos
        nodos_hoja.push(std::make_tuple(solucion_, aux_actualizar_puntos_fuera, cota_inferior_actual, nivel + 1)); // Partir de la primera
      }
    }
    if (nivel < (kNumElementosEnSolucion - 1)) {
      nodos_hoja.push(std::make_tuple(cada_solucion_inicial, puntos_fuera, cota_inferior, nivel + 1));
    }
  } while (!nodos_hoja.empty());
  solucion_ = cada_solucion_inicial;
  solucion_.setFuncionObjetivo() = cota_inferior;
}

std::pair<Matriz, std::vector<int>> RamificacionYPodaAmplitud::obtenerElementosFueraDeSolucion(
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