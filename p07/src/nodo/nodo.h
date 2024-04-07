/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 20 de Marzo de 2024
 * @file nodo.h
 * @brief Definición e implementación de la clase Nodo que se encarga
 * de crear nodos para un grafo
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07_parcial_1/src}
 */

#pragma once

#include <string>
#include <vector>

#include "../arco/arco.h"

/**
 * @brief Clase que representa un nodo en un grafo.
 * 
 * Un nodo tiene un identificador único y puede estar conectado a otros nodos a través de arcos.
 */
class Nodo {
 public:
  Nodo(const std::string kId): id_(kId) {}
  /**
   * @brief Inserta un nodo vecino al nodo actual junto con el peso del arco que los conecta.
   * 
   * @param vecino Puntero al nodo vecino a insertar.
   * @param peso Peso del arco que conecta al nodo actual con el nodo vecino (por defecto es 0).
   */  
  void insertarNodoVecino(Nodo* vecino, const int kCoste = 0) {
    nodosVecinos_.emplace_back(vecino, kCoste);
  }
  const std::vector<Arco>& getNodosVecinos() const { return nodosVecinos_; }
  const Arco& getVecino(const int kIndice) const { return nodosVecinos_[kIndice]; }
  const std::string getId() const { return id_; }
  /**
   * @brief Obtiene el peso del arco que conecta al nodo actual con otro nodo dado.
   * 
   * @param otroNodo Puntero al nodo con el que se quiere obtener el peso del arco.
   * @return Peso del arco que conecta al nodo actual con otro nodo dado, o -1 si no existe el arco.
   */  
  const int getCosteHaciaVecino(const Nodo* otroNodo) const {
    for (const auto& a : this->getNodosVecinos()) {
      if (a.getNodoDestino()->getId() == otroNodo->getId()) return a.getCoste();
    }
    return -1;
  }
 private:
  std::string id_;
  std::vector<Arco> nodosVecinos_;
};