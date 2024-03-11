/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 6 de Marzo de 2024
 * @file modoDepurador.h
 * @brief Definición de la clase ModoDepurador, que hereda
 * de la clase base Debug, y permite elegir el algoritmo y tamaño de instancia
 * y se muestra por pantalla tanto la instancia como la solución obtenida.
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p05/src}
 * @see {@link https://docs.google.com/document/d/1pwPk5iI5dRHo8M-raauPP5mgCUHy9m9j_au3UDkn_Rc/edit}
 */

#pragma once

#include "debug.h"

/**
 * @brief Clase ModoDepurador
 */
class ModoDepurador: public Debug {
 public:
  virtual void ejecutar(TablaAlgoritmos&) const override;
};