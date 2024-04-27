#include "GRASP.h"

Solucion GRASP::ejecutar(const Problema& kProblema, const int kNumElementosEnSolucion) {  
  const Matriz& kCoordenadas = kProblema.getCoordenadas();
  const std::vector<int>& kInidcesProblema = kProblema.getIndicesProblema();
  std::pair<Matriz, std::vector<int>> elementos_problema(
    kCoordenadas, kInidcesProblema
  );  
  const std::vector<double> kMedidaCalidad = calcularMedidaCalidad(elementos_problema, kProblema.getDistancias());
  faseConstructiva(kProblema, elementos_problema, kNumElementosEnSolucion, kMedidaCalidad);
  Solucion mejor_solucion = solucion_;
  double mejor_funcion_objetivo = solucion_.getFuncionObjetivo();
  int contador = 0;
  do {
    std::pair<Matriz, std::vector<int>> elementos_problema(kCoordenadas, kInidcesProblema);
    faseConstructiva(kProblema, elementos_problema, kNumElementosEnSolucion, kMedidaCalidad);
    const double kFuncionObjetivoCadaIter = solucion_.getFuncionObjetivo();
    if (kFuncionObjetivoCadaIter > mejor_funcion_objetivo) {
      mejor_funcion_objetivo = kFuncionObjetivoCadaIter;
      mejor_solucion = solucion_;
    }
  } while (++contador < 1000);
  solucion_ = mejor_solucion;
  solucion_.setFuncionObjetivo() = mejor_funcion_objetivo;
  return solucion_;  
}

void GRASP::faseConstructiva(
  const Problema& kProblema,
  std::pair<Matriz, std::vector<int>>& elementos_problema,
  const int kNumElementosEnSolucion,
  const std::vector<double>& kMedidaCalidad
) {
  int numElementosEnSolucion = 0;
  const Matriz& kDistancias = kProblema.getDistancias();
  Solucion solucion_fase_constructiva;
  do {
    const std::vector<int> kLRC = calcularLRC(elementos_problema, kDistancias, kMedidaCalidad); // Indices de elementos
    const int kIndiceElemento = seleccionarAleatoriamenteElementoDeLRC(kLRC);
    solucion_fase_constructiva.añadirNuevoElementoEIndice(
      elementos_problema.first[kIndiceElemento], kIndiceElemento
    );
    elementos_problema.first.eliminarElemento(kIndiceElemento);
    elementos_problema.second.erase(elementos_problema.second.begin() + kIndiceElemento);    
  } while (++numElementosEnSolucion < kNumElementosEnSolucion);
  solucion_ = solucion_fase_constructiva;
  calcularFuncionObjetivo(kDistancias);
}

std::vector<int> GRASP::calcularLRC(
  const std::pair<Matriz, std::vector<int>>& kElementosProblema,
  const Matriz& kDistancias,
  const std::vector<double>& kMedidaCalidad
) const {
  std::vector<int> indicesNoSeleccionados(kElementosProblema.second.size());
  std::iota(indicesNoSeleccionados.begin(), indicesNoSeleccionados.end(), 0);
  std::sort(indicesNoSeleccionados.begin(), indicesNoSeleccionados.end(), [&](int a, int b) { 
    return kMedidaCalidad[a] > kMedidaCalidad[b]; 
  });
  const double kAlpha = 0.5;
  const int kLRCSize = kAlpha * indicesNoSeleccionados.size();
  std::vector<int> LRC(indicesNoSeleccionados.begin(), indicesNoSeleccionados.begin() + kLRCSize);
  return LRC;
}

std::vector<double> GRASP::calcularMedidaCalidad(
  const std::pair<Matriz, std::vector<int>>& kElementosProblema,
  const Matriz& kDistancias
) const {
  const int kNumIndices = kElementosProblema.second.size();
  const int kNumPuntosTotales = kDistancias.size();
  std::vector<double> diversidadPuntosRestantes(kNumIndices);
  for (int i = 0; i < kNumIndices; ++i) {
    double suma_distancias = 0.0;
    for (int j = 0; j < kNumPuntosTotales; ++j) {
      if (kElementosProblema.second[i] == j) continue;
      suma_distancias += kDistancias[kElementosProblema.second[i]][j];
    }
    diversidadPuntosRestantes[i] = (suma_distancias / (kNumPuntosTotales - 1));
  }
  return diversidadPuntosRestantes;
}

const int GRASP::seleccionarAleatoriamenteElementoDeLRC(const std::vector<int>& kLRC) const {
  std::random_device dispositivo_aleatorio;
  std::mt19937 generador(dispositivo_aleatorio());  
  std::uniform_int_distribution<> dis(0, kLRC.size() - 1);
  return kLRC[dis(generador)];
}