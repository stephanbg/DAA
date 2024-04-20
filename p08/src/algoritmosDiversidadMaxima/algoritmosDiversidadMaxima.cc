#include "algoritmosDiversidadMaxima.h"

const std::vector<double> AlgoritmosDiversidadMaxima::calcularCentroGravedad(
  const Matriz& kCoordenadas
) const {
  const int kNumElementos = kCoordenadas.getMatriz().size();
  const int kNumDimensiones = kCoordenadas.getMatriz()[0].size();
  std::vector<double> coordenadas_centro_gravedad(kNumDimensiones);
  double sumatorio_coordenadas;
  for (int columna = 0; columna < kNumDimensiones; ++columna) {
    sumatorio_coordenadas = 0.0;
    for (int fila = 0; fila < kNumElementos; ++fila) {
      sumatorio_coordenadas += kCoordenadas[fila][columna];
    }
    coordenadas_centro_gravedad[columna] = (sumatorio_coordenadas / kNumElementos);
  }
  return coordenadas_centro_gravedad;
}

const std::pair<std::vector<double>, int>
AlgoritmosDiversidadMaxima::obtenerElementoEIndiceRealMasAlejadoDeCentroGravedad(
  const std::vector<double>& kCentroGravedad,
  const Matriz& kElementosRestantes
) const {
  std::pair<std::vector<double>, int> elemento_mas_lejano;
  const int kNumDimensiones = kElementosRestantes[0].size();
  const int kSizeElementosRestantes = kElementosRestantes.size();
  double mayor_distancia_euclidiana = 0.0, cada_distancia_euclidiana = 0.0;
  // Compruebo cuál es el más lejano
  for (int fila = 0; fila < kSizeElementosRestantes; ++fila) {
    for (int indice_dimension = 0; indice_dimension < kNumDimensiones; ++indice_dimension) {
      cada_distancia_euclidiana += (
        (kElementosRestantes[fila][indice_dimension] - kCentroGravedad[indice_dimension]) *
        (kElementosRestantes[fila][indice_dimension] - kCentroGravedad[indice_dimension])
      );
    }
    cada_distancia_euclidiana = sqrt(cada_distancia_euclidiana);
    if (fila == 0 || cada_distancia_euclidiana > mayor_distancia_euclidiana) {
      mayor_distancia_euclidiana = cada_distancia_euclidiana;
      elemento_mas_lejano.first = kElementosRestantes[fila];
      elemento_mas_lejano.second = fila;
    }
  }
  return elemento_mas_lejano;
}

const double AlgoritmosDiversidadMaxima::calcularFuncionObjetivo(const Matriz& kDistancias) {
  double& funcion_objetivo = solucion_.setFuncionObjetivo();
  funcion_objetivo = 0;
  const std::vector<int>& kIndices = solucion_.getIndicesElementosIntroducidos();
  const int kSizeIndices = kIndices.size();
  for (int i = 0; i < kSizeIndices; ++i) {
    for (int j = i + 1; j < kSizeIndices; ++j) {
      funcion_objetivo += kDistancias[kIndices[i]][kIndices[j]];
    }
  }
  return funcion_objetivo;
}

const double AlgoritmosDiversidadMaxima::calcularFuncionObjetivoParcial(
  const Solucion& kSolucionInicial,
  const int kIndiceElementoIntroducido,
  const Matriz& kDistancias
) {
  // Restar antes y Sumar Despues
  const int kSizeSolucion = solucion_.size();
  double& funcion_objetivo = solucion_.setFuncionObjetivo(); 
  const std::vector<int>& kIndicesAntes = kSolucionInicial.getIndicesElementosIntroducidos();
  const std::vector<int>& kIndicesDespues = solucion_.getIndicesElementosIntroducidos();
  for (int i = 0; i < kSizeSolucion; ++i) {
    if (i == kIndiceElementoIntroducido) continue;
    funcion_objetivo -= kDistancias[kIndicesAntes[kIndiceElementoIntroducido]][kIndicesAntes[i]];
    funcion_objetivo += kDistancias[kIndicesDespues[kIndiceElementoIntroducido]][kIndicesDespues[i]];
  }
  return funcion_objetivo;
}