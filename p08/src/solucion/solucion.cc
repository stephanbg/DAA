#include "solucion.h"

void Solucion::swapPuntosDelEspacio(const int kPosAnterior, const int kPosSiguiente) {
  const int kCantidadDePuntos = coordenadas_.size();
  if (kPosAnterior < 0 || kPosAnterior >= kCantidadDePuntos) {
    throw std::out_of_range("No existe el punto origen en la solución");
  }
  if (kPosSiguiente < 0 || kPosSiguiente >= kCantidadDePuntos) {
    throw std::out_of_range("No existe el punto destino en la solución");
  }
  std::swap(coordenadas_[kPosAnterior], coordenadas_[kPosSiguiente]);
  std::swap(indices_elementos_introducidos_[kPosAnterior], indices_elementos_introducidos_[kPosSiguiente]);
}

std::ostream& operator<<(std::ostream& salida, const Solucion& kSolucion) {
  salida << "Matriz coordenadas de cada elemento (Solución)" << std::endl;
  salida << "-----------------------------------" << std::endl;
  salida << kSolucion.getCoordenadas();
  salida << std::endl;
  return salida;
}