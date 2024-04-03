#include "movimientoReInsercionInterGRASP.h"

const std::vector<Solucion> MovimientoReInsercionInterGRASP::busquedaLocal(const Nodo* kNodoRaiz) {
  std::vector<Solucion> solucion_vecina, solucion_mejor;
  const int kNumMaquinas = solucion_inicial_.size(); 
  int funcion_objetivo_inicial = Solucion::getFuncionObjetivo(),
  funcion_objetivo_aux = funcion_objetivo_inicial, funcion_objetivo_vecino = 0;
  for (int i = 0; i < kNumMaquinas; ++i) {
    const int kTctMaquinaI = solucion_inicial_[i].getTCT();
    const int kNumTareas = solucion_inicial_[i].getTareas().size();
    for (int j = 0; j < kNumTareas; ++j) {
      solucion_vecina = solucion_inicial_;
      const Nodo* kTarea = solucion_vecina[i].getTareas()[j];
      for (int k = j + 1; k < kNumTareas; ++k) {
        solucion_vecina[i].moverTareaAPosicionDada(kTarea, k);
        // Calcular TCT vecino (PARCIAL) TENGO QUE HACERLO
        const int kTctVecinoI = solucion_vecina[i].calcularTCT(kNodoRaiz);
        funcion_objetivo_vecino = funcion_objetivo_inicial - kTctMaquinaI + kTctVecinoI;
        if (funcion_objetivo_vecino < funcion_objetivo_aux) {
          solucion_mejor = solucion_vecina;
          solucion_mejor[i].setTCT() = kTctVecinoI;
          funcion_objetivo_aux = funcion_objetivo_vecino;
        }
      }
    }
  }
  return solucion_mejor;
}