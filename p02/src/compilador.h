#pragma once

#include <unordered_map>
#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <fstream>
#include <sstream>

class Compilador {
 public:
  void CompilarPrograma(const::std::string&);
 private:
  std::unordered_map<std::string, int> tabla_etiqueta_valor_;
  std::vector<std::string> tabla_instrucciones_;
  int puntero_linea_;
  // Comprueba errores
  void CompilarLinea(std::string&, std::vector<std::string>&);
  void ExtraerComentarios(std::string&);
  void SepararInstruccionEnPalabras(const std::string&, std::vector<std::string>&);
  void ComprobarInstruccion(const std::vector<std::string>&);
  // AlmacenarDatos
  void AlmacenarInstruccion(const std::vector<std::string>&);
  void AlmacenarEtiqueta(const std::string&);
  // Comprobar el formato de las instrucciones
  bool EsOperacionConstante(const std::vector<std::string>&);
  bool EsOperacionDirecta(const std::vector<std::string>&);
  bool EsOperacionIndirecta(const std::vector<std::string>&);
  bool EsEtiqueta(const std::string&);
  // Mostrar fallo
  void MostrarInstruccionYLineaErronea(const std::vector<std::string>&);

};