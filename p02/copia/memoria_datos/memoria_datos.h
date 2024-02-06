#pragma once

#include <iostream>
#include <vector>

#include "../estrategia_almacenamiento/estrategia_almacenamiento.h"

class MemoriaDatos {
 public:
  MemoriaDatos(const int, EstrategiaAlmacenamiento*);
  void almacenarDato(const int kDato, const int kIndiceFila, const int kIndiceColumna = 0) {
    estrategia_->almacenarDato(registros_, kDato, kIndiceFila, kIndiceColumna);
  }
  const int obtenerDato(const int kIndiceFila, const int kIndiceColumna = 0) const {
    return estrategia_->obtenerDato(registros_, kIndiceFila, kIndiceColumna);
  }
  friend std::ostream& operator<<(std::ostream&, const MemoriaDatos&);
 private:
  std::vector<std::vector<int>> registros_;
  EstrategiaAlmacenamiento* estrategia_;
};