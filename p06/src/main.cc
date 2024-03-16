#include "comprobar_parametros/comprobar_parametros.h"
#include "grafo/grafoNoDirigidoCompleto.h"
#include "TSP/voraz_tsp.h"
#include "TSP/fuerza_bruta_tsp.h"
#include "TSP/programacion_dinamica_tsp.h"

int main(int argc, char *argv[]) {
  try {
    //ComprobarParametros::comprobar(argc, argv);  
  } catch (const std::string& kErrorParametros) {
    std::cout << "Error: " << kErrorParametros << "." << std::endl << std::endl;
    ComprobarParametros::ayuda();
    return EXIT_FAILURE;
  }
  try {
    GrafoNoDirigidoCompleto grafo(argv[1]);
    //std::cout << grafo << std::endl;
    VorazTSP tsp1;
    FuerzaBrutaTSP tsp2;
    ProgramacionDinamicaTSP tsp3;
    // Voraz
    //tsp1.ejecutar(grafo);
    //tsp1.mostrarCaminoMinimo();
    //tsp1.mostrarCoste();
    //tsp1.mostrarTiempoEjecución();
    // Fuerza Bruta
    //tsp2.ejecutar(grafo);
    //tsp2.mostrarCaminoMinimo();
    //tsp2.mostrarCoste();
    //tsp2.mostrarTiempoEjecución();
    // Programación dinámica
    
    tsp3.ejecutar(grafo);
    tsp3.mostrarCaminoMinimo();
    //tsp3.mostrarCoste();
    //tsp3.mostrarTiempoEjecución();
  } catch (const std::string& kErrorEnGrafo) {
    std::cout << "Error: " << kErrorEnGrafo << "." << std::endl;
  }
  return 0;
}