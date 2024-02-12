/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @brief Práctica 2, simulador de la Máquina RAM
 *        Implementación de un simulador de Máquina de Acceso Aleatorio (RAM)
 *        según las especificaciones dadas. La Máquina RAM se utiliza para calcular
 *        la complejidad de los algoritmos mediante la ejecución de un conjunto de
 *        instrucciones sobre una memoria de programa y una memoria de datos.
 * @see {@link https://docs.google.com/document/d/1n6iua2wSG2UVns-mTA4YdMBVKfKIazkJi4HRzKVKS78/edit}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p02}
 */

#include <iostream>
#include <string>

#include "comprobar_parametros/comprobar_parametros.h"
#include "cargar_programa/cargar_programa.h"
#include "alu/alu.h"
#include "estrategia_almacenamiento/estrategia_almacenamiento.h"
#include "estrategia_almacenamiento/estrategia_almacenamiento_unico.h"
#include "estrategia_almacenamiento/estrategia_almacenamiento_dinamico.h"
#include "debug/debug_utilidades.h"

/**
 * @brief Función principal del programa, se encarga de comprobar parámetrosd e entrada,
 *        de cargar los datos, de ejecutar el programa en la ALU, y lanzar la cinta de salida
 *        a un fichero. Recoge cualquier throw lanzado en el programa.
 * 
 * @param argc Cantidad de parámetros de la línea de comandos
 * @param argv El array de parámetros de la línea de comandos
 * @return Devuelve EXIT_FAILURE si detecta un fallo muy grave y si no devuelve 0.
 */
int main(int argc, char *argv[]) {
  try {
    // Comprobar parámetros
    ComprobarParametros::ComprobarErrores(argc, argv);
    // Cargar Datos
    Debug* debugger = crear_debug(argv[4]);
    EstrategiaAlmacenamiento* estrategia = new EstrategiaVectorDinamico();
    MemoriaDatos memoria_datos(32, estrategia); // 32 número de registros
    CintaIn cinta_entrada(argv[2]);
    MemoriaPrograma memoria_programa;
    CargarPrograma programa(argv[1], memoria_programa);
    CintaOut cinta_salida;
    // Ejecutar Programa
    ALU alu;
    try {
      alu.EjecutarPrograma(memoria_programa, memoria_datos, cinta_entrada, cinta_salida, debugger);
    } catch (const int kLineaErroneaMemoria) { // Error al validar la instrucción
      const int kLineaOriginal = programa.get_direcciones_fichero()[kLineaErroneaMemoria];
      std::cout << "Error: Sintaxis" << std::endl;
      std::cout << "Línea: " << kLineaOriginal << std::endl;
      std::cout << "Instrucción: " << programa.get_lineas_fichero()[kLineaOriginal - 1] << std::endl;
    } catch (const std::string& kErrorEjecucion) { // Error al ejecutar la instrucción
      const size_t pos_barra = kErrorEjecucion.find('|');
      std::string error_ejecucion = kErrorEjecucion.substr(0, pos_barra);
      int linea_original = stoi(kErrorEjecucion.substr(pos_barra + 1));
      linea_original = programa.get_direcciones_fichero()[linea_original];
      std::cout << "Error: " << error_ejecucion << std::endl;
      std::cout << "Línea: " << linea_original << std::endl;
      std::cout << "Instrucción: " << programa.get_lineas_fichero()[linea_original - 1] << std::endl;      
    }
    // Volcar Cinta salida a Fichero
    cinta_salida.MeterEnFichero(argv[3]);
  } catch (const std::string& mensaje) { // Carga el programa en memoria (graves) o meter en fichero
    std::cout << "Error: " << mensaje << std::endl;
    return EXIT_FAILURE;
  }
  return 0;
}