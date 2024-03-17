#include <set>
#include <string>
#include <random>

#include "comprobar_parametros/comprobar_parametros.h"
#include "generador_instancias_aleatorias/generador_instancias_aleatorias.h"
#include "funciones/peticionesUsuario.h"
#include "grafo/grafoNoDirigidoCompleto.h"
#include "tablaResultadosTSP/tablaResultadosTSP.h"
#include "TSP/voraz_tsp.h"
#include "TSP/fuerza_bruta_tsp.h"
#include "TSP/programacion_dinamica_tsp.h"
#include "controlTiempo/controlTiempo.h"

int main(int argc, char *argv[]) {
  try {
    ComprobarParametros::comprobar(argc, argv);  
  } catch (const std::string& kErrorParametros) {
    std::cout << "Error: " << kErrorParametros << "." << std::endl << std::endl;
    ComprobarParametros::ayuda();
    return EXIT_FAILURE;
  }
  try {
    const int kNumNodos = peticionUsuarioCantidadNodos();
    GeneradorInstanciasAleatorias::insertarFicheros(argv[1]);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 10);    
    do {
      GeneradorInstanciasAleatorias::generadorRand(kNumNodos, argv[1]);
    } while (dis(gen) != 0);
    const std::set<std::string> kConjuntoNombresFichero = GeneradorInstanciasAleatorias::getFicherosRand();
    FuerzaBrutaTSP tsp1;
    ProgramacionDinamicaTSP tsp2;
    VorazTSP tsp3;
    std::pair<long double, long double> coste_y_tiempo_ejecucion_algoritmo;
    for (const auto& kCadaNombreFichero : kConjuntoNombresFichero) {
      TablaResultadosTSP::insertarDatoNombreFichero(kCadaNombreFichero);
      std::vector<std::pair<const long double, const long double>> fila_datos;
      GrafoNoDirigidoCompleto grafo(argv[1], kCadaNombreFichero);
      ControlTiempo::inicializarContador(argv[2]);
      //tsp1.ejecutar(grafo);
      //coste_y_tiempo_ejecucion_algoritmo.first = tsp1.getCoste();
      //coste_y_tiempo_ejecucion_algoritmo.second = tsp1.getTiempoEjecución();
      //fila_datos.push_back(coste_y_tiempo_ejecucion_algoritmo);
      //TablaResultadosTSP::insertarDatoNombreAlgoritmo("Fuerza Bruta");
      //ControlTiempo::inicializarContador(argv[2]);
      tsp2.ejecutar(grafo);
      tsp2.mostrarCaminoMinimo();
      coste_y_tiempo_ejecucion_algoritmo.first = tsp2.getCoste();
      coste_y_tiempo_ejecucion_algoritmo.second = tsp2.getTiempoEjecución();
      fila_datos.push_back(coste_y_tiempo_ejecucion_algoritmo);
      TablaResultadosTSP::insertarDatoNombreAlgoritmo("Programación Dinámica");
      ControlTiempo::inicializarContador(argv[2]);
      //tsp3.ejecutar(grafo);
      //coste_y_tiempo_ejecucion_algoritmo.first = tsp3.getCoste();
      //coste_y_tiempo_ejecucion_algoritmo.second = tsp3.getTiempoEjecución();
      //fila_datos.push_back(coste_y_tiempo_ejecucion_algoritmo);
      //TablaResultadosTSP::insertarDatoNombreAlgoritmo("Voraz");
      //TablaResultadosTSP::insertarFilaMatrizDatos(fila_datos);
    }
    const std::string kOpcion = peticionUsuarioTablaPantallaOFichero();
    if (kOpcion == "P") TablaResultadosTSP::mostrarTablaEnPantalla();
    else TablaResultadosTSP::mostrarTablaEnFichero();
  } catch (const std::string& kErrorEnGrafo) {
    std::cout << "Error: " << kErrorEnGrafo << "." << std::endl;
  }
  const std::string kOpcion = peticionUsuarioEliminarFicherosRand();
  GeneradorInstanciasAleatorias::eliminarFicherosRand(argv[1], kOpcion);
  return 0;
}