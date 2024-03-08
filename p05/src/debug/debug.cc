#include "debug.h"
#include "modoDepurador.h"
#include "modoNormal.h"

Debug* Debug::crearModo() {
  std::cout << "Bienvenido al modo elección de depuración:" << std::endl << std::endl;
  std::cout << "Modo Normal: [1]" << std::endl;
  std::cout << "Modo Depurador: [2]" << std::endl << std::endl;
  std::string opcion = "";
  std::cout << "Elija el modo: ";
  while (std::cin >> opcion && opcion != "1" && opcion != "2") {
    std::cout << "\nNo es una opción permitida" << std::endl << std::endl;
    std::cout << "Modo Normal: [1]" << std::endl;
    std::cout << "Modo Depurador: [2]" << std::endl << std::endl;
    std::cout << "Elija el modo: ";
  }
  switch (stoi(opcion)) {
    case 1:
      return new ModoNormal;
    case 2:
      return new ModoDepurador;
    default:
      std::cout << "Opción no válida. Seleccionando Modo Normal por defecto." << std::endl;
      return new ModoNormal;      
  }
}

const std::string Debug::eleccionDeAlgoritmo() const {
  std::cout << "Elija el algoritmo que desea ejecutar:\n";
  std::cout << "MergeSort: [1]" << std::endl;
  std::cout << "QuickSort: [2]" << std::endl;
  std::cout << "BinarySort: [3]" << std::endl;
  std::cout << "Hanoi: [4]" << std::endl;
  std::cout << "Strassen: [5]" << std::endl;
  std::string eleccion = "";
  while (std::cin >> eleccion &&
         eleccion != "1" &&
         eleccion != "2" &&
         eleccion != "3" &&
         eleccion != "4" &&
         eleccion != "5") {
    std::cout << "\nNo es una opción permitida" << std::endl << std::endl;
    std::cout << "MergeSort: [1]" << std::endl;
    std::cout << "QuickSort: [2]" << std::endl;
    std::cout << "BinarySort: [3]" << std::endl;
    std::cout << "Hanoi: [4]" << std::endl;
    std::cout << "Strassen: [5]" << std::endl;
    std::cout << "Elija el algoritmo que desea ejecutar:\n";
  }
  return eleccion; 
}