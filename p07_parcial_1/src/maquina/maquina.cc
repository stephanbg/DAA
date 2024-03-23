#include "maquina.h"

int Maquina::numero_maquinas_ = 0;

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