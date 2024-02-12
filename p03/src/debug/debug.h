#pragma once

#include <iostream>

#include "../instruccion/instruccion.h"
#include "../memoria_datos/memoria_datos.h"
#include "../cintas/cinta_in.h"
#include "../cintas/cinta_out.h"

class Debug {
 public:  
  virtual void MostrarNumeroInstruccionesEjecutadas(const int kNumInstrucciones) const {
    std::cout << "Número de instrucciones ejecutadas: " << kNumInstrucciones << std::endl;
  } 
  virtual void InfoDuranteEjecucion(const Instruccion&, const MemoriaDatos&,
                                    const CintaIn&, const CintaOut&) const = 0;
  ~Debug() {}
};