#include "grafo/grafoDirigidoCompleto.h"
#include "maquina/maquina.h"
#include "sintaxis_fichero_grafo/sintaxis_fichero_grafo.h"
#include "algoritmos_min_TCT/algoritmos_min_TCT.h"
#include "algoritmos_min_TCT/algoritmo_constructivo_voraz_TCT.h"

int main(int argc, char* argv[]) {
  try {
    SintaxisFicheroGrafo::comprobarSintaxisFichero(argv[1]);
    GrafoDirigidoCompleto grafo(argv[1]);
    Maquina::cuantasMaquinasACrear(argv[1]);
    AlgoritmoMinimizarTCT* voraz = new AlgoritmoConstructivoVoraz;
    //std::cout << grafo << std::endl;
    std::vector<Maquina> maquinas = voraz->ejecutar(Maquina::getNumeroMaquinas(), grafo);
    for (auto a : maquinas) {
      std::cout << "MAQUINA: ";
      for (auto b : a.getTareas()) {
        std::cout << b->getId() << std::endl;
      }      
    }
  } catch (const std::string& kErrorGrafo) {
    std::cout << "Error: " << kErrorGrafo << "." << std::endl;
    return EXIT_FAILURE;
  }
  return 0;
}