#include "algoritmosDiversidadMaxima.h"

const std::vector<double> AlgoritmosDiversidadMaxima::centroGravedad(const Matriz& kCoordenadas) const {
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

const double AlgoritmosDiversidadMaxima::maximizarFuncionObjetivo(
  const Solucion& kSolucion,
  const Matriz& kDistancias,
  const int kIndiceElementoMasLejano
) const {
  Solucion solucion_tras_insertar_elemento_mas_lejano = kSolucion;
  solucion_tras_insertar_elemento_mas_lejano.setIndicesElementosIntroducidos(kIndiceElementoMasLejano);
  kSolucion.getIndicesElementosIntroducidos();
  exit(1);
}

const std::vector<double> AlgoritmosDiversidadMaxima::obtenerElementoMasAlejadoDeCentroGravedad(
  const std::vector<double>& kCentroGravedad,
  const Matriz& kCoordenadasElementosRestantes
) const {
  std::vector<double> elemento_mas_lejano = kCoordenadasElementosRestantes[0];
  const int kNumDimensiones = elemento_mas_lejano.size();
  const int kSizeElementosRestantes = kCoordenadasElementosRestantes.getMatriz().size();
  double mayor_distancia_euclidiana = 0.0, cada_distancia_euclidiana = 0.0;
  // Compruebo cuál es el más lejano
  for (int fila = 0; fila < kSizeElementosRestantes; ++fila) {
    for (int indice_dimension = 0; indice_dimension < kNumDimensiones; ++indice_dimension) {
      cada_distancia_euclidiana += (
        (kCoordenadasElementosRestantes[fila][indice_dimension] - kCentroGravedad[indice_dimension]) *
        (kCoordenadasElementosRestantes[fila][indice_dimension] - kCentroGravedad[indice_dimension])
      );
    }
    cada_distancia_euclidiana = sqrt(cada_distancia_euclidiana);
    if (fila == 0 || cada_distancia_euclidiana > mayor_distancia_euclidiana) {
      mayor_distancia_euclidiana = cada_distancia_euclidiana;
      elemento_mas_lejano = kCoordenadasElementosRestantes[fila];
    }
  }
  return elemento_mas_lejano;
}