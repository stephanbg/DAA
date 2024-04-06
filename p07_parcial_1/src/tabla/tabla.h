/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 20 de Marzo de 2024
 * @file tabla.h
 * @brief Definición de la clase Tabla
 * que almacena datos de los algoritmos utilizados para resolver el problema
 * Parallel Machine Scheduling Problem with Dependent Setup Times
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07_parcial_1/src}
 */

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

#include "../solucion/solucion.h"

/**
 * @brief Clase para almacenar y mostrar los resultados de las diferentes ejecuciones.
 * 
 * Esta clase proporciona métodos para insertar datos de resultados, como nombre de archivo,
 * nombres de algoritmos, número de nodos y máquinas, funciones objetivo y los tiempos de ejecución.
 * También puede mostrar la tabla de resultados en pantalla
 * o guardarla en un archivo.
 */
class Tabla {
 public:
  static void insertarDatosIniciales(const std::string&, const int, const int);
  static void insertarDatos(const std::string&, const int);
  static void mostrarTablaEnPantalla();
  static void mostrarTablaEnFichero();
 private:
  static std::string nombre_fichero_;
  static std::vector<std::string> nombres_algoritmos_;
  static int numero_nodos_;
  static int numero_maquinas_;
  static std::vector<int> tiempos_;
  static std::vector<int> funcion_objetivo_;
  static void insertarNumeroNodos(const int);
  static void insertarNumeroMaquinas(const int);  
  static void insertarNombreFichero(const std::string&);
  static void insertarNombreAlgoritmo(const std::string&);
  static void insertarTiempo(const int);
  static void insertarFuncionObjetivo(const int);  
};