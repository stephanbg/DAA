#include "peticionesUsuario.h"

const int peticionUsuarioCantidadNodos() {
  std::cout << "¿Cuántos nodos quieres para las instancias aleatorias?: ";
  std::string num_nodos = "";
  while (std::cin >> num_nodos && !SintaxisFicheroGrafo::numeroNodosValido(num_nodos)) {
    std::cout << "El número de nodos no es válido, tiene que ser > 1: ";
  }
  return stoi(num_nodos);
}

const std::string peticionUsuarioEliminarFicherosRand() {
  std::cout << "Quieres eliminar los ficheros aleatorios? [S|N]: ";
  std::string opcion = "";
  while (std::cin >> opcion && (opcion != "S") && (opcion != "N")) {
    std::cout << "Tiene que elegir las opciones [S|N]: ";
  }
  return opcion;
}

const std::string peticionUsuarioTablaPantallaOFichero() {
  std::cout << "Quieres mostrar las tablas por pantalla o por fichero [P|F]: ";
  std::string opcion = "";
  while (std::cin >> opcion && opcion != "P" && opcion != "F") {
    std::cout << "Tiene que escribir [P|F]: ";
  }
  return opcion;
}