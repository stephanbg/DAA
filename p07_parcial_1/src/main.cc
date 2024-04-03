/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 20 de Marzo de 2024
 * @file main.cc
 * @brief Función principal que se encargará de implementar
 * Parallel Machine Scheduling Problem with Dependent Setup Times
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p07_parcial_1/src}
 */

#include "comprobar_parametros/comprobar_parametros.h"
#include "sintaxis_fichero/sintaxis_fichero.h"
#include "problema/problema.h"
#include "solucion/solucion.h"
#include "algoritmos_min_TCT/algoritmos_min_TCT.h"
#include "algoritmos_min_TCT/voraz/algoritmo_constructivo_voraz_TCT.h"
#include "algoritmos_min_TCT/GRASP/algoritmo_GRASP_TCT.h"
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
    Tabla tabla;
    tabla.insertarNombreFichero(argv[1]);
    tabla.insertarNumeroNodos(grafo.getGrafo().size() - 1);
    tabla.insertarNumeroMaquinas(numero_maquinas);    
    tabla.insertarNombreAlgoritmo("VORAZ");
    AlgoritmoMinimizarTCT* algoritmo = new AlgoritmoConstructivoVoraz;
    // Crear un objeto ControladorTiempo con una función lambda como argumento
    ControladorTiempo<std::vector<Solucion>, int, Problema&> tiempo1(
      [&](int numeroMaquinas, Problema& grafo) {
        return algoritmo->ejecutar(numeroMaquinas, grafo);
      }
    );
    std::vector<Solucion> maquinas = tiempo1.medirTiempoFuncion(std::move(numero_maquinas), grafo);
    tabla.insertarFuncionObjetivo(Solucion::getFuncionObjetivo());
    tabla.insertarTiempo(tiempo1.getDuracion());
    tabla.insertarNombreAlgoritmo("GRASP");
    algoritmo = new AlgoritmoGRASP;
    // Crear un objeto ControladorTiempo con una función lambda como argumento
    ControladorTiempo<std::vector<Solucion>, int, Problema&> tiempo2(
      [&](int numeroMaquinas, Problema& grafo) {
        return algoritmo->ejecutar(numeroMaquinas, grafo);
      }
    );
    maquinas = tiempo2.medirTiempoFuncion(std::move(numero_maquinas), grafo); 
    tabla.insertarFuncionObjetivo(Solucion::getFuncionObjetivo());
    tabla.insertarTiempo(tiempo2.getDuracion());
    const std::string kOpcion = peticionUsuarioTablaPantallaOFichero();
    if (kOpcion == "P") Tabla::mostrarTablaEnPantalla();
    else Tabla::mostrarTablaEnFichero();
  } catch (const std::string& kError) {
    std::cout << "Error: " << kError << "." << std::endl << std::endl;
    ComprobarParametros::ayuda();
    return EXIT_FAILURE;
  }
  return 0;
}