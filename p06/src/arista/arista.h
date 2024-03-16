#pragma once

#include "../nodo/nodo.h"

class Nodo;

class Arista {
 public:
  Arista(const long double kPeso): peso_(kPeso) {}
  Arista(Nodo*& nodoDestino, const long double kPeso) : nodoDestino_(nodoDestino), peso_(kPeso) {}
  //const std::pair<Nodo*, Nodo*>& getNodoOrigenDestino() const { return nodoOrigenDestino_; }
  //std::pair<Nodo*, Nodo*>& setNodoOrigenDestino() { return nodoOrigenDestino_; }
  const Nodo* getNodoDestino() const { return nodoDestino_; }
  const long double getPeso() const { return peso_; }
  //void setPeso(const long double kPeso) { peso_ = kPeso; }
 private:
  long double peso_;
  Nodo* nodoDestino_;
};