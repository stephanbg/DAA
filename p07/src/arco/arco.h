/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 20 de Marzo de 2024
 * @file arco.h
 * @brief Definición e implementación de la clase Arco para enlazar dos nodos
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07/src}
 */

#pragma once

#include "../nodo/nodo.h"

class Nodo;

/**
 * @brief Clase que representa un arco en un grafo.
 * 
 * Esta clase modela un arco que conecta un nodo de origen con un nodo de destino,
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