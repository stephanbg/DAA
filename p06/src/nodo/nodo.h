/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Marzo de 2024
 * @file nodo.h
 * @brief Definición e implementación de la clase Nodo
 * que generará nodos de un grafo
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p06/src}
 * @see {@link https://docs.google.com/document/d/1a691HPtHQL4qBtI2qaTMTp23wxZvU8-CCIbGOyNJRQo/edit}
 */

#pragma once

#include <string>
#include <vector>

#include "../arista/arista.h"

/**
 * @brief Clase que representa un nodo en un grafo.
 * 
 * Un nodo tiene un identificador único y puede estar conectado a otros nodos a través de aristas.
 */
class Nodo {
 public:
  Nodo(const std::string kId): id_(kId) {}
  /**
   * @brief Inserta un nodo vecino al nodo actual junto con el peso de la arista que los conecta.
   * 
   * @param vecino Puntero al nodo vecino a insertar.
   * @param peso Peso de la arista que conecta al nodo actual con el nodo vecino (por defecto es 0).
   */  
  void insertarNodoVecino(Nodo* vecino, long double peso = 0.0) {
    nodosVecinos_.emplace_back(vecino, peso);
  }
  const std::vector<Arista>& getNodosVecinos() const { return nodosVecinos_; }
  const std::string getId() const { return id_; }
  /**
   * @brief Obtiene el peso de la arista que conecta al nodo actual con otro nodo dado.
   * 
   * @param otroNodo Puntero al nodo con el que se quiere obtener el peso de la arista.
   * @return Peso de la arista que conecta al nodo actual con otro nodo dado, o -1 si no existe la arista.
   */  
  const long double getCoste(const Nodo* otroNodo) const {
    for (const auto& a : this->getNodosVecinos()) {
      if (a.getNodoDestino()->getId() == otroNodo->getId()) return a.getPeso();
    }
    return -1;
  }
 private:
  std::string id_;
  std::vector<Arista> nodosVecinos_;
};