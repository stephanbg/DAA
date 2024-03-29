/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Marzo de 2024
 * @file funciones.h
 * @brief Definición de funciones necesarias para todo el programa
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p06/src}
 * @see {@link https://docs.google.com/document/d/1a691HPtHQL4qBtI2qaTMTp23wxZvU8-CCIbGOyNJRQo/edit}
 */

#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

const bool contieneFalso(const std::vector<bool>&);
const bool esNumeroEnteroSinSigno(const std::string&);
const bool esNumeroSinSigno(const std::string&);
const std::string sustituirComasPorPunto(const std::string&);
const std::string formatearNumero(const long double);