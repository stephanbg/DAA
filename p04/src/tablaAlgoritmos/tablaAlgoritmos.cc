#include "tablaAlgoritmos.h"

void TablaAlgoritmos::imprimirTabla() const {
  // Imprimir encabezado de la tabla
  for (int i = 0; i < sizeInstancias_.size(); ++i) {
    std::cout << "\nTamaño instancia: " << sizeInstancias_[i] << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    for (int j = 0; j < tiempoAlgoritmos_[i].size(); ++j) {
      std::cout << nombresAlgoritmos_[i][j] << ": " << tiempoAlgoritmos_[i][j] << " µs";
      if (j < tiempoAlgoritmos_[i].size() - 1) std::cout << std::endl;
    }
    std::cout << std::endl;
  }
}

void TablaAlgoritmos::meterEnFicheroTabla() const {

}

void TablaAlgoritmos::peticionUsuario() const {
  std::cout << "Quieres mostrar las tablas por pantalla o por fichero [P|F]: ";
  std::string opcion = "";
  while (std::cin >> opcion && opcion != "P" && opcion != "F") {
    std::cout << "Tiene que escribir [P|F]: ";
  }
  if (opcion == "P") imprimirTabla();
  else meterEnFicheroTabla();
}