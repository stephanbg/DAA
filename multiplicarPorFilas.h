#pragma once
#include "multiplicarMatriz.h"

class MultiplicarPorFilas : public MultiplicarMatriz {
 public:
  Matriz multiplicar(const Matriz&, const Matriz&) const override;
};