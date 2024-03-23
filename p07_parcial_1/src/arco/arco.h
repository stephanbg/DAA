/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Marzo de 2024
 * @file arista.h
 * @brief Definición e implementación de la clase Arista
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p06/src}
 * @see {@link https://docs.google.com/document/d/1a691HPtHQL4qBtI2qaTMTp23wxZvU8-CCIbGOyNJRQo/edit}
 */

#pragma once

#include "../nodo/nodo.h"

class Nodo;

/**
 * @brief Clase que representa una arista en un grafo.
 * 
 * Esta clase modela una arista que conecta un nodo de origen con un nodo de destino,
 * con un peso asociado que representa la distancia entre los nodos.
 */
class Arco {
 public:
  Arco(const int kCoste): coste_(kCoste) {}
  Arco(Nodo*& nodoDestino, const int kCoste) : nodo_destino_(nodoDestino), coste_(kCoste) {}
  const Nodo* getNodoDestino() const { return nodo_destino_; }
  const int getCoste() const { return coste_; }
 private:
  int coste_;
  Nodo* nodo_destino_;
};