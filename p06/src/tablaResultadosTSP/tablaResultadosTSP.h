/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Marzo de 2024
 * @file tablaResultados.h
 * @brief Definición de la clase TablaResultadosTSP
 * que almacena datos de los algoritmos utilizados para resolver el problema TSP
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p06/src}
 * @see {@link https://docs.google.com/document/d/1a691HPtHQL4qBtI2qaTMTp23wxZvU8-CCIbGOyNJRQo/edit}
 */

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "../nodo/nodo.h"

/**
 * @brief Clase para almacenar y mostrar los resultados del Problema del Viajante de Comercio (TSP).
 * 
 * Esta clase proporciona métodos para insertar datos de resultados, como nombres de archivos, nombres de algoritmos,
 * costes y tiempos de ejecución, así como caminos mínimos. También puede mostrar la tabla de resultados en pantalla
 * o guardarla en un archivo.
 */
class TablaResultadosTSP {
 public:
  static void insertarDatoNombreFichero(const std::string&);
  static void insertarDatoNombreAlgoritmo(const std::string&);
  static void insertarFilaMatrizDatos(const std::vector<std::pair<const long double, const long double>>&);
  static void insertarFilaMatrizCaminosMinimos(const std::vector<const Nodo*>&);
  static void mostrarTablaEnPantalla();
  static void mostrarTablaEnFichero();
 private:
  static std::vector<std::string> nombres_ficheros_;
  static std::vector<std::string> nombres_algoritmos_;
  static std::vector<std::vector<std::pair<const long double, const long double>>> matriz_datos_;
  static std::vector<std::vector<const Nodo*>> caminos_minimos;
};