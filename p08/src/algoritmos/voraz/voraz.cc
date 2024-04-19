#include "voraz.h"

Solucion Voraz::ejecutar(const Problema& kProblema, const int kNumElementosEnSolucion) {
  faseConstructiva(kProblema, kNumElementosEnSolucion);
  busquedaLocal(kProblema.getDistancias());
  return solucion_;
}

void Voraz::faseConstructiva(const Problema& kProblema, const int kNumElementosEnSolucion) {
  // Variables
  Matriz& solucion_coordenadas = solucion_.setCoordenadas();
  Matriz elementos_problema = kProblema.getCoordenadas();
  // Algoritmo
  std::vector<double> cada_centro_gravedad = calcularCentroGravedad(elementos_problema);
  do {
    const std::vector<double> kCadaElementoMasLejano = (
      obtenerElementoMasAlejadoDeCentroGravedad(cada_centro_gravedad, elementos_problema)
    );
    const int kIndiceElementoMasLejano = kProblema.getIndiceElemento(kCadaElementoMasLejano);
    solucion_.añadirElemento(kCadaElementoMasLejano);
    solucion_.añadirIndiceElemento(kIndiceElementoMasLejano);
    elementos_problema.eliminarElemento(kCadaElementoMasLejano);
    cada_centro_gravedad = calcularCentroGravedad(solucion_coordenadas);
  } while (solucion_coordenadas.size() != kNumElementosEnSolucion);
  calcularFuncionObjetivo(solucion_, kProblema.getDistancias());
}

void Voraz::busquedaLocal(const Matriz& kDistancias) {
  Matriz distancias;
  Solucion solucion_vecina;
  const int kNumPuntosEnElEspacio = solucion_.getCoordenadas().getMatriz().size();
  double mejor_funcion_objetivo = solucion_.getFuncionObjetivo(), funcion_objetivo_vecino;
  for (int i = 0; i < kNumPuntosEnElEspacio; ++i) {
    for (int j = i + 1; j < kNumPuntosEnElEspacio; ++j) {
      solucion_vecina = solucion_;
      distancias = kDistancias;
      solucion_vecina.swapPuntosDelEspacio(i, j);
      distancias.swapFilas(i, j);
      funcion_objetivo_vecino = calcularFuncionObjetivo(solucion_vecina, distancias);
      /*std::cout << "\nfuncion_objetivo_vecino: " << funcion_objetivo_vecino << std::endl;
      std::cout << "mejor_funcion_objetivo: " << mejor_funcion_objetivo << std::endl;
      std::cout << i << ", " << j << std::endl << "\n";*/
      if (mejor_funcion_objetivo < funcion_objetivo_vecino) {
        solucion_ = solucion_vecina;
        mejor_funcion_objetivo = funcion_objetivo_vecino;
      }
    }
  }
  solucion_.setFuncionObjetivo() = mejor_funcion_objetivo;
}