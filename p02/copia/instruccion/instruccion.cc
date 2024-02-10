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

#include "../operando/operando_constante/operando_constante.h"
#include "../operando/operando_directo/operando_directo.h"
#include "../operando/operando_indirecto/operando_indirecto.h"

#include "../operaciones/error_tipo/error_tipo.h"
#include "../operando/error_operando/error_operando.h"

Instruccion::Instruccion(const std::string& kInstruccion) {
  std::string operador = "";
  std::string operando = "";
  SepararInstruccionEnPalabras(kInstruccion);
  if (instruccion_.size() >= 1 && instruccion_.size() <= 2) { // Asumo que solo vendrán (operador + operando)
    operador = TipoOperador();
    if (instruccion_.size() == 2) operando = TipoOperando();
    operador = ConvertirAMayusculas(operador);
    instruccion_[0] = operador;
  }
  if (!ConstruirOperador(operador)) {
    tipo_operacion_ = new ErrorTipo();
  }
  if (!ConstruirOperando(operador, operando)) {
    tipo_operando_ = new ErrorOperando();
  }
}

bool Instruccion::ConstruirOperador(const std::string& kOperador) {
  if (kOperador == "LOAD") {
    tipo_operacion_ = new Load();
  } else if (kOperador == "STORE") {
    tipo_operacion_ = new Store();
  } else if (kOperador == "ADD") {
    tipo_operacion_ = new Add();
  } else if (kOperador == "SUB") {
    tipo_operacion_ = new Sub();
  } else if (kOperador == "MUL") {
    tipo_operacion_ = new Mul();
  } else if (kOperador == "DIV") {
    tipo_operacion_ = new Div();
  } else if (kOperador == "READ") {
    tipo_operacion_ = new Read();
  } else if (kOperador == "WRITE") {
    tipo_operacion_ = new Write();
  } else if (kOperador == "JUMP") {
    tipo_operacion_ = new Jump();
  } else if (kOperador == "JZERO") {
    tipo_operacion_ = new Jzero();
  } else if (kOperador == "JGTZ") {
    tipo_operacion_ = new Jgtz();
  } else if (kOperador == "HALT") {
    tipo_operacion_ = new Halt();
  } else return false;
  return true;
}

bool Instruccion::ConstruirOperando(const std::string& kOperador, const std::string& kOperando) {
  if (kOperador == "LOAD" || kOperador == "ADD" || kOperador == "SUB" ||
      kOperador == "MUL" || kOperador == "DIV" || kOperador == "WRITE") {
    if (kOperando[0] == '=') {
      tipo_operando_ = new OperandoConstante();
    } else if (sonTodoDigitos(kOperando)) {
      tipo_operando_ = new OperandoDirecto();
    } else if (kOperando[0] == '*') {
      tipo_operando_ = new OperandoIndirecto();
    } else return false;      
  } else if (kOperador == "STORE" || kOperador == "READ") {
    if (sonTodoDigitos(kOperando)) {
      tipo_operando_ = new OperandoDirecto();
    } else if (kOperando[0] == '*') {
      tipo_operando_ = new OperandoIndirecto();
    } else return false;    
    // Solo puede ser constante porque si hay error fuerzo a -1 y si no es una dirección de la memoria
  } else if (kOperador == "JUMP" || kOperador == "JZERO" || kOperador == "JGTZ") {
    tipo_operando_ = new OperandoConstante();
  } else if (kOperador == "HALT") return true;
    else return false;
  tipo_operando_->set_lecturaOEscritura(kOperador);
  return true;
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

const std::string& Instruccion::TipoOperando() const {
  return instruccion_[1];
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