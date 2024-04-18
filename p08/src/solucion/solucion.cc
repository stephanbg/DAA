#include "solucion.h"

std::ostream& operator<<(std::ostream& salida, const Solucion& kSolucion) {
  salida << "Matriz coordenadas de cada elemento (Solución)" << std::endl;
  salida << "-----------------------------------" << std::endl;
  salida << kSolucion.getCoordenadas();
  salida << std::endl;
  return salida;
}