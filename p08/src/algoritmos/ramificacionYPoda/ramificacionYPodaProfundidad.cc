#include "ramificacionYPodaProfundidad.h"

Solucion RamificacionYPodaProfundidad::ejecutar(
  const Problema& kProblema, const int kNumElementosEnSolucion, const int kIteraciones
) {  
  const Matriz& kDistancias = kProblema.getDistancias();
  const std::pair<Matriz, std::vector<int>>& kElementosProblema = std::make_pair(
    kProblema.getCoordenadas(), kProblema.getIndicesProblema()
  );
  GRASP algortimo;
  Solucion mejor_solucion = algortimo.ejecutar(kProblema, kNumElementosEnSolucion, kIteraciones);
  double cota_inferior = mejor_solucion.getFuncionObjetivo();
  std::vector<std::tuple<double, double, int>> distancias_min_max = calcularDistanciasMinMax(kDistancias, kNumElementosEnSolucion);
  std::sort(distancias_min_max.begin(), distancias_min_max.end(),
            [](const auto& a, const auto& b) {
              return std::get<1>(a) > std::get<1>(b);
            });
  ramificacionYPoda(
    kDistancias, kElementosProblema, kNumElementosEnSolucion, mejor_solucion, cota_inferior, 0, distancias_min_max
  );
  solucion_ = mejor_solucion;
  return solucion_;
}

void RamificacionYPodaProfundidad::ramificacionYPoda(
  const Matriz& kDistancias, const std::pair<Matriz, std::vector<int>>& kElementosProblema,
  const int kNumElementosEnSolucion, Solucion& mejor_solucion, double& cota_inferior,
  const int kIndice, const std::vector<std::tuple<double, double, int>>& kDistanciasMinMax
  ) {
  if (solucion_.size() == kNumElementosEnSolucion) {
    double cota = calcularFuncionObjetivo(kDistancias);
    if (cota > cota_inferior) {
      cota_inferior = cota;
      mejor_solucion = solucion_;
    }
    return;
  }
  if (kIndice >= kElementosProblema.first.size()) return;
  if (nodoAPodar(
      solucion_, kNumElementosEnSolucion - solucion_.size(), cota_inferior,
      calcularFuncionObjetivo(kDistancias), kDistanciasMinMax
    )
  ) return;
  // Ramificación: incluir el punto actual en el conjunto
  solucion_.añadirNuevoElementoEIndice(kElementosProblema.first[kIndice], kElementosProblema.second[kIndice]);
  ramificacionYPoda(
    kDistancias, kElementosProblema, kNumElementosEnSolucion,
    mejor_solucion, cota_inferior, kIndice + 1, kDistanciasMinMax
  );
  // Ramificación: no incluir el punto actual en el conjunto
  solucion_.eliminarUltimoElementoEIndice();
  ramificacionYPoda(
    kDistancias, kElementosProblema, kNumElementosEnSolucion,
    mejor_solucion, cota_inferior, kIndice + 1, kDistanciasMinMax
  );
}

bool RamificacionYPodaProfundidad::nodoAPodar(
  const Solucion& kSolucionAExpandir,
  const int kNumRestoDeNodosFuturos,
  const double kCotaInferior,
  const double kFuncionObjetivo,
  const std::vector<std::tuple<double, double, int>>& kDistanciasMinMax
) {
  const int kNumElementosEnSolucionActual = kSolucionAExpandir.size();
  const int kNumNodosTotales = kDistanciasMinMax.size();
  double sum = kFuncionObjetivo;
  int contador = 0;
  for (int i = 0; i < kNumNodosTotales; ++i) {
    bool nodo_existe_en_solucion = false;
    for (int j = 0; j < kNumElementosEnSolucionActual; ++j) {
      if (kSolucionAExpandir.getIndicesElementosIntroducidos()[j] == std::get<2>(kDistanciasMinMax[i])) {
        nodo_existe_en_solucion = true;
        break;
      }
    }
    if (!nodo_existe_en_solucion) {
      sum += std::get<1>(kDistanciasMinMax[i]);
      if (++contador == kNumRestoDeNodosFuturos) break;
    }
  }
  //std::cout << "SUM: " << sum << " | Cota: " << kCotaInferior << std::endl;
  return (sum < kCotaInferior) ? true : false;
}

std::vector<std::tuple<double, double, int>> RamificacionYPodaProfundidad::calcularDistanciasMinMax(
  const Matriz& kDistancias,
  const int kNumElementosEnSolucion
) const {
  const int kFilas = kDistancias.size();
  std::vector<std::tuple<double, double, int>> min_max_distancias(kFilas);
  double sum_distancias_min, sum_distancias_max;
  for (int f = 0; f < kFilas; ++f) {
    std::vector<double> fila_ordenada_menor_mayor = kDistancias[f];
    std::sort(fila_ordenada_menor_mayor.begin(), fila_ordenada_menor_mayor.end());
    sum_distancias_min = 0.0;
    sum_distancias_max = 0.0;
    for (int c = 0, aux_c = 0; c < kNumElementosEnSolucion; ++c) {
      if (c >= f) aux_c = c + 1;
      else aux_c = c;
      sum_distancias_min += fila_ordenada_menor_mayor[aux_c];
      sum_distancias_max += fila_ordenada_menor_mayor[fila_ordenada_menor_mayor.size() - aux_c];
    }
    min_max_distancias[f] = std::make_tuple(sum_distancias_min, sum_distancias_max, f);
  }
  return min_max_distancias;
}