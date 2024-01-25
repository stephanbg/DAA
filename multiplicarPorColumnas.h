#pragma once
#include "multiplicarMatriz.h"

class MultiplicarPorColumnas : public MultiplicarMatriz {
 public:
  Matriz multiplicar(const Matriz&, const Matriz&) const override;
};