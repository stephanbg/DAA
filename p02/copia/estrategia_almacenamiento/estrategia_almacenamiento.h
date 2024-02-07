#pragma once

#include <vector>

// Interfaz para la estrategia de almacenamiento
class EstrategiaAlmacenamiento {
 public:
  virtual void almacenarDato(std::vector<std::vector<long double>>&, const long double, const int, const int) const = 0;
  virtual const long double obtenerDato(const std::vector<std::vector<long double>>&, const int, const int) const = 0;
  virtual ~EstrategiaAlmacenamiento() {}
};