#pragma once

#include "estrategia_almacenamiento.h"

// Estrategia actual: Cada registro almacena un único espacio para datos
class EstrategiaUnicoEspacio : public EstrategiaAlmacenamiento {
 public:
  void almacenarDato(std::vector<std::vector<long double>>& registros, const long double kDato,
                     const int kIndiceFila, const int kIndiceColumna = 0) const override {
    registros[kIndiceFila][0] = kDato;
  }
  const long double obtenerDato(const std::vector<std::vector<long double>>& kRegistros, const int kIndiceFila,
                                const int kIndiceColumna = 0) const override {
    return kRegistros[kIndiceFila][0];
  }
};