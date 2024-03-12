/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 6 de Marzo de 2024
 * @file debug.h
 * @brief Definición de la clase Debug, que servirá
 * de clase base abstracta para los diferentes modos debug que hayan
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p05/src}
 * @see {@link https://docs.google.com/document/d/1pwPk5iI5dRHo8M-raauPP5mgCUHy9m9j_au3UDkn_Rc/edit}
 */

#include "debug.h"
#include "modoDepurador.h"
#include "modoNormal.h"

/**
 * @brief Función para crear un objeto de tipo Debug dependiendo del modo seleccionado.
 * @return Puntero al objeto Debug creado.
 */
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

/**
 * @brief Función para solicitar al usuario la elección de un algoritmo.
 * @return Cadena que representa la elección del algoritmo.
 */
const std::string Debug::eleccionDeAlgoritmo() const {
  std::cout << "Elija el algoritmo que desea ejecutar:\n";
  std::cout << "MergeSort: [1]" << std::endl;
  std::cout << "QuickSort: [2]" << std::endl;
  std::cout << "BusquedaBinaria: [3]" << std::endl;
  std::cout << "Hanoi: [4]" << std::endl;
  std::cout << "Strassen: [5]" << std::endl;
  std::cout << "Fibonacci: [6]" << std::endl;
  std::string eleccion = "";
  while (std::cin >> eleccion &&
         eleccion != "1" &&
         eleccion != "2" &&
         eleccion != "3" &&
         eleccion != "4" &&
         eleccion != "5" &&
         eleccion != "6") {
    std::cout << "\nNo es una opción permitida" << std::endl << std::endl;
    std::cout << "MergeSort: [1]" << std::endl;
    std::cout << "QuickSort: [2]" << std::endl;
    std::cout << "BinarySort: [3]" << std::endl;
    std::cout << "Hanoi: [4]" << std::endl;
    std::cout << "Strassen: [5]" << std::endl;
    std::cout << "Fibonacci: [6]" << std::endl;
    std::cout << "Elija el algoritmo que desea ejecutar:\n";
  }
  return eleccion; 
}