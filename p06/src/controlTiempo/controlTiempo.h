#pragma once

#include <string>
#include <chrono>
#include <iostream>

class ControlTiempo {
 public:
  static const bool tiempoTranscurrido(
    const std::chrono::steady_clock::time_point&,
    const std::chrono::steady_clock::time_point&
  );
  static void inicializarContador(const std::string&);
 private:
  static int tiempo_limite;
};