#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "../funciones/funciones.h"

class SintaxisFicheroGrafo {
 public:
  static const bool numeroNodosValido(const std::string&);
  static const bool tresElementosPorLineaNodo1Nodo2Coste(const std::vector<std::string>&);
};