/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file estrategia_almacenamiento_unico.cc
 * @brief Implementación de la clase EstrategiaUnicoEspacio derivada de
 *        EstrategiaAlmacenamiento, utilizada para poder almacenar y obtener datos
 *        de los registros de la memoria de datos, pero cuando solo hay una única columna. 
 * 
 * @see {@link https://docs.google.com/document/d/1zf_w2HtS4zJX3iqr9yPm6f7rRNsrBxL7afCsMapujMQ/edit#heading=h.5bq8rsdy1ujx}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p03}
 */

#include "estrategia_almacenamiento_unico.h"

/**
 * @brief Almacena datos en un vector bidimensional, donde cada fila contiene solo un elemento.
 * 
 * @param registros El vector bidimensional donde se almacenarán los datos.
 * @param kDato El dato que se almacenará.
 * @param kIndiceFila El índice de la fila donde se almacenará el dato.
 * @param kIndiceColumna El índice de la columna donde se almacenará el dato (por defecto: 0).
 */
void EstrategiaUnicoEspacio::almacenarDato(std::vector<std::vector<long double>>& registros, const long double kDato,
                                           const int kIndiceFila, const int kIndiceColumna) const {
  registros[kIndiceFila][0] = kDato;
}

/**
 * @brief Obtiene datos de un vector bidimensional, considerando que cada fila contiene solo un elemento.
 * 
 * @param kRegistros El vector bidimensional del cual se obtendrán los datos.
 * @param kIndiceFila El índice de la fila de la cual se obtendrán los datos.
 * @param kIndiceColumna El índice de la columna de la cual se obtendrán los datos (por defecto: 0).
 * @return El dato obtenido.
 */
const long double EstrategiaUnicoEspacio::obtenerDato(const std::vector<std::vector<long double>>& kRegistros,
                                                      const int kIndiceFila, const int kIndiceColumna) const {
  return kRegistros[kIndiceFila][0];
}