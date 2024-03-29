/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 20 de Marzo de 2024
 * @file controlador_tiempo.h
 * @brief Definición e implementación de la clase ControladorTiempo
 * que recibe una función con sus parámetros y se encarga de comprobar
 * el tiempo de ejecución que dura la función
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07_parcial_1/src}
 */

#include <chrono>
#include <functional>
#include <iostream>

/**
 * @brief Controlador de tiempo para medir el rendimiento de una función.
 * 
 * @tparam Tipo de retorno de la función a medir.
 * @tparam Tipos de los argumentos de la función a medir.
 */
template<typename TipoRetorno, typename... Args>
class ControladorTiempo {
 public:
  /**
   * @brief Constructor del ControladorTiempo.
   * 
   * @param funcion Función a medir.
   */
  ControladorTiempo(std::function<TipoRetorno(Args...)> funcion): funcion_(funcion) {}
  /**
   * @brief Mide el tiempo de ejecución de la función y devuelve su resultado.
   * 
   * @param args Argumentos de la función.
   * @return Resultado de la función.
   */  
  TipoRetorno medirTiempoFuncion(Args&&... args) {
    start();
    TipoRetorno resultado = funcion_(std::forward<Args>(args)...);
    stop();
    return resultado;
  }
  /**
   * @brief Obtiene la duración de la medición en microsegundos.
   * 
   * @return Duración de la medición en microsegundos.
   */
  const int getDuracion() const {
    return std::chrono::duration_cast<std::chrono::microseconds>(fin_ - inicio_).count();
  }
 private:
  std::function<TipoRetorno(Args...)> funcion_;
  std::chrono::time_point<std::chrono::high_resolution_clock> inicio_;
  std::chrono::time_point<std::chrono::high_resolution_clock> fin_;
  /**
   * @brief Inicia la medición del tiempo.
   */
  void start() {
    inicio_ = std::chrono::high_resolution_clock::now();
  }
  /**
   * @brief Detiene la medición del tiempo.
   */
  void stop() {
    fin_ = std::chrono::high_resolution_clock::now();
  }
};