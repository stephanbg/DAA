#include "peticionesUsuario.h"

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

const int cuantosElementosParaSolucion(const std::string& kNombreFichero) {
  std::ifstream archivo(kNombreFichero);
  int numero_maximo_posible, cantidad;
  archivo >> numero_maximo_posible;
  archivo.close();
  std::cout <<
      "¿Cuántos elementos quieres ingresar para la solución? (num > 0 y num <= " << numero_maximo_posible << "): ";
  do {
    std::string input;
    std::getline(std::cin, input);
    if (input.empty()) return numero_maximo_posible;
    std::stringstream ss(input);
    if (!(ss >> cantidad)) std::cout << "Por favor, introduce un número válido: ";
    else if (cantidad < 1 || cantidad > numero_maximo_posible) {
      std::cout << "Por favor, introduce un número > 0 y <= " << numero_maximo_posible << ": ";
    } else return cantidad;
  } while (true);
}

/**
 * @brief Pregunta al usuario si desea mostrar las tablas por pantalla o por fichero.
 * 
 * @return La respuesta del usuario (P para pantalla, F para fichero).
 */
const std::string peticionUsuarioTablaPantallaOFichero() {
  std::cout << "Quieres mostrar las tablas por pantalla o por fichero [P|F]: ";
  std::string opcion = "";
  while (std::cin >> opcion && opcion != "P" && opcion != "F") {
    std::cout << "Tiene que escribir [P|F]: ";
  }
  return opcion;
}