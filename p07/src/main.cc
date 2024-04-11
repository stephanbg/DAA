/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 1 de Abril de 2024
 * @file main.cc
 * @brief Función principal que se encargará de implementar
 * Parallel Machine Scheduling Problem with Dependent Setup Times
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07/src}
 */

#include "comprobar_parametros/comprobar_parametros.h"
#include "sintaxis_fichero/sintaxis_fichero.h"
#include "problema/problema.h"
#include "solucion/solucion.h"
#include "algoritmos_min_TCT/algoritmos_min_TCT.h"
#include "algoritmos_min_TCT/voraz/algoritmo_constructivo_voraz_TCT.h"
#include "algoritmos_min_TCT/GRASP/algoritmo_GRASP_TCT.h"
#include "algoritmos_min_TCT/GRASP/busquedaLocal/movimientoReInsercionInterGRASP.h"
#include "algoritmos_min_TCT/GRASP/busquedaLocal/movimientoReInsercionIntraGRASP.h"
#include "algoritmos_min_TCT/GRASP/busquedaLocal/movimientoSwapInterGRASP.h"
#include "algoritmos_min_TCT/GRASP/busquedaLocal/movimientoSwapIntraGRASP.h"
#include "algoritmos_min_TCT/MultiArranqueGVNS/multiArranqueGVNS.h"
#include "ejecutar_algoritmos/ejecutar_algoritmos.h"
#include "controlador_tiempo/controlador_tiempo.h"
#include "tabla/tabla.h"
#include "peticionesUsuario/peticionesUsuario.h"

/**
 * @brief Función principal del programa.
 * 
 * @param argc Cantidad de argumentos de la línea de comandos.
 * @param argv Vector de argumentos de la línea de comandos.
 * @return Devuelve EXIT_SUCCESS si el programa se ejecuta correctamente, EXIT_FAILURE en caso contrario.
 */
int main(int argc, char* argv[]) {
  try {
    ComprobarParametros::comprobar(argc, argv);
    SintaxisFichero::comprobarSintaxisFichero(argv[1]);
    Problema grafo(argv[1]);
    int numero_maquinas = Solucion::cuantasMaquinasACrear(argv[1]);
    MultiArranqueGVNS GVNS;
    GVNS.ejecutar(numero_maquinas, grafo);
    /*
    Tabla::insertarDatosIniciales(argv[1], grafo.getGrafo().size() - 1, numero_maquinas);
    AlgoritmoMinimizarTCT* algoritmo;
    // Se define un mapa que asocia nombres de algoritmos con funciones para crear instancias
    std::map<std::string, std::function<AlgoritmoMinimizarTCT*()>> constructores = {
      {"VORAZ", [](){ return new AlgoritmoConstructivoVoraz; }},
      {"Mov. ReInsercionInter", [](){ return new MovimientoReInsercionInterGRASP; }},
      {"Mov. ReInsercionIntra", [](){ return new MovimientoReInsercionIntraGRASP; }},
      {"Mov. SwapInter", [](){ return new MovimientoSwapInterGRASP; }},
      {"Mov. SwapIntra", [](){ return new MovimientoSwapIntraGRASP; }}
    };
    const std::vector<std::string> kOrdenAlgoritmos = {
      "VORAZ", "Mov. ReInsercionInter", "Mov. ReInsercionIntra", "Mov. SwapInter", "Mov. SwapIntra"
    };
    // Itera sobre los nombres de algoritmos y crea instancias dinámicamente
    for (const auto& kNombre : kOrdenAlgoritmos) {
      algoritmo = constructores[kNombre]();
      auto resultado = ejecutarAlgoritmo(algoritmo, numero_maquinas, grafo);
      Tabla::insertarDatos(kNombre, resultado.second);
    }       
    const std::string kOpcion = peticionUsuarioTablaPantallaOFichero();
    if (kOpcion == "P") Tabla::mostrarTablaEnPantalla();
    else Tabla::mostrarTablaEnFichero();*/
  } catch (const std::string& kError) {
    std::cout << "Error: " << kError << "." << std::endl << std::endl;
    ComprobarParametros::ayuda();
    return EXIT_FAILURE;
  }
  return 0;
}