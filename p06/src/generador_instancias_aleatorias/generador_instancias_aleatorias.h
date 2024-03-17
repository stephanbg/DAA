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