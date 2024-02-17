/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file cargar_programa.h
 * @brief Definición de la clase CargarPrograma para cargar un programa
 *        en la memoria de programa de la Máquina RAM.
 * @see {@link https://docs.google.com/document/d/1zf_w2HtS4zJX3iqr9yPm6f7rRNsrBxL7afCsMapujMQ/edit#heading=h.5bq8rsdy1ujx}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p03}
 */

#pragma once

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <regex>

#include "../memoria_programa/memoria_programa.h"
#include "../instruccion/instruccion.h"
#include "../funciones/funciones_necesarias.h"

/**
 * @brief Clase CargarPrograma encargada de cargar un programa desde
 *        un archivo de texto en la memoria de programa.
 */
class CargarPrograma {
 public:
  CargarPrograma(const::std::string&, MemoriaPrograma&); // Constructor
  const std::vector<int>& get_direcciones_fichero() const { return direcciones_fichero_; } // Almacena la posición de la línea
  const std::vector<std::string>& get_lineas_fichero() const { return lineas_fichero_; } // Devuelve la línea del fichero
 private:
  std::unordered_map<std::string, int> tabla_etiqueta_valor_; // Guarda cada etiqueta y su posición en la memoria a la que hay que saltar
  std::vector<Instruccion> tabla_instrucciones_; // Almacena cada instrucción
  std::vector<int> direcciones_fichero_; // Posición de las lineas del fichero
  std::vector<std::string> lineas_fichero_; // Lineas del fichero
  int puntero_fichero_; // Puntero a cada línea
  // Métodos necesarios para cargar el programa
  void ExtraerComentarios(std::string&);
  void BuscarEtiqueta(std::string&);
  void AlmacenarEtiqueta(const std::string&);
  void AlmacenarInstruccion(const std::string&);
  void SustituirEtiquetasPorValor();
  const std::vector<std::string> GuardarEtiquetasDeLinea(const std::regex&, const std::string&);
  void GuardaPosInstruccionDelFichero();
};