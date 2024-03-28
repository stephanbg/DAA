#include "maquina.h"

int Maquina::numero_maquinas_ = 0;
std::vector<Maquina*> Maquina::maquinas_ = {};

void Maquina::cuantasMaquinasACrear(const std::string& kNombreDirYFichero) {
  fs::path ruta_actual = fs::current_path();
  fs::path ruta_completa = ruta_actual / kNombreDirYFichero; 
  std::ifstream archivo(ruta_completa);
  std::string cada_linea = "";
  getline(archivo, cada_linea);
  getline(archivo, cada_linea);
  std::stringstream ss(cada_linea);
  std::string palabra = "";
  ss >> palabra; // Descartar La primera palabra
  ss >> palabra;
  numero_maquinas_ = stoi(palabra);
}

void Maquina::mostrarTareasDeTodasLasMaquinas() {
  for (int i = 0; i < numero_maquinas_; ++i) {
    std::cout << "Maquina " << i + 1 << " tiene asignadas las siguientes tareas: ";
    const auto& tareas = maquinas_[i]->getTareas();
    for (const auto& tarea : tareas) {
      std::cout << tarea->getId() << " ";
    }
    std::cout << std::endl;
  }
}

void Maquina::limpiarTareasDeTodasLasMaquinas() {
  for (auto& maquina : maquinas_) {
    maquina->limpiarTareas();
  }
}