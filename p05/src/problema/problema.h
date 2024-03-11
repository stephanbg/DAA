/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 6 de marzo de 2024
 * @file problema.h
 * @brief Definición de la clase Problema, que representa cualquier problema de DyV
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p05/src}
 * @see {@link https://docs.google.com/document/d/1pwPk5iI5dRHo8M-raauPP5mgCUHy9m9j_au3UDkn_Rc/edit}
 */

#pragma once

#include <iostream>

#include "../funcionesNecesarias/funcionesNecesarias.h"

/**
 * @brief La clase Problema representa cualquier problema de DyV.
 * @tparam TipoProblema Tipo del problema generado por el algoritmo.
 */
template<typename TipoProblema>
class Problema {
 public:
  /**
   * @brief Devuelve la elección del tamaño de la instancia del problema.
   * @return Tamaño de la instancia elegido por el usuario.
   */
  static const int eleccionSizeInstancia() {
    std::cout << "Cuantos número de elementos quieres para el problema?: ";
    std::string resultado = "";
    while (std::cin >> resultado && (!contieneSoloDigitos(resultado) || resultado == "0")) {
      std::cout << "Tiene que ser un número natural estrictamente positivo: ";
    }
    return stoi(resultado);
  } 
  virtual const TipoProblema& getProblema() const = 0;
  virtual TipoProblema& setProblema() = 0;
  virtual void mostrarProblema() const = 0;
  virtual ~Problema() {};
};