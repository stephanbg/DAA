/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 19 de Abril de 2024
 * @file main.cc
 * @brief Implementación del programa principal que ejecuta algoritmos para resolver Maximum diversity problem.
 * Este programa procesa una serie de archivos que contienen descripciones de problemas y ejecuta algoritmos para
 * resolverlos. Luego, muestra los resultados en una tabla.
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p08/src}
 */

#include <map>
#include <functional> 

#include "ejecutar_algoritmos/ejecutar_algoritmos.h"
#include "algoritmosDiversidadMaxima/algoritmosDiversidadMaxima.h"
#include "algoritmos/voraz/voraz.h"
#include "algoritmos/GRASP/GRASP.h"
#include "algoritmos/busquedaTabu/busquedaTabu.h"
#include "algoritmos/ramificacionYPoda/ramificacionYPodaProfundidad.h"
#include "algoritmos/ramificacionYPoda/ramificacionYPodaAmplitud.h"
#include "problema/problema.h"
#include "tabla/tabla.h"
#include "funciones/funciones.h"
#include "comprobar_parametros/comprobar_parametros.h"
#include "sintaxis_fichero/sintaxis_fichero.h"

/**
 * @brief Función principal del programa.
 * 
 * @param argc Cantidad de argumentos de la línea de comandos.
 * @param argv Vector de argumentos de la línea de comandos.
 * @return Devuelve 0 si el programa se ejecuta correctamente, o un código de error si hay algún problema.
 */
int main(int argc, char* argv[]) {
  try {
    ComprobarParametros::comprobar(argc, argv);
    AlgoritmosDiversidadMaxima* algoritmo;
    // Se define un mapa que asocia nombres de algoritmos con funciones para crear instancias
    std::map<std::string, std::function<AlgoritmosDiversidadMaxima*()>> constructores = {
      {"VORAZ", [](){ return new Voraz; }},
      {"GRASP", [](){ return new GRASP; }},
      {"BusquedaTabu", [](){ return new BusquedaTabu; }},
      {"RamificacionYPodaProf.", [](){ return new RamificacionYPodaProfundidad; }},
      {"RamificacionYPodaAmpl.", [](){ return new RamificacionYPodaAmplitud; }}
    };
    const std::vector<std::string> kOrdenAlgoritmos = {
      "VORAZ", "GRASP", "BusquedaTabu", "RamificacionYPodaProf.", "RamificacionYPodaAmpl."
    };
    const std::vector<std::string> kNombreFicheros = extraerFicherosEjemplo(argv[1]);
    for (const auto& kNombreFichero : kNombreFicheros) {
      SintaxisFichero::comprobarSintaxisFichero(kNombreFichero);
      Problema problema(kNombreFichero);
      const std::vector<std::vector<double>>& kCoordenadas = problema.getCoordenadas().getMatriz();
      const int kNumElementosEnSolucion = cuantosElementosParaSolucion(kNombreFichero);
      const std::string kNombreFicheroReal = extraerNombreFicheroDeRuta(kNombreFichero);
      for (const auto& kNombre : kOrdenAlgoritmos) {
        algoritmo = constructores[kNombre]();
        auto resultado = ejecutarAlgoritmo(algoritmo, problema, kNumElementosEnSolucion);
        Tabla::insertarDatosIniciales(
          kNombreFicheroReal,
          kCoordenadas.size(),
          kCoordenadas[0].size(),
          kNumElementosEnSolucion
        );        
        Tabla::insertarDatos(kNombre, resultado);
      }
    }
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