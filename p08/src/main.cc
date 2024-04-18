#include <map>
#include <functional> 

#include "funciones/funciones.h"
#include "algoritmosDiversidadMaxima/algoritmosDiversidadMaxima.h"
#include "algoritmos/voraz/voraz.h"
#include "problema/problema.h"

int main(int argc, char* argv[]) {
  const std::vector<std::string> kNombreFicheros = extraerFicherosEjemplo(argv[1]);
  AlgoritmosDiversidadMaxima* algoritmo;
  // Se define un mapa que asocia nombres de algoritmos con funciones para crear instancias
  std::map<std::string, std::function<AlgoritmosDiversidadMaxima*()>> constructores = {
    {"VORAZ", [](){ return new Voraz; }}
  };
  const std::vector<std::string> kOrdenAlgoritmos = {
    "VORAZ"
  };
  for (const auto& kNombreFichero : kNombreFicheros) {
    Problema problema(kNombreFichero);
    for (const auto& kNombre : kOrdenAlgoritmos) {
      algoritmo = constructores[kNombre]();
      algoritmo->ejecutar(problema);
    } 
  }  
  return 0;
}