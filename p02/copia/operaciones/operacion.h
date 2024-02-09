#pragma once

#include <iostream>
#include <regex>

#include "../memoria_datos/memoria_datos.h"
#include "../cintas/cinta_in.h"
#include "../cintas/cinta_out.h"
#include "../instruccion/instruccion.h"
#include "../funciones/funciones_necesarias.h"
#include "../operando/operando_constante/operando_constante.h"
#include "../operando/operando_directo/operando_directo.h"
#include "../operando/operando_indirecto/operando_indirecto.h"

class Operacion {
 public:
  virtual bool ValidarInstruccion(const Instruccion&) const = 0;
  virtual void EjecutarInstruccion(const Instruccion&, MemoriaDatos&, CintaIn&, CintaOut&, int&) const = 0;
  virtual ~Operacion() {} // Destructor virtual
};