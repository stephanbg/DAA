#include "ramificacionYPodaAmplitud.h"

Solucion RamificacionYPodaAmplitud::ejecutar(
  const Problema& kProblema, const int kNumElementosEnSolucion, const int kIteraciones
) {  
  const Matriz& kDistancias = kProblema.getDistancias();
  GRASP algortimo;
  solucion_ = algortimo.ejecutar(kProblema, kNumElementosEnSolucion, 1);
  Solucion mejor_solucion = solucion_;
  double cota_inferior = mejor_solucion.getFuncionObjetivo();
  std::pair<Matriz, std::vector<int>> elementos_problema = (
    obtenerElementosFueraDeSolucion(kProblema, mejor_solucion)
  );
  ramificacionYPoda(kDistancias, elementos_problema, kNumElementosEnSolucion, mejor_solucion, cota_inferior);
  std::cout << "DESPUES\n";
  //std::cout << solucion_ << std::endl;  
  for (auto a : solucion_.getIndicesElementosIntroducidos()) {
    std::cout << a << ", ";
  }
  std::cout << std::endl;
  std::cout << "cota_inferior_actual: " << cota_inferior << std::endl;
  exit(1);
  return solucion_;
}

  // Declaración de la cola de prioridades con comparador en la propia declaración
  auto comparador = [](const auto& a, const auto& b) {
    // Ordenar por el tercer elemento (double) de la tupla de menor a mayor
    return std::get<2>(a) > std::get<2>(b);
  };


void mostrar(std::priority_queue<std::tuple<Solucion, std::pair<Matriz, std::vector<int>>, double, int>,
              std::vector<std::tuple<Solucion, std::pair<Matriz, std::vector<int>>, double, int>>,
              decltype(comparador)> nodos_hoja) {
  while (!nodos_hoja.empty()) {
    // Obtener el elemento de mayor prioridad (el primero de la cola)
    auto top_element = nodos_hoja.top();
    // Procesar el elemento (en este ejemplo, imprimir el valor del tercer elemento de la tupla)
    std::cout << std::get<0>(top_element) << std::endl;
    std::cout << "Indices reales dentro" << std::endl;
    for (auto a : std::get<0>(top_element).getIndicesElementosIntroducidos()) {
      std::cout << a << ", ";
    }  
    std::cout << std::endl;  
    std::cout << "Puntos fuera" << std::endl;
    std::cout << std::get<1>(top_element).first << std::endl;
    std::cout << "Indices reales fuera" << std::endl;
    for (auto a : std::get<1>(top_element).second) {
      std::cout << a << ", ";
    }
    std::cout << std::endl;
    std::cout << "Funcion objetivo" << std::endl;
    std::cout << std::get<2>(top_element) << std::endl;
    // Eliminar el elemento de la cola
    nodos_hoja.pop();
  }
}


void RamificacionYPodaAmplitud::ramificacionYPoda(
  const Matriz& kDistancias, const std::pair<Matriz, std::vector<int>>& kElementosProblema,
  const int kNumElementosEnSolucion, Solucion& mejor_solucion, double& cota_inferior
) {
  std::cout << "INICIAL" << std::endl;
  std::cout << "cota_inferior: " << cota_inferior << std::endl;
  //std::cout << solucion_ << std::endl;  
  for (auto a : solucion_.getIndicesElementosIntroducidos()) {
    std::cout << a << ", ";
  }
  std::cout << std::endl;  
  std::priority_queue<std::tuple<Solucion, std::pair<Matriz, std::vector<int>>, double, int>,
                      std::vector<std::tuple<Solucion, std::pair<Matriz, std::vector<int>>, double, int>>,
                      decltype(comparador)> nodos_hoja(comparador);
  nodos_hoja.push(std::make_tuple(mejor_solucion, kElementosProblema, cota_inferior, 0));
  int nivel;
  Solucion cada_solucion_inicial;
  std::pair<Matriz, std::vector<int>> puntos_fuera;
  bool existe_hijo;
  do {
    // Almacenar cada estructura
    if (!nodos_hoja.empty()) {
      cada_solucion_inicial = std::get<0>(nodos_hoja.top());
      puntos_fuera = std::get<1>(nodos_hoja.top());
      cota_inferior = std::get<2>(nodos_hoja.top());
      nivel = std::get<3>(nodos_hoja.top());
      //std::cout << "nivel ACTUAL: " << nivel << std::endl;
      nodos_hoja.pop();
    }
    existe_hijo = false;
    // Recorremos los puntos de fuera del entorno para ramificar
    const int kNumPuntosProblema = puntos_fuera.first.size();
    for (int i = 0; (i < kNumPuntosProblema && nivel < kNumElementosEnSolucion); ++i) { // Cada mismo nivel
      solucion_ = cada_solucion_inicial;
      solucion_.setCoordenadas()[nivel] = puntos_fuera.first[i];
      solucion_.setIndicesElementosIntroducidos()[nivel] = puntos_fuera.second[i];
      double cota_inferior_actual = calcularFuncionObjetivoParcial(cada_solucion_inicial, nivel, kDistancias);
      //std::cout << "FOBJ: " << cota_inferior_actual << std::endl;
      if (cota_inferior_actual >= cota_inferior) { // Si encuentro mejores soluciones almacenar
        std::pair<Matriz, std::vector<int>> aux_actualizar_puntos_fuera = puntos_fuera;
        aux_actualizar_puntos_fuera.first.eliminarElemento(i);
        aux_actualizar_puntos_fuera.second.erase(aux_actualizar_puntos_fuera.second.begin() + i);        
        nodos_hoja.push(std::make_tuple(solucion_, aux_actualizar_puntos_fuera, cota_inferior_actual, nivel + 1));
        existe_hijo = true;
        /*std::cout << "PADRE" << std::endl;
        //std::cout << "cota_inferior_actual: " << cota_inferior_actual << std::endl;
        //std::cout << solucion_ << std::endl;
        for (auto a : cada_solucion_inicial.getIndicesElementosIntroducidos()) {
          std::cout << a << ", ";
        }
        std::cout << std::endl;
        for (auto a : puntos_fuera.second) {
          std::cout << a << ", ";
        }
        std::cout << std::endl;          
        std::cout << "NUEVO" << std::endl;
        //std::cout << "cota_inferior_actual: " << cota_inferior_actual << std::endl;
        //std::cout << solucion_ << std::endl;
        for (auto a : solucion_.getIndicesElementosIntroducidos()) {
          std::cout << a << ", ";
        }
        std::cout << std::endl;
        for (auto a : aux_actualizar_puntos_fuera.second) {
          std::cout << a << ", ";
        }
        std::cout << std::endl;       */ 
      }
    }
    if (!existe_hijo && nivel < (kNumElementosEnSolucion - 1)) {
      nodos_hoja.push(std::make_tuple(cada_solucion_inicial, puntos_fuera, cota_inferior, nivel + 1));
      //std::cout << "nivel SIGUIENTE: " << nivel + 1 << std::endl;
    }
    //mostrar(nodos_hoja);
  } while (nodos_hoja.size() > 0);
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