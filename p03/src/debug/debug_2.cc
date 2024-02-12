#include "debug_2.h"

void Debug2::InfoDuranteEjecucion(const Instruccion& kInstruccion, const MemoriaDatos& kMemoriaDatos,
                                  const CintaIn& kCintaIn, const CintaOut& kCintaOut) const {
  std::cout << "Instrucción ejecutada: " << kInstruccion << std::endl << std::endl;
  std::cout << "Memoria de datos:\n" << kMemoriaDatos << std::endl << std::endl;
  std::cout << "Cinta de entrada: " << kCintaIn << std::endl;
  std::cout << "Posición actual de la cinta de entrada: " << kCintaIn.get_puntero() << std::endl << std::endl;
  std::cout << "Cinta de salida: " << kCintaOut << std::endl;
  std::cout << "Posición actual de la cinta de salida: " << kCintaOut.get_puntero() << std::endl << std::endl;
}