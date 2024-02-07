#pragma once

#include "estrategia_almacenamiento.h"

// Estrategia futura: Cada registro almacena un vector de tamaño dinámico
class EstrategiaVectorDinamico : public EstrategiaAlmacenamiento {
 public:
  void almacenarDato(std::vector<std::vector<long double>>& registros, const long double kDato,
                     const int kIndiceFila, const int kIndiceColumna) const override {
    if (kIndiceColumna >= registros.size()) registros[kIndiceFila].resize(kIndiceColumna, 0);
    registros[kIndiceFila][kIndiceColumna] = kDato;
  }
  const long double obtenerDato(const std::vector<std::vector<long double>>& kRegistros, const int kIndiceFila,
                                const int kIndiceColumna) const override {
    if (kIndiceColumna >= kRegistros.size()) throw ("Rango fuera de Registro.");
    return kRegistros[kIndiceFila][kIndiceColumna];
  }
};