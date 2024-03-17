#include "controlTiempo.h"

int ControlTiempo::tiempo_limite = 0;

void ControlTiempo::inicializarContador(const std::string& kTiempoEnMinutos) {
  tiempo_limite = std::stoi(kTiempoEnMinutos) * 60;
}

const bool ControlTiempo::tiempoTranscurrido(
    const std::chrono::steady_clock::time_point& kIni,
    const std::chrono::steady_clock::time_point& kActual) {
  auto diff = std::chrono::duration_cast<std::chrono::seconds>(kActual - kIni).count();
  return (diff > tiempo_limite);
}