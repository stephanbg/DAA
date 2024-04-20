#include "solucion.h"

void Solucion::insertarNuevoPuntoEIndice(
  const int kIndice,
  const std::vector<double>& kFilaElementoFueraDeSolucion,
  const int kNuevoIndice
) {
  coordenadas_[kIndice] = kFilaElementoFueraDeSolucion;
  indices_elementos_introducidos_[kIndice] = kNuevoIndice;
}

void Solucion::añadirNuevoElementoEIndice(
  const std::vector<double> kElemento, const int kIndiceElemento
) { 
  coordenadas_.setMatriz().push_back(kElemento);
  indices_elementos_introducidos_.push_back(kIndiceElemento); 
}

std::ostream& operator<<(std::ostream& salida, const Solucion& kSolucion) {
  salida << "Matriz coordenadas de cada elemento (Solución)" << std::endl;
  salida << "-----------------------------------" << std::endl;
  salida << kSolucion.getCoordenadas();
  salida << std::endl;
  return salida;
}