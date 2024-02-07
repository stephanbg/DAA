#include "instruccion.h"
#include "../operaciones/load/load.h"
#include "../operaciones/store/store.h"
#include "../operaciones/add/add.h"
#include "../operaciones/sub/sub.h"
#include "../operaciones/mul/mul.h"
#include "../operaciones/div/div.h"
#include "../operaciones/read/read.h"
#include "../operaciones/write/write.h"
#include "../operaciones/jump/jump.h"
#include "../operaciones/jzero/jzero.h"
#include "../operaciones/jgtz/jgtz.h"
#include "../operaciones/halt/halt.h"
#include "../operaciones/error_tipo/error_tipo.h"

Instruccion::Instruccion(const std::string& kInstruccion) {
  std::string tipo = "";
  SepararInstruccionEnPalabras(kInstruccion);
  if (!instruccion_.empty()) {
    tipo = TipoOperador();
    tipo = ConvertirAMayusculas(tipo);
    instruccion_[0] = tipo;
  }
  if (tipo == "LOAD") {
    tipo_operacion_ = new LOAD();
  } else if (tipo == "STORE") {
    tipo_operacion_ = new STORE();
  } else if (tipo == "ADD") {
    tipo_operacion_ = new ADD();
  } else if (tipo == "SUB") {
    tipo_operacion_ = new SUB();
  } else if (tipo == "MUL") {
    tipo_operacion_ = new MUL();
  } else if (tipo == "DIV") {
    tipo_operacion_ = new DIV();
  } else if (tipo == "READ") {
    tipo_operacion_ = new READ();
  } else if (tipo == "WRITE") {
    tipo_operacion_ = new WRITE();
  } else if (tipo == "JUMP") {
    tipo_operacion_ = new JUMP();
  } else if (tipo == "JZERO") {
    tipo_operacion_ = new JZERO();
  } else if (tipo == "JGTZ") {
    tipo_operacion_ = new JGTZ();
  } else if (tipo == "HALT") {
    tipo_operacion_ = new HALT();
  } else {
    tipo_operacion_ = new ErrorTipo();
  }
}

void Instruccion::SepararInstruccionEnPalabras(const std::string& kLinea) {
  // Separo la instrucción en palabras
  std::istringstream iss(kLinea);
  std::string palabra;
  while (iss >> palabra) {
    instruccion_.push_back(palabra);
  }
}

const std::string& Instruccion::TipoOperador() const {
  return instruccion_[0];
}

const long double Instruccion::ObtenerConstante() const {
  const std::string kOperando = instruccion_[1];
  std::string constanteNumerica = instruccion_[1];
  if (kOperando[0] == '=' || kOperando[0] == '*' ) {
    constanteNumerica = constanteNumerica.substr(1);
  }
  return stold(constanteNumerica);
}

std::ostream& operator<<(std::ostream& os, const Instruccion& kInstruccion) {
  const int kSizeInstruccion = kInstruccion.instruccion_.size();
  for (int i = 0; i < kSizeInstruccion; ++i) {
    os << kInstruccion.instruccion_[i];
    if (i < kSizeInstruccion - 1) os << " ";
  }
  return os;
}