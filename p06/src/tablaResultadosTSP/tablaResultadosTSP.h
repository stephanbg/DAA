#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class TablaResultadosTSP {
 public:
  static void insertarDatoNombreFichero(const std::string&);
  static void insertarDatoNombreAlgoritmo(const std::string&);
  static void insertarFilaMatrizDatos(const std::vector<std::pair<const long double, const long double>>&);
  static void mostrarTablaEnPantalla();
  static void mostrarTablaEnFichero();
 private:
  static std::vector<std::string> nombres_ficheros_;
  static std::vector<std::string> nombres_algoritmos_;
  static std::vector<std::vector<std::pair<const long double, const long double>>> matriz_datos_;
};