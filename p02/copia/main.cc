#include <iostream>

#include "comprobar_parametros/comprobar_parametros.h"
#include "cargar_programa/cargar_programa.h"
#include "alu/alu.h"
#include "estrategia_almacenamiento/estrategia_almacenamiento.h"
#include "estrategia_almacenamiento/estrategia_almacenamiento_unico.h"
#include "estrategia_almacenamiento/estrategia_almacenamiento_dinamico.h"

int main(int argc, char *argv[]) {
  try {
    ComprobarParametros::ComprobarErrores(argc, argv);
    // Cargar Datos
    EstrategiaAlmacenamiento* estrategia = new EstrategiaUnicoEspacio();
    MemoriaDatos memoria_datos(32, estrategia); // 32 número de registros
    CintaIn cinta_entrada(argv[2]);
    MemoriaPrograma memoria_programa;
    CargarPrograma programa(argv[1], memoria_programa);
    CintaOut cinta_salida;
    // Ejecutar Programa
    ALU alu;
    try {
      alu.EjecutarPrograma(memoria_programa, memoria_datos, cinta_entrada, cinta_salida);
    } catch (const int kLineaErroneaMemoria) { /// Error al validar la instrucción
      const int kLineaOriginal = programa.get_direcciones_fichero()[kLineaErroneaMemoria];
      std::cout << "Error:" << std::endl;
      std::cout << "Línea: " << kLineaOriginal << std::endl;
      std::cout << "Instrucción: " << programa.get_lineas_fichero()[kLineaOriginal - 1] << std::endl;
    } catch (const std::string& kErrorEjecucion) { /// Error al ejecutar la instrucción
      std::cout << "Error: " << kErrorEjecucion << std::endl;
    }
    //std::cout << memoria_datos << std::endl;
    // Volcar Cinta salida a Fichero
    cinta_salida.MeterEnFichero(argv[3]);
  } catch (const std::string& mensaje) { /// Carga el progrma en memoria
    std::cout << "Error: " << mensaje << std::endl;
    return EXIT_FAILURE;
  }
  return 0;
}