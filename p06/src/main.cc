/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Marzo de 2024
 * @file main.cc
 * @brief Práctica 6, Algoritmos de Divide y Vencerás
 * Realizar los algoritmos Voraz, Fuerza Bruta y Programación dinámica
 * para el problema del TSP 
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p06/src}
 * @see {@link https://docs.google.com/document/d/1a691HPtHQL4qBtI2qaTMTp23wxZvU8-CCIbGOyNJRQo/edit}
 */

#include <set>
#include <string>
#include <random>

#include "comprobar_parametros/comprobar_parametros.h"
#include "generador_instancias_aleatorias/generador_instancias_aleatorias.h"
#include "funciones/peticionesUsuario.h"
#include "grafo/grafoNoDirigidoCompleto.h"
#include "tablaResultadosTSP/tablaResultadosTSP.h"
#include "TSP/tsp.h"
#include "TSP/voraz_tsp.h"
#include "TSP/fuerza_bruta_tsp.h"
#include "TSP/programacion_dinamica_tsp.h"
#include "controlTiempo/controlTiempo.h"

/**
 * @brief Función principal que ejecuta el algoritmo del Viajante de Comercio.
 * 
 * Esta función principal se encarga de ejecutar el algoritmo del Viajante de Comercio
 * utilizando diferentes enfoques (Fuerza Bruta, Programación Dinámica y Voraz) para
 * resolver instancias aleatorias de grafos completos no dirigidos. También recopila los
 * resultados y los muestra en una tabla en pantalla o los guarda en un archivo, según la
 * elección del usuario.
 * 
 * @param argc Cantidad de argumentos de la línea de comandos.
 * @param argv Argumentos de la línea de comandos.
 * @return Código de salida del programa.
 */
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
    std::uniform_int_distribution<> dis(0, 1);
    // Genera los ficheros 
    do {
      GeneradorInstanciasAleatorias::generadorRand(kNumNodos, argv[1]);
    } while (dis(gen) != 0);
    const std::set<std::string> kConjuntoNombresFichero = GeneradorInstanciasAleatorias::getFicherosRand();
    std::pair<long double, long double> coste_y_tiempo_ejecucion_algoritmo;
    long double media_fuerza_bruta = 0, media_voraz = 0, media_programacion_dinamica = 0;
    int contador = 0;
    const int kConversion10MinMicro = 600000000;
    // Recorre los nombres de los ficheros
    for (const auto& kCadaNombreFichero : kConjuntoNombresFichero) {
      TSP* tsp = new FuerzaBrutaTSP;      
      TablaResultadosTSP::insertarDatoNombreFichero(kCadaNombreFichero);
      std::vector<std::pair<const long double, const long double>> fila_datos;
      GrafoNoDirigidoCompleto grafo(argv[1], kCadaNombreFichero);
      ControlTiempo::inicializarContador(argv[2]);
      tsp->ejecutar(grafo);
      coste_y_tiempo_ejecucion_algoritmo.first = tsp->getCoste();
      coste_y_tiempo_ejecucion_algoritmo.second = tsp->getTiempoEjecución();
      if (coste_y_tiempo_ejecucion_algoritmo.second == -1) {
        media_fuerza_bruta += kConversion10MinMicro;
      } else media_fuerza_bruta += coste_y_tiempo_ejecucion_algoritmo.second;
      fila_datos.push_back(coste_y_tiempo_ejecucion_algoritmo);
      TablaResultadosTSP::insertarDatoNombreAlgoritmo("Fuerza Bruta");
      TablaResultadosTSP::insertarFilaMatrizCaminosMinimos(tsp->getCaminoMinimo());
      ControlTiempo::inicializarContador(argv[2]);
      tsp = new ProgramacionDinamicaTSP;      
      tsp->ejecutar(grafo);   
      coste_y_tiempo_ejecucion_algoritmo.first = tsp->getCoste();
      coste_y_tiempo_ejecucion_algoritmo.second = tsp->getTiempoEjecución();
      if (coste_y_tiempo_ejecucion_algoritmo.second == -1) {
        media_programacion_dinamica += kConversion10MinMicro;
      } else media_programacion_dinamica += coste_y_tiempo_ejecucion_algoritmo.second;      
      fila_datos.push_back(coste_y_tiempo_ejecucion_algoritmo);
      TablaResultadosTSP::insertarDatoNombreAlgoritmo("Programación Dinámica");
      TablaResultadosTSP::insertarFilaMatrizCaminosMinimos(tsp->getCaminoMinimo());
      ControlTiempo::inicializarContador(argv[2]);
      tsp = new VorazTSP;      
      tsp->ejecutar(grafo);   
      coste_y_tiempo_ejecucion_algoritmo.first = tsp->getCoste();
      coste_y_tiempo_ejecucion_algoritmo.second = tsp->getTiempoEjecución();
      if (coste_y_tiempo_ejecucion_algoritmo.second == -1) {
        media_voraz += kConversion10MinMicro;
      } else media_voraz += coste_y_tiempo_ejecucion_algoritmo.second;      
      fila_datos.push_back(coste_y_tiempo_ejecucion_algoritmo);
      TablaResultadosTSP::insertarDatoNombreAlgoritmo("Voraz");
      TablaResultadosTSP::insertarFilaMatrizCaminosMinimos(tsp->getCaminoMinimo());
      TablaResultadosTSP::insertarFilaMatrizDatos(fila_datos);
      contador++;
    }
    media_fuerza_bruta = (double) (media_fuerza_bruta / contador);
    media_programacion_dinamica = (double) (media_programacion_dinamica / contador);
    media_voraz = (double) (media_voraz / contador);
    TablaResultadosTSP::insertarMediaTiempos(media_fuerza_bruta);
    TablaResultadosTSP::insertarMediaTiempos(media_programacion_dinamica);
    TablaResultadosTSP::insertarMediaTiempos(media_voraz);
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