#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

#include "../nodo/nodo.h"
#include "../sintaxis_fichero_grafo/sintaxis_fichero_grafo.h"

class GrafoNoDirigidoCompleto {
 public:
  GrafoNoDirigidoCompleto(const std::string);
  const std::vector<Nodo*>& getGrafo() const { return grafo_; }
  const int getIndiceNodo(const std::string&) const;
  friend std::ostream& operator<<(std::ostream&, const GrafoNoDirigidoCompleto&);
 private:
  std::vector<Nodo*> grafo_;
  const bool existeArista(const Nodo*, const Nodo*) const;
  const bool esCompleto() const;
  const bool esCorrectaCantidadNodos(const int) const;
};