#pragma once

#include "debug.h"

class ModoNormal: public Debug {
 public:
  virtual void ejecutar(TablaAlgoritmos&) const override;
};