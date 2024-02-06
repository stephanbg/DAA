#pragma once

#include <regex>

#include "memoria_programa.h"
#include "memoria_datos.h"
#include "cinta_in.h"
#include "cinta_out.h"
#include "operacion.h"
#include "operacion_constante.h"
#include "operacion_directa.h"
#include "operacion_indirecta.h"

class ALU {
 public:
  void EjecutarPrograma(const MemoriaPrograma&, MemoriaDatos&, CintaIn&, CintaOut&);
 private:
  Operacion* operacion_;
  int pc_;
  bool ValidarInstruccion(const Instruccion&);
  bool FormatoOperacionCorrecta(const std::vector<std::regex>&, const Instruccion&);
};