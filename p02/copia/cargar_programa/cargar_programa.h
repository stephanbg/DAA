#pragma once

#include <unordered_map>
#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <fstream>
#include <sstream>

#include "../memoria_programa/memoria_programa.h"
#include "../instruccion/instruccion.h"
#include "../funciones/funciones_necesarias.h"

class CargarPrograma {
 public:
  CargarPrograma(const::std::string&, MemoriaPrograma&);
  const std::vector<int>& get_direcciones_fichero() const { return direcciones_fichero_; }
  const std::vector<std::string>& get_lineas_fichero() const { return lineas_fichero_; }
 private:
  std::unordered_map<std::string, int> tabla_etiqueta_valor_;
  std::vector<Instruccion> tabla_instrucciones_;
  std::vector<int> direcciones_fichero_;
  std::vector<std::string> lineas_fichero_;
  int puntero_fichero_;
  // Comprueba errores
  void ExtraerComentarios(std::string&);
  void BuscarEtiqueta(std::string&);
  void AlmacenarEtiqueta(const std::string&);
  void AlmacenarInstruccion(const std::string&);
  void SustituirEtiquetasPorValor();
  const std::vector<std::string> GuardarEtiquetasDeLinea(const std::regex&, const std::string&);
  void GuardaPosInstruccionDelFichero();
};