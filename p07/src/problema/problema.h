/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 20 de Marzo de 2024
 * @file problema.h
 * @brief Definición de la clase Problema que se encarga
 * de leer los datos de un fichero y crear el grafo
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07/src}
 */

#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>

#include "../nodo/nodo.h"

namespace fs = std::filesystem;

/**
 * @brief Clase que genera un Problema (grafo dirigido completo)
 */
class Problema {
 public:
  Problema(const std::string&);
  const std::vector<Nodo*>& getGrafo() const { return grafo_; }
  friend std::ostream& operator<<(std::ostream&, const Problema&);
  ~Problema();
 private:
  std::vector<Nodo*> grafo_;
  const int calculaNumeroNodos(const std::string&) const;
  void calculaTiemposProcesamientos(const std::string&, std::vector<int>&);
  void calculaTiemposSetUp(const std::string&, std::vector<std::vector<int>>&) const;  
  void rellenarCostesArcos(const std::vector<std::vector<int>>&, const std::vector<int>&);
  const bool esCorrectaCantidadNodos(const int) const;
  const bool esCompleto() const;
  const bool existeArco(const Nodo*, const Nodo*) const;
};