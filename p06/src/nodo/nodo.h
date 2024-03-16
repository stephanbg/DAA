#pragma once

#include <string>
#include <vector>

#include "../arista/arista.h"

class Nodo {
 public:
  Nodo(const std::string kId): id_(kId) {}
  void insertarNodoVecino(Nodo* vecino, long double peso = 0.0) {
    nodosVecinos_.emplace_back(vecino, peso);
  }
  const std::vector<Arista>& getNodosVecinos() const { return nodosVecinos_; }
  const std::string getId() const { return id_; }
  const long double getCoste(const Nodo* otroNodo) const {
    for (const auto& a : this->getNodosVecinos()) {
      if (a.getNodoDestino()->getId() == otroNodo->getId()) return a.getPeso();
    }
    return -1;
  }
  //std::string& setValor(const std::string kId) { id_ = kId; }
 private:
  std::string id_;
  std::vector<Arista> nodosVecinos_;
};