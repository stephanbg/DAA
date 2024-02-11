/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file estrategia_almacenamiento_dinamico.cc
 * @brief Implementación de la clase EstrategiaVectorDinamico derivada de
 *        EstrategiaAlmacenamiento, utilizada para poder almacenar y obtener datos
 *        de los registros de la memoria de datos, pero cuando un registro puede almacenar
 *        varias columnas de datos. 
 * 
 * @see {@link https://docs.google.com/document/d/1n6iua2wSG2UVns-mTA4YdMBVKfKIazkJi4HRzKVKS78/edit}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p02}
 */

#include "estrategia_almacenamiento_dinamico.h"

/**
 * @brief Almacena un dato en un vector bidimensional con tamaño dinámico.
 * 
 * @param registros El vector bidimensional donde se almacenará el dato.
 * @param kDato El dato que se almacenará.
 * @param kIndiceFila El índice de la fila donde se almacenará el dato.
 * @param kIndiceColumna El índice de la columna donde se almacenará el dato.
 */
void EstrategiaVectorDinamico::almacenarDato(std::vector<std::vector<long double>>& registros, const long double kDato,
                                             const int kIndiceFila, const int kIndiceColumna) const {
  if (kIndiceColumna >= registros.size()) registros[kIndiceFila].resize(kIndiceColumna, 0);
  registros[kIndiceFila][kIndiceColumna] = kDato;
}

/**
 * @brief Obtiene un dato de un vector bidimensional con tamaño dinámico.
 * 
 * @param kRegistros El vector bidimensional del cual se obtendrá el dato.
 * @param kIndiceFila El índice de la fila de la cual se obtendrá el dato.
 * @param kIndiceColumna El índice de la columna de la cual se obtendrá el dato.
 * @throw Lanza una excepción si se quiere obtener un dato fuera del vector
 * @return El dato obtenido.
 */
const long double EstrategiaVectorDinamico::obtenerDato(const std::vector<std::vector<long double>>& kRegistros,
                                                        const int kIndiceFila, const int kIndiceColumna) const {
  if (kIndiceColumna >= kRegistros.size()) throw ("Rango fuera de Registro.");
  return kRegistros[kIndiceFila][kIndiceColumna];
}