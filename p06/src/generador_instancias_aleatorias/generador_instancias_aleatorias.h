/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Marzo de 2024
 * @file generador_instancias_aleatorias.h
 * @brief Definición de la clase GeneradorInstanciasAleatorias
 * que generará ficheros aleatorios
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p06/src}
 * @see {@link https://docs.google.com/document/d/1a691HPtHQL4qBtI2qaTMTp23wxZvU8-CCIbGOyNJRQo/edit}
 */

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <random>
#include <filesystem>
#include <cstdlib>
#include <ctime>
#include <iomanip>

#include "../sintaxis_fichero_grafo/sintaxis_fichero_grafo.h"
#include "../funciones/funciones.h"

namespace fs = std::filesystem;

/**
 * @brief Clase que genera instancias aleatorias de ficheros
 * que contienen la descripción de grafos no dirigidos completos
 * con pesos positivos
 */
class GeneradorInstanciasAleatorias {
 public:
  static void generadorRand(const int, const std::string&);
  static const std::set<std::string> getFicherosRand() { return ficheros_aletorios_; }
  static void insertarFicheros(const std::string&);
  static void eliminarFicherosRand(const std::string&, const std::string&);
 private:
  static std::set<std::string> ficheros_aletorios_;
  static const std::string generarNombreFicheroAleatorio();
  static const std::vector<std::string> generadorIdsAleatorios(const int);
  static const std::string generarConexionNodos(const std::vector<std::string>&, const int, const int);
  static const long double generarCosteAleatorio();
  static const bool nombreExiste(const std::string&);
};