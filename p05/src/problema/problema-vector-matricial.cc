/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 6 de Marzo de 2024
 * @file problema-vector-matricial.cc
 * @brief Implementación de la clase ProblemaVectorMatricial, que representa
 * cualquier problema vectorial de matrices, clase hija de la clase abstracta Problema
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p05/src}
 * @see {@link https://docs.google.com/document/d/1pwPk5iI5dRHo8M-raauPP5mgCUHy9m9j_au3UDkn_Rc/edit}
 */

#include "problema-vector-matricial.h"

/**
 * @brief Constructor que inicializa el tamaño del problema a uno dado
 * @param kCantidadMatrices Tamaño del problema
 */
ProblemaVectorMatricial::ProblemaVectorMatricial(const int kCantidadMatrices) { 
  problema_.resize(kCantidadMatrices);
}

/**
 * @brief Constructor que inicializa el tamaño del problema con un número dado
 * de matrices y las dimensiones de cada una. Además, se le puede pasar un parámetro
 * para inicializar matrices aleatorias.
 * @param kCantidadMatrices Número de matrices en el problema.
 * @param kFilasColumnas Vector de pares (filas, columnas) que indica las dimensiones de cada matriz.
 * @param kGeneradorInstanciasAleatroia Bool que si está en true se rellenan las matrices con datos aleatorios.
 */
ProblemaVectorMatricial::ProblemaVectorMatricial(const int kCantidadMatrices,
    const std::vector<std::pair<int, int>> kFilasColumnas,
    const bool kGeneradorInstanciasAleatroia) { 
  problema_.resize(kCantidadMatrices);
  for (int i = 0; i < kCantidadMatrices; ++i) {
    problema_[i].resize(kFilasColumnas[i].first, std::vector<int>(kFilasColumnas[i].second));
  }
  if (kGeneradorInstanciasAleatroia) generadorInstanciaAleatoriaSizeFijo();
}

/**
 * @brief Genera instancias aleatorias de matrices con tamaños fijos.
 */
void ProblemaVectorMatricial::generadorInstanciaAleatoriaSizeFijo() {
  for (auto& matriz : problema_) {
    for (auto& fila : matriz) {
      for (int& elemento : fila) {
        // Asignar un valor aleatorio entre 1 y 1000
        elemento = rand() % 10 + 1;
      }
    }
  }
}

/**
 * @brief Muestra cada matriz si no están vacías
 */
void ProblemaVectorMatricial::mostrarProblema() const {
  const int kSize = problema_.size();
  for (int i = 0; i < kSize; ++i) {
    if (problema_[i].empty()) continue;
    std::cout << "Matriz " << i + 1 << ":" << std::endl;
    const auto& matriz = problema_[i];
    for (const auto& fila : matriz) {
      for (const auto& elemento : fila) {
        std::cout << elemento << " ";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }
}

/**
 * @brief Inserta matrices en el problema.
 * @param kMatrices Matrices a insertar.
 */
void ProblemaVectorMatricial::meterValores(const std::vector<std::vector<std::vector<int>>>& kMatrices) {
  const int kSize = kMatrices.size();
  const int kSizeProblema = problema_.size();
  if (kSizeProblema == 0) problema_ = kMatrices;
  else if (kSizeProblema == kSize) { // Si los tamaños son iguales, simplemente copiamos las matrices
    for (int i = 0; i < kSize; ++i) {
      problema_[i] = kMatrices[i];
    }
  } else if (kSizeProblema < kSize) { // Si problema_ es más pequeño que kMatrices, copiamos las primeras matrices y agregamos las restantes
    //problema_ = kMatrices; 
    for (int i = 0; i < kSizeProblema; ++i) {
      problema_[i] = kMatrices[i];
    }
    for (int i = kSizeProblema; i < kSize; ++i) {
      problema_.push_back(kMatrices[i]);
    }
  } else { // Si problema_ es más grande que kMatrices, truncamos problema_ y copiamos las matrices
    for (int i = 0; i < kSize; ++i) {
      problema_[i] = kMatrices[i];
    }
    problema_.resize(kSize);
  }
}

/**
 * @brief Solicita al usuario la cantidad de matrices que desea y devuelve el valor ingresado.
 * @return Cantidad de matrices deseadas por el usuario.
 */
const int ProblemaVectorMatricial::cantidadMatrices() {
  std::cout << "Dime la cantidad de Matrices que desea (Necesitamos mínimo 2 si vamos a hacer operaciones): ";
  std::string numero;
  while (std::cin >> numero) {
    if (contieneSoloDigitos(numero) && numero >= "2") break;
    std::cout << "Tienen que ser mínimo 2 matrices." << std::endl;
    std::cout << "Que número de matrices desea: ";
  }
  return stoi(numero);
}

/**
 * @brief Solicita al usuario la cantidad de filas que desea y devuelve el valor ingresado.
 * @return Cantidad de filas deseadas por el usuario.
 */
const int ProblemaVectorMatricial::cantidadFilas() {
  std::cout << "Dime la cantidad de filas que desea: ";
  std::string numero;
  while (std::cin >> numero) {
    if (contieneSoloDigitos(numero) && numero >= "1") break;
    std::cout << "Tienen que ser mínimo 1 fila." << std::endl;
    std::cout << "Que número de filas desea: ";
  }
  return stoi(numero);
}

/**
 * @brief Solicita al usuario la cantidad de columnas que desea y devuelve el valor ingresado.
 * @return Cantidad de columnas deseadas por el usuario.
 */
const int ProblemaVectorMatricial::cantidadColumnas() {
  std::cout << "Dime la cantidad de columnas que desea: ";
  std::string numero;
  while (std::cin >> numero) {
    if (contieneSoloDigitos(numero) && numero >= "1") break;
    std::cout << "Tienen que ser mínimo 1 columna." << std::endl;
    std::cout << "Que número de columnas desea: ";
  }
  return stoi(numero);
}