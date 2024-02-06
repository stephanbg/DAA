#pragma once

#include "estrategia_almacenamiento.h"

// Estrategia actual: Cada registro almacena un único espacio para datos
class EstrategiaUnicoEspacio : public EstrategiaAlmacenamiento {
 public:
  void almacenarDato(std::vector<std::vector<int>>& registros, const int kDato,
                     const int kIndiceFila, const int kIndiceColumna = 0) const override {
    registros[kIndiceFila][0] = kDato;
  }
  const int obtenerDato(const std::vector<std::vector<int>>& kRegistros, const int kIndiceFila,
                  const int kIndiceColumna = 0) const override {
    return kRegistros[kIndiceFila][0];
  }
};