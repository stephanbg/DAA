#pragma once

#include <regex>

#include "../memoria_programa/memoria_programa.h"
#include "../memoria_datos/memoria_datos.h"
#include "../cintas/cinta_in.h"
#include "../cintas/cinta_out.h"
#include "../operaciones/operacion.h"

class ALU {
 public:
  void EjecutarPrograma(const MemoriaPrograma&, MemoriaDatos&, CintaIn&, CintaOut&);
 private:
  int pc_;
  //bool ValidarInstruccion(const Instruccion&);
  //bool FormatoOperacionCorrecta(const std::vector<std::regex>&, const Instruccion&);
};