/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Marzo de 2024
 * @file controlTiempo.h
 * @brief Definición de la clase ControlTiempo, que se encarga de realizar una cuenta atrás
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p06/src}
 * @see {@link https://docs.google.com/document/d/1a691HPtHQL4qBtI2qaTMTp23wxZvU8-CCIbGOyNJRQo/edit}
 */

#pragma once

#include <string>
#include <chrono>
#include <iostream>

/**
 * @brief Clase para controlar el tiempo transcurrido.
 */
class ControlTiempo {
 public:
  static const bool tiempoTranscurrido(
    const std::chrono::high_resolution_clock::time_point&,
    const std::chrono::high_resolution_clock::time_point&
  );
  static void inicializarContador(const std::string&);
 private:
  static int tiempo_limite;
};