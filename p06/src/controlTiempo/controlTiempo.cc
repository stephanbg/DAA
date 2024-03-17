/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Marzo de 2024
 * @file controlTiempo.cc
 * @brief Implementación de la clase ControlTiempo, que se encarga de realizar una cuenta atrás
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p06/src}
 * @see {@link https://docs.google.com/document/d/1a691HPtHQL4qBtI2qaTMTp23wxZvU8-CCIbGOyNJRQo/edit}
 */

#include "controlTiempo.h"

int ControlTiempo::tiempo_limite = 0;

/**
 * @brief Inicializa el contador de tiempo límite.
 * 
 * @param kTiempoEnMinutos Tiempo límite en minutos.
 */
void ControlTiempo::inicializarContador(const std::string& kTiempoEnMinutos) {
  tiempo_limite = std::stoi(kTiempoEnMinutos) * 60;
}

/**
 * @brief Comprueba si ha transcurrido el tiempo límite.
 * 
 * @param kIni Punto de inicio del contador.
 * @param kActual Punto de fin del contador.
 * @return true si ha transcurrido el tiempo límite, false en caso contrario.
 */
const bool ControlTiempo::tiempoTranscurrido(
    const std::chrono::high_resolution_clock::time_point& kIni,
    const std::chrono::high_resolution_clock::time_point& kActual) {
  auto diff = std::chrono::duration_cast<std::chrono::seconds>(kActual - kIni).count();
  return (diff > tiempo_limite);
}