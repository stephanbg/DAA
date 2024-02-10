#include "alu.h"

void ALU::EjecutarPrograma(const MemoriaPrograma& kMemoriaPrograma,
                           MemoriaDatos& memoria_datos,
                           CintaIn& cinta_in, CintaOut& cinta_out) {
  const int kSizeMemoriaPrograma = kMemoriaPrograma.get_programa().size();
  pc_ = 0;
  while ((pc_ < kSizeMemoriaPrograma) && (pc_ != -1)) {
    if (!kMemoriaPrograma.get_programa()[pc_].get_tipo_operacion()->ValidarInstruccion(kMemoriaPrograma.get_programa()[pc_])) {
      throw (pc_);
    }
    try { /// Si al ejecutar detecta error reenvía la línea errónea hacia el main
      kMemoriaPrograma.get_programa()[pc_].get_tipo_operacion()->EjecutarInstruccion(kMemoriaPrograma.get_programa()[pc_],
                                                                                     memoria_datos, cinta_in, cinta_out, pc_);
    } catch (const std::string& kError) {
      std::string error_con_linea = kError + "|" + std::to_string(pc_);
      throw(error_con_linea);
    }
  }
}