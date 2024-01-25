#pragma once
#include "matriz.h"

class MultiplicarMatriz {
 public:
  virtual Matriz multiplicar(const Matriz&, const Matriz&) const = 0; 
};