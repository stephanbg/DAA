/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 6 de Marzo de 2024
 * @file problema-vector-pilas.cc
 * @brief Implementación de la clase ProblemaVectorPilas, que representa
 * cualquier problema vectorial con pilas, clase hija de la clase abstracta Problema
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p05/src}
 * @see {@link https://docs.google.com/document/d/1pwPk5iI5dRHo8M-raauPP5mgCUHy9m9j_au3UDkn_Rc/edit}
 */

#include "problema-vector-pilas.h"

/**
 * @brief Constructor de ProblemaVectorPilas que inicializa el número de pilas
 * y opcionalmente genera datos aleatorios para la primera pila.
 * @param kCantidadPilas Número de pilas.
 * @param kRandomDatosPila0 Indica si se deben generar datos aleatorios para la primera pila.
 */
ProblemaVectorPilas::ProblemaVectorPilas(const int kCantidadPilas, const bool kRandomDatosPila0) {
  pilas_.resize(kCantidadPilas);
  if (kRandomDatosPila0) generadorInstanciaAleatoria();
}

/**
 * @brief Constructor de ProblemaVectorPilas que inicializa el número de pilas,
 * y opcionalmente genera datos aleatorios para la primera pila con un tamaño dado.
 * @param kCantidadPilas Número de pilas.
 * @param kCantidadElementosPila0 Tamaño de la primera pila.
 * @param kRandomDatosPila0 Indica si se deben generar datos aleatorios para la primera pila.
 */
ProblemaVectorPilas::ProblemaVectorPilas(const int kCantidadPilas, const int kCantidadElementosPila0,
    const bool kRandomDatosPila0) {
  pilas_.resize(kCantidadPilas);
  if (kRandomDatosPila0) generadorInstanciaAleatoriaSizeFijo(kCantidadElementosPila0);
}

/**
 * @brief Muestra el problema de las pilas, solamente si no están vacías.
 */
void ProblemaVectorPilas::mostrarProblema() const {
  const int kSize = pilas_.size();
  std::stack<int> cada_pila;
  for (int i = 0; i < kSize; ++i) {
    if (!pilas_[i].empty()) std::cout << "PILA " << i + 1 << ":\n";
    cada_pila = pilas_[i];
    while (!cada_pila.empty()) {
      int pila_top = cada_pila.top();
      std::cout << pila_top << std::endl;
      cada_pila.pop();
    }
    if (!pilas_[i].empty()) std::cout << std::endl;
  }
}

/**
 * @brief Inserta valores en una pila específica.
 * @param kPosPila Posición de la pila en la que se insertarán los valores.
 * @param kValores Vector de valores a insertar en la pila.
 */
void ProblemaVectorPilas::meterValores(const int kPosPila, const std::vector<int>& kValores) {
  const int kSize = kValores.size();
  for (int i = 0; i < kSize; ++i) {
    pilas_[kPosPila].push(kValores[i]);
  }
}

/**
 * @brief Genera una instancia aleatoria para la primera pila.
 * De tamaño inferior a 5
 */
void ProblemaVectorPilas::generadorInstanciaAleatoria() {
  const int kSizeInstancia = rand() % 5 + 1;
  std::vector<int> pilaOrigen;
  for (int pos = 0; pos < kSizeInstancia; ++pos) {
    pilaOrigen.push_back(rand() % 1000 + 1);
  }
  std::sort(pilaOrigen.begin(), pilaOrigen.end());
  for (const auto& elemento : pilaOrigen) {
    pilas_[0].push(elemento);
  }
}

/**
 * @brief Genera una instancia aleatoria para la primera pila con un tamaño fijo.
 * @param kCantidadElementosPila0 Tamaño de la primera pila.
 */
void ProblemaVectorPilas::generadorInstanciaAleatoriaSizeFijo(const int kCantidadElementosPila0) {
  std::vector<int> pilaOrigen;
  for (int pos = 0; pos < kCantidadElementosPila0; ++pos) {
    pilaOrigen.push_back(rand() % 1000 + 1);
  }
  std::sort(pilaOrigen.begin(), pilaOrigen.end());
  for (const auto& elemento : pilaOrigen) {
    pilas_[0].push(elemento);
  }
}

/**
 * @brief Solicita al usuario la cantidad de pilas que desea y devuelve el valor ingresado.
 * @return Cantidad de pilas deseada por el usuario.
 */
const int ProblemaVectorPilas::cantidadPilas() {
  std::cout << "Dime la cantidad de Pilas que desea: ";
  std::string numero;
  while (std::cin >> numero) {
    if (contieneSoloDigitos(numero) && numero >= "3") break;
    std::cout << "Tienen que ser mínimo 3 pilas." << std::endl;
    std::cout << "Que número de pilas desea: ";
  }
  return stoi(numero);
} 