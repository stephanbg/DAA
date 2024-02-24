#pragma once

#include <set>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

class Instancia {
 public:
  Instancia() { this->instancia_ = Instancia::generadorInstanciaAleatoria(); }
  static std::set<std::vector<int>> getConjuntos() { return conjuntos_; }
  const std::vector<int>& getInstancia() const { return instancia_; }
  friend std::ostream& operator<<(std::ostream&, const Instancia&);
 private:
  static std::set<std::vector<int>> conjuntos_;
  static const std::vector<int> generadorInstanciaAleatoria();
  std::vector<int> instancia_;
};