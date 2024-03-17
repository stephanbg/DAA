/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Marzo de 2024
 * @file grafoNoDirigidoCompleto.h
 * @brief Definición de la clase GrafoNoDirigidoCompleto
 * que generará grafos no dirigidos completos
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p06/src}
 * @see {@link https://docs.google.com/document/d/1a691HPtHQL4qBtI2qaTMTp23wxZvU8-CCIbGOyNJRQo/edit}
 */

#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>

#include "../nodo/nodo.h"
#include "../sintaxis_fichero_grafo/sintaxis_fichero_grafo.h"

namespace fs = std::filesystem;

/**
 * @brief Clase que genera un grafo no dirigido completo
 * 
 */
class GrafoNoDirigidoCompleto {
 public:
  GrafoNoDirigidoCompleto(const std::string, const std::string);
  const std::vector<Nodo*>& getGrafo() const { return grafo_; }
  const int getIndiceNodo(const std::string&) const;
  friend std::ostream& operator<<(std::ostream&, const GrafoNoDirigidoCompleto&);
 private:
  std::vector<Nodo*> grafo_;
  const bool existeArista(const Nodo*, const Nodo*) const;
  const bool esCompleto() const;
  const bool esCorrectaCantidadNodos(const int) const;
};