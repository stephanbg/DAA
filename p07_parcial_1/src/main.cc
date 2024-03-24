#include "comprobar_parametros/comprobar_parametros.h"
#include "sintaxis_fichero_grafo/sintaxis_fichero_grafo.h"
#include "grafo/grafoDirigidoCompleto.h"
#include "maquina/maquina.h"
#include "algoritmos_min_TCT/algoritmos_min_TCT.h"
#include "algoritmos_min_TCT/voraz/algoritmo_constructivo_voraz_TCT.h"
#include "algoritmos_min_TCT/GRASP/algoritmo_GRASP_TCT.h"

int main(int argc, char* argv[]) {
  try {
    ComprobarParametros::comprobar(argc, argv);
    SintaxisFicheroGrafo::comprobarSintaxisFichero(argv[1]);
    GrafoDirigidoCompleto grafo(argv[1]);
    std::cout << grafo << std::endl;
    Maquina::cuantasMaquinasACrear(argv[1]);
    std::cout << "ALGORITMO CONSTRUCTIVO VORAZ: " << std::endl;
    std::cout << "-----------------------------" << std::endl;
    AlgoritmoMinimizarTCT* algoritmo = new AlgoritmoConstructivoVoraz;
    std::vector<Maquina> maquinas = algoritmo->ejecutar(Maquina::getNumeroMaquinas(), grafo);
    Maquina::mostrarTareasDeTodasLasMaquinas();
    std::cout << std::endl;
    Maquina::limpiarTareasDeTodasLasMaquinas();
    std::cout << "ALGORITMO GRASP: " << std::endl;
    std::cout << "----------------" << std::endl;    
    algoritmo = new AlgoritmoGRASP;
    maquinas = algoritmo->ejecutar(Maquina::getNumeroMaquinas(), grafo);
    Maquina::mostrarTareasDeTodasLasMaquinas();
    std::cout << std::endl;
    Maquina::limpiarTareasDeTodasLasMaquinas();
  } catch (const std::string& kError) {
    std::cout << "Error: " << kError << "." << std::endl;
    return EXIT_FAILURE;
  }
  return 0;
}