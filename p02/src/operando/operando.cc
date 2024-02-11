#include "operando.h"  
  
void Operando::set_lecturaOEscritura(const std::string& kOperador) { 
  if (kOperador == "LOAD" || kOperador == "ADD" || kOperador == "SUB" ||
      kOperador == "MUL" || kOperador == "DIV") {
    lecturaOEscritura_ = "Lectura"; /// Lectura
  } else if (kOperador == "WRITE" || kOperador == "STORE" || kOperador == "READ") {
    lecturaOEscritura_ = "Escritura"; /// Escritura
  }
}