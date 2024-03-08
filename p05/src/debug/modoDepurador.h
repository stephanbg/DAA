#pragma once

#include "debug.h"

class ModoDepurador: public Debug {
 public:
  virtual void ejecutar(TablaAlgoritmos&) const override;
};