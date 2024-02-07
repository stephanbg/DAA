#pragma once

#include <iostream>
#include <vector>
#include <iomanip>

#include "../estrategia_almacenamiento/estrategia_almacenamiento.h"
#include "../funciones/funciones_necesarias.h"

class MemoriaDatos {
 public:
  MemoriaDatos(const int, EstrategiaAlmacenamiento*);
  void almacenarDato(const long double kDato, const int kIndiceFila, const int kIndiceColumna = 0) {
    estrategia_->almacenarDato(registros_, kDato, kIndiceFila, kIndiceColumna);
  }
  const long double obtenerDato(const int kIndiceFila, const int kIndiceColumna = 0) const {
    return estrategia_->obtenerDato(registros_, kIndiceFila, kIndiceColumna);
  }
  const std::vector<std::vector<long double>>& get_registros() const { return registros_; }
  friend std::ostream& operator<<(std::ostream&, const MemoriaDatos&);
 private:
  std::vector<std::vector<long double>> registros_;
  EstrategiaAlmacenamiento* estrategia_;
};