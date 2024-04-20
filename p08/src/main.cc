#include <map>
#include <functional> 

#include "ejecutar_algoritmos/ejecutar_algoritmos.h"
#include "algoritmosDiversidadMaxima/algoritmosDiversidadMaxima.h"
#include "algoritmos/voraz/voraz.h"
#include "problema/problema.h"
#include "tabla/tabla.h"
#include "funciones/funciones.h"
#include "comprobar_parametros/comprobar_parametros.h"
#include "sintaxis_fichero/sintaxis_fichero.h"

int main(int argc, char* argv[]) {
  try {
    ComprobarParametros::comprobar(argc, argv);
    AlgoritmosDiversidadMaxima* algoritmo;
    // Se define un mapa que asocia nombres de algoritmos con funciones para crear instancias
    std::map<std::string, std::function<AlgoritmosDiversidadMaxima*()>> constructores = {
      {"VORAZ", [](){ return new Voraz; }}
    };
    const std::vector<std::string> kOrdenAlgoritmos = {
      "VORAZ"
    };
    const std::vector<std::string> kNombreFicheros = extraerFicherosEjemplo(argv[1]);
    for (const auto& kNombreFichero : kNombreFicheros) {
      SintaxisFichero::comprobarSintaxisFichero(kNombreFichero);
      Problema problema(kNombreFichero);
      const std::vector<std::vector<double>>& kCoordenadas = problema.getCoordenadas().getMatriz();
      const int kNumElementosEnSolucion = cuantosElementosParaSolucion(kNombreFichero);
      Tabla::insertarDatosIniciales(
        extraerNombreFicheroDeRuta(kNombreFichero),
        kCoordenadas.size(),
        kCoordenadas[0].size(),
        kNumElementosEnSolucion
      );
      for (const auto& kNombre : kOrdenAlgoritmos) {
        algoritmo = constructores[kNombre]();
        auto resultado = ejecutarAlgoritmo(algoritmo, problema, kNumElementosEnSolucion);
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