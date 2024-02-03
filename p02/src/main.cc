#include <iostream>

#include "comprobar_parametros.h"
#include "compilador.h"
#include "cinta_in.h"

int main(int argc, char *argv[]) {
  try {
    ComprobarParametros::ComprobarErrores(argc, argv);
    Compilador compilador;
    compilador.CompilarPrograma(argv[1]);
    //CintaIn cinta_entrada(argv[2]);
    //std::cout << cinta_entrada << std::endl;
    /// GuardarProgramaEnMemoria(instrucciones);
    /// EjecutarPrograma();
    /// MeterEnFichero();
  } catch (const std::string& mensaje) {
    std::cout << "Error: " << mensaje << std::endl;
    return EXIT_FAILURE;
  }
  return 0;
}