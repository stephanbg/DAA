/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 19 de Abril de 2024
 * @file funciones.h
 * @brief Definición de funciones necesarias
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p08/src}
 */

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <cmath>
#include <limits>
#include <filesystem>

#include "peticionesUsuario.h"

namespace fs = std::filesystem;

std::vector<std::string> extraerFicherosEjemplo(const std::string&);
std::string extraerNombreFicheroDeRuta(const std::string&);
const int cantidadMaximaFicheros(const std::string&);
const std::string reemplazarComaDecimalPorPunto(const std::string&);
const int contarDecimales(const double, const int);
bool tieneCaracteresNumericosYUnPuntoDecimal(const std::string&);