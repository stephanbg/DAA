#include "movimientoReInsercionInterGRASP.h"

const std::vector<Solucion> MovimientoReInsercionInterGRASP::busquedaLocal(
  const std::vector<Solucion>& kSolucionActual,
  const Nodo* kNodoRaiz
) const {
  std::vector<Solucion> solucion_vecina, solucion_mejor;
  const int kNumMaquinas = kSolucionActual.size();
  int funcion_objetivo_inicial = Solucion::getFuncionObjetivo(),
  funcion_objetivo = funcion_objetivo_inicial, funcion_objetivo_vecino = 0;
  for (int i = 0; i < kNumMaquinas; ++i) {
    const int kTctMaquinaI = kSolucionActual[i].getTCT();
    const int kNumTareas = kSolucionActual[i].getTareas().size();
    for (int j = 0; j < kNumTareas; ++j) {
      solucion_vecina = kSolucionActual;
      const Nodo* kTarea = solucion_vecina[i].getTareas()[j];
      for (int k = j + 1; k < kNumTareas; ++k) {
        solucion_vecina[i].moverTareaAPosicionDada(kTarea, k);
        // Calcular TCT vecino (PARCIAL) TENGO QUE HACERLO
        const int kTctVecinoI = solucion_vecina[i].calcularTCT(kNodoRaiz);
        /*std::cout << "kTctMaquinaI: " << kTctMaquinaI << std::endl;
        Solucion::mostrarTareasDeTodasLasMaquinas(kSolucionActual);
        std::cout << "Primer mov TCT TOTAL: " << kTctVecinoI << std::endl;
        Solucion::mostrarTareasDeTodasLasMaquinas(solucion_vecina);
        const int kTctVecinoAux = solucion_vecina[i].calcularTCTParcial(kNodoRaiz, kSolucionActual[i], k);
        std::cout << "Primer mov TCT PARCIAL: " << kTctVecinoAux << std::endl;
        Solucion::mostrarTareasDeTodasLasMaquinas(solucion_vecina);*/
        funcion_objetivo_vecino = funcion_objetivo_inicial - kTctMaquinaI + kTctVecinoI;
        if (funcion_objetivo_vecino < funcion_objetivo) {
          solucion_mejor = solucion_vecina;
          solucion_mejor[i].setTCT() = kTctVecinoI;
          funcion_objetivo = funcion_objetivo_vecino;
        }
      }
    }
  }
  Solucion::setFuncionObjetivo() = funcion_objetivo;
  return solucion_mejor;
}