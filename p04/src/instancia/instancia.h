#pragma once

#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

class Instancia {
 public:
  Instancia(const bool generarAleatorio = false) { 
    if (generarAleatorio) this->generadorInstanciaAleatoria();
  }
  Instancia(const std::vector<int>& instancia): instancia_(instancia) {}
  const int size() const { return this->getInstancia().size(); }
  std::vector<int>& setInstancia() { return instancia_; }
  const std::vector<int>& getInstancia() const { return instancia_; }
  int& operator[](const size_t kIndice) { return instancia_[kIndice]; }
  const int operator[](const size_t kIndice) const { return instancia_[kIndice]; }   
  friend std::ostream& operator<<(std::ostream&, const Instancia&);
 private:
  void generadorInstanciaAleatoria();
  std::vector<int> instancia_;
};