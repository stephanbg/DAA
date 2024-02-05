#pragma once

#include <regex>

#include "memoria_programa.h"
#include "memoria_datos.h"
#include "cinta_in.h"
#include "cinta_out.h"

class ALU {
 public:
  void EjecutarPrograma(const MemoriaPrograma&, MemoriaDatos&, CintaIn&, CintaOut&);
 private:
  bool ValidarInstruccion(const Instruccion&);
  bool FormatoOperacionCorrecta(const std::vector<std::regex>&, const Instruccion&);
};