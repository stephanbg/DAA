/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 27 de Febrero de 2024
 * @file tablaAlgoritmos.cc
 * @brief Implementación de la clase TablaAlgoritmos
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p04/src}
 * @see {@link https://docs.google.com/document/d/1CcrG-85_oTdAkTo-zgXkudKT8C8z7T7m2hUHVLGUReQ/edit#heading=h.5bq8rsdy1ujx}
 */

#include "tablaAlgoritmos.h"

/**
 * @brief Imprime el encabezado de la tabla junto
 * con los tiempos de ejecución de los algoritmos para
 * cada tamaño de instancia.
 */
void TablaAlgoritmos::imprimirTabla() const {
  // Imprimir encabezado de la tabla
  for (int i = 0; i < sizeInstancias_.size(); ++i) {
    std::cout << "\nTamaño instancia: " << sizeInstancias_[i] << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    for (int j = 0; j < tiempoAlgoritmos_[i].size(); ++j) {
      std::cout << nombresAlgoritmos_[i][j] << ": " << tiempoAlgoritmos_[i][j] << " µs" << std::endl;
      std::cout << "MAX NIVEL RECURSIVIDAD: " << maximoNivelesRecursividad_[i][j] << std::endl;       
      if (j < tiempoAlgoritmos_[i].size() - 1) std::cout << std::endl;
    }
    std::cout << std::endl;
  }
}

/**
 * @brief Escribe la tabla en un archivo de texto, incluyendo el encabezado y los
 * tiempos de ejecución de los algoritmos para cada tamaño de instancia.
 */
void TablaAlgoritmos::meterEnFicheroTabla() const {
  std::ofstream archivo("tablaAlgoritmos.txt", std::ios::app);
  for (int i = 0; i < sizeInstancias_.size(); ++i) {
    archivo << "Tamaño instancia: " << sizeInstancias_[i] << std::endl;
    archivo << "------------------------------------------" << std::endl;
    for (int j = 0; j < tiempoAlgoritmos_[i].size(); ++j) {
      archivo << nombresAlgoritmos_[i][j] << ": " << tiempoAlgoritmos_[i][j] << " µs" << std::endl;
      archivo << "MAX NIVEL RECURSIVIDAD: " << maximoNivelesRecursividad_[i][j] << std::endl;       
      if (j < tiempoAlgoritmos_[i].size() - 1) archivo << std::endl;
    }
    archivo << std::endl << std::endl;
  }
  archivo.close(); 
}

/**
 * @brief Pregunta al usuario si desea mostrar la tabla
 * por pantalla o guardarla en un fichero, y luego
 * realiza la acción correspondiente.
 */
void TablaAlgoritmos::peticionUsuario() const {
  std::cout << "Quieres mostrar las tablas por pantalla o por fichero [P|F]: ";
  std::string opcion = "";
  while (std::cin >> opcion && opcion != "P" && opcion != "F") {
    std::cout << "Tiene que escribir [P|F]: ";
  }
  if (opcion == "P") imprimirTabla();
  else meterEnFicheroTabla();
}