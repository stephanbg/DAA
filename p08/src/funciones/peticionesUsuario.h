/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 19 de Abril de 2024
 * @file peticionesUsuario.h
 * @brief Definición de funciones que hacen solicitudes al usuario
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p08/src}
 */

#pragma once

#include <fstream>
#include <sstream>

#include "funciones.h"

const int cuantosFicherosAEjecutar(const std::string&);
const int cuantosElementosParaSolucion(const std::string&);
const std::string peticionUsuarioTablaPantallaOFichero();
