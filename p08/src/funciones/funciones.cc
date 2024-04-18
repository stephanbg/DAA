#include "funciones.h"

std::vector<std::string> extraerFicherosEjemplo(const std::string& kNombreDir) {
  std::vector<std::string> nombres_ficheros;
  int num_ficheros = 0;
  const int kCantidadFicherosPedidosPorUsr = cuantosFicherosAEjecutar(kNombreDir);
  for (const auto& kEntrada : fs::directory_iterator(kNombreDir)) {
    if (kEntrada.is_regular_file()) {
      nombres_ficheros.push_back(kEntrada.path().filename().string());
      if (++num_ficheros == kCantidadFicherosPedidosPorUsr) break;
    }
  }
  std::sort(nombres_ficheros.begin(), nombres_ficheros.end());
  return nombres_ficheros;
}

const int cuantosFicherosAEjecutar(const std::string& kNombreDir) {
  const int kNumMaximoFicheros = cantidadMaximaFicheros(kNombreDir);
  int cantidad;
  std::cout << "¿Cuántos ficheros quieres ejecutar? ";
  do {
    std::string input;
    std::getline(std::cin, input);
    if (input.empty()) return cantidadMaximaFicheros(kNombreDir);
    std::stringstream ss(input);
    if (!(ss >> cantidad)) std::cout << "Por favor, introduce un número válido: ";
    else if (cantidad < 1) std::cout << "Por favor, introduce un número mayor que 0: ";
    else {
      if (cantidad > kNumMaximoFicheros) {
        std::cout << "El número debe ser como máximo " << kNumMaximoFicheros << ": ";
      } else return cantidad;
    }
  } while (true);
}

const int cantidadMaximaFicheros(const std::string& kNombreDir) {
  int num_ficheros = 0;
  for (const auto& kEntrada : fs::directory_iterator(kNombreDir)) {
    if (kEntrada.is_regular_file()) ++num_ficheros;
  }
  return num_ficheros;
}