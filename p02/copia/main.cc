#include <iostream>

#include "comprobar_parametros.h"
#include "cargar_programa.h"
#include "alu.h"
#include "estrategia_almacenamiento.h"
#include "estrategia_almacenamiento_unico.h"
#include "estrategia_almacenamiento_dinamico.h"

int main(int argc, char *argv[]) {
  try {
    ComprobarParametros::ComprobarErrores(argc, argv);
    // Cargar Datos
    EstrategiaAlmacenamiento* estrategia = new EstrategiaUnicoEspacio();
    MemoriaDatos memoria_datos(32, estrategia); // 32 número de registros
    std::cout << memoria_datos << std::endl;
    exit(EXIT_FAILURE);
    //std::cout << memoria_datos << std::endl << std::endl;
    CintaIn cinta_entrada(argv[2]);
    //std::cout << cinta_entrada << std::endl << std::endl;
    MemoriaPrograma memoria_programa;
    CargarPrograma programa(argv[1], memoria_programa);
    //std::cout << memoria_programa << std::endl;
    CintaOut cinta_salida;
    // Ejecutar Programa
    ALU alu;
    try {
      alu.EjecutarPrograma(memoria_programa, memoria_datos, cinta_entrada, cinta_salida);
    } catch (const int kLineaErroneaMemoria) {
      const int kLineaOriginal = programa.get_direcciones_fichero()[kLineaErroneaMemoria];
      std::cout << "Error:" << std::endl;
      std::cout << "Línea: " << kLineaOriginal << std::endl;
      std::cout << "Instrucción: " << programa.get_lineas_fichero()[kLineaOriginal - 1] << std::endl;
      return EXIT_FAILURE;
    }
    // Volcar Cinta salida a Fichero
    //cinta_salida.MeterEnFichero(argv[3]);
  } catch (const std::string& mensaje) {
    std::cout << "Error: " << mensaje << std::endl;
    return EXIT_FAILURE;
  }
  return 0;
}