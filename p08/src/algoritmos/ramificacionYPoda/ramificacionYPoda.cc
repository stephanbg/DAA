#include "ramificacionYPoda.h"

Solucion RamificacionYPoda::ejecutar(const Problema& kProblema, const int kNumElementosEnSolucion, const int kIteraciones) {  
  const Matriz& kDistancias = kProblema.getDistancias();
  const std::pair<Matriz, std::vector<int>>& kElementosProblema = std::make_pair(
    kProblema.getCoordenadas(), kProblema.getIndicesProblema()
  );
  Solucion mejor_solucion;
  double mejor_funcion_objetivo = 0.0;
  ramificacionYPoda(kDistancias, kElementosProblema, kNumElementosEnSolucion, mejor_solucion, mejor_funcion_objetivo, 0);
  solucion_ = mejor_solucion;
  solucion_.setFuncionObjetivo() = mejor_funcion_objetivo;
  return solucion_;
}

void RamificacionYPoda::ramificacionYPoda(
  const Matriz& kDistancias, const std::pair<Matriz, std::vector<int>>& kElementosProblema,
  const int kNumElementosEnSolucion, Solucion& mejor_solucion, double& mejor_funcion_objetivo,
  const int kIndice
  ) {
  if (solucion_.size() == kNumElementosEnSolucion) {
    double funcion_objetivo_actual = calcularFuncionObjetivo(kDistancias);
    if (funcion_objetivo_actual > mejor_funcion_objetivo) {
      mejor_funcion_objetivo = funcion_objetivo_actual;
      mejor_solucion = solucion_;
    }
    return;
  }
  if (kIndice >= kElementosProblema.first.size()) return;
  // Ramificación: incluir el punto actual en el conjunto
  solucion_.añadirNuevoElementoEIndice(kElementosProblema.first[kIndice], kElementosProblema.second[kIndice]);
  ramificacionYPoda(
    kDistancias, kElementosProblema, kNumElementosEnSolucion, mejor_solucion, mejor_funcion_objetivo, kIndice + 1
  );
  // Ramificación: no incluir el punto actual en el conjunto
  solucion_.eliminarUltimoElementoEIndice();
  ramificacionYPoda(
    kDistancias, kElementosProblema, kNumElementosEnSolucion, mejor_solucion, mejor_funcion_objetivo, kIndice + 1
  );
}