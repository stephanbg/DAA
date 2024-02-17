/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file funciones_necesarias.h
 * @brief Definición de funciones necesarias para todo el programa
 * 
 * @see {@link https://docs.google.com/document/d/1zf_w2HtS4zJX3iqr9yPm6f7rRNsrBxL7afCsMapujMQ/edit#heading=h.5bq8rsdy1ujx}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p03}
 */

#pragma once

#include <regex>
#include <algorithm>

int ContarDecimales(const long double);
bool EsNumero(const std::string&);
const std::string ConvertirAMayusculas(const std::string&);
const std::string QuitarEspacios(const std::string&);
void EliminarCoincidencias(const std::vector<std::string>&, std::string&);
bool sonTodoDigitos(const std::string&);
bool esOperandoVectorial(const std::string&);