#pragma once

#include <iostream>
#include <vector>

#include "../instruccion/instruccion.h"

class MemoriaPrograma {
 public:
  MemoriaPrograma() {}
  MemoriaPrograma(const std::vector<Instruccion>& programa) : programa_(programa) {}
  const std::vector<Instruccion>& get_programa() const { return programa_; }
  friend std::ostream& operator<<(std::ostream&, const MemoriaPrograma&);
 private:
  std::vector<Instruccion> programa_;
};