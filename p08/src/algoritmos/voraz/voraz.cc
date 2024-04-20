#include "voraz.h"

Solucion Voraz::ejecutar(const Problema& kProblema, const int kNumElementosEnSolucion) {
  std::pair<Matriz, std::vector<int>> elementos_problema(
    kProblema.getCoordenadas(), kProblema.getIndicesProblema()
  );
  faseConstructiva(kProblema, elementos_problema, kNumElementosEnSolucion);
  busquedaLocal(kProblema, elementos_problema);
  return solucion_;
}

void Voraz::faseConstructiva(
  const Problema& kProblema,
  std::pair<Matriz, std::vector<int>>& elementos_problema,
  const int kNumElementosEnSolucion
) {
  // Variables
  Matriz& solucion_coordenadas = solucion_.setCoordenadas();
  // Algoritmo
  std::vector<double> centro_gravedad = calcularCentroGravedad(elementos_problema.first);
  do {
    const std::pair<std::vector<double>, int> kElementoMasLejanoEIndiceReal = (
      obtenerElementoEIndiceRealMasAlejadoDeCentroGravedad(centro_gravedad, elementos_problema.first)
    );
    solucion_.añadirNuevoElementoEIndice(
      kElementoMasLejanoEIndiceReal.first, elementos_problema.second[kElementoMasLejanoEIndiceReal.second]
    );
    elementos_problema.first.eliminarElemento(kElementoMasLejanoEIndiceReal.first);
    elementos_problema.second.erase(elementos_problema.second.begin() + kElementoMasLejanoEIndiceReal.second);
    centro_gravedad = calcularCentroGravedad(solucion_coordenadas);
  } while (solucion_coordenadas.size() != kNumElementosEnSolucion);
  calcularFuncionObjetivo(kProblema.getDistancias());
}

void Voraz::busquedaLocal(
  const Problema& kProblema,
  const std::pair<Matriz, std::vector<int>>& kElementosRestantes
) {
  // Variables
  Solucion mejor_solucion = solucion_;
  const Solucion& kSolucionInicial = mejor_solucion;
  const Matriz& kDistancias = kProblema.getDistancias();
  const int kSizeElementosRestantes = kElementosRestantes.first.size();
  const int kSizeElementosSolucion = solucion_.size();
  double mejor_funcion_objetivo = solucion_.getFuncionObjetivo(), funcion_objetivo_actual;
  // Empieza algoritmo
  for (int i = 0; i < kSizeElementosSolucion; ++i) {
    for (int j = 0; j < kSizeElementosRestantes; ++j) {
      solucion_.insertarNuevoPuntoEIndice(i, kElementosRestantes.first[j], kElementosRestantes.second[j]);
      funcion_objetivo_actual = calcularFuncionObjetivoParcial(kSolucionInicial, i, kDistancias);
      if (mejor_funcion_objetivo < funcion_objetivo_actual) {   
        mejor_funcion_objetivo = funcion_objetivo_actual;
        mejor_solucion = solucion_;
      }
      solucion_ = kSolucionInicial;
    }
  }
  solucion_ = mejor_solucion;
  solucion_.setFuncionObjetivo() = mejor_funcion_objetivo;
}