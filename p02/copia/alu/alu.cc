#include "alu.h"

void ALU::EjecutarPrograma(const MemoriaPrograma& kMemoriaPrograma,
                           MemoriaDatos& memoria_datos,
                           CintaIn& cinta_in, CintaOut& cinta_out) {
  const int kSizeMemoriaPrograma = kMemoriaPrograma.get_programa().size();
  pc_ = 0;
  while (pc_ < kSizeMemoriaPrograma) {
    if (!kMemoriaPrograma.get_programa()[pc_].get_tipo_operacion()->ValidarInstruccion(kMemoriaPrograma.get_programa()[pc_])) {
      throw (pc_);
    }    
    try { /// Si al ejecutar detecta error reenvía la línea errónea hacia el main
      kMemoriaPrograma.get_programa()[pc_].get_tipo_operacion()->EjecutarInstruccion(kMemoriaPrograma.get_programa()[pc_],
                                                                                   memoria_datos, cinta_in, cinta_out, pc_);
    } catch (...) {
        throw(pc_);
    }
  }
}

/*bool ALU::ValidarInstruccion(const Instruccion& kInstruccion) {
  std::vector<std::regex> vector_patrones;
  const std::string K32Registros = "([0-9]|[1-2][0-9]|3[0-1])";
  const std::string K32RegistrosMenosR0 = "([1-9]|[1-2][0-9]|3[0-1])";

  const std::regex kPatron1("^=[-+]?\\d+([,.]?\\d+|\\d*)$"); // Empieza por '=' y acaba por uno o más dígitos
  const std::regex kPatron2("^" + K32Registros + "$"); // permite 0-31 registros
  const std::regex kPatron3("^\\*" + K32Registros + "$"); // Empieza por '*' y acaba por uno o más dígitos
  //const std::regex kPatron2("^([0-9]|[1-9][0-9]{1,2}|10[0-1][0-9]|102[0-3])$"); // permite 0-1023 registros
  //const std::regex kPatron4("^=[-+]?" + K32Registros + "[,.]?\\d+$"); // Empieza por '=' + 0's + [1-9]'s o [1-9]'s
  const std::regex kPatron4("^" + K32RegistrosMenosR0 + "$"); // Empieza por 0's + [1-9]'s o [1-9]'s
  const std::regex kPatron5("^=\\d+$"); // Empieza por '*' + 0's + [1-9]'s o [1-9]'s 
  const std::string kTipo = kInstruccion.TipoOperador();
  if (kTipo == "LOAD" || kTipo == "ADD" || kTipo == "SUB" ||
      kTipo == "MUL" || kTipo == "DIV") {
    vector_patrones.push_back(kPatron1);
    vector_patrones.push_back(kPatron2);
    vector_patrones.push_back(kPatron3);
  } else if (kTipo == "STORE") {
    vector_patrones.push_back(kPatron2);
    vector_patrones.push_back(kPatron3);
  } else if (kTipo == "READ") {
    vector_patrones.push_back(kPatron3);
    vector_patrones.push_back(kPatron4);
  } else if (kTipo == "WRITE") {
    vector_patrones.push_back(kPatron1);
    vector_patrones.push_back(kPatron3);
    vector_patrones.push_back(kPatron4);
  } else if (kTipo == "JUMP" || kTipo == "JZERO" || kTipo == "JGTZ") {
    vector_patrones.push_back(kPatron5);
  } else if (kTipo == "HALT") {
    if (kInstruccion.get_instruccion().size() > 1) return false;
    else return true;
  } else {
    return false; // Instrucción desconocida
  }
  if (FormatoOperacionCorrecta(vector_patrones, kInstruccion)) return true;
  else return false;
}

bool ALU::FormatoOperacionCorrecta(const std::vector<std::regex>& kVectorPatrones,
                            const Instruccion& kPalabrasInstruccion) {
  if (kPalabrasInstruccion.get_instruccion().size() != 2) return false; // Si hay más de un operando error
  const int kSizeVectorPatrones = kVectorPatrones.size(); 
  for (int i = 0; i < kSizeVectorPatrones; ++i) {
    if (std::regex_match(kPalabrasInstruccion.get_instruccion()[1], kVectorPatrones[i])) return true;
  }
  return false;
}*/