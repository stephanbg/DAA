#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "../matriz/matriz.h"
#include "../funciones/funciones.h"

class Problema {
 public:
  Problema(const std::string&);
 private:
  Matriz elementos_subconjunto_;
  Matriz distancias_;
};