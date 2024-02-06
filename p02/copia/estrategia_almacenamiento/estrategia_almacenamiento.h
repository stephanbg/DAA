#pragma once

#include <vector>

// Interfaz para la estrategia de almacenamiento
class EstrategiaAlmacenamiento {
 public:
  virtual void almacenarDato(std::vector<std::vector<int>>&, const int, const int, const int) const = 0;
  virtual const int obtenerDato(const std::vector<std::vector<int>>&, const int, const int) const = 0;
  virtual ~EstrategiaAlmacenamiento() {}
};