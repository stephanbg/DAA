/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 *
 * @author Stephan Brommer Gutiérrez
 * Correo: alu0101493497@ull.edu.es
 * @date 30/01/2024
 * @file main.cc
 * @brief Complejidad computacional
 *        Este programa genera dos matrices de manera random y genera la multiplicación
 *        de matrices con dos alogritmos, multiplicación por filas y multiplicación por
 *        columnas, luego comprueba los tiempos de ejecución y vuelca la información a
 *        un fichero.
 * @see {@link https://github.com/stephanbg/DAA}
 *
 */

#include "matriz.h"
#include "funciones_necesarias.h"

/**
 * @brief Función principal del programa
 * @returns 0, indicando que el programa finalizó correctamente
 */
int main() {
  IniciarSemilla();
  Matriz matriz1, matriz2, resultado_algoritmo_filas, resultado_algoritmo_columnas;
  double tiempo_algoritmo_filas, tiempo_algoritmo_columnas;
  CrearDatosParaMeterEnFichero(matriz1, matriz2, tiempo_algoritmo_filas, tiempo_algoritmo_columnas,
                               resultado_algoritmo_filas, resultado_algoritmo_columnas);
  MeterEnFichero(matriz1, matriz2, tiempo_algoritmo_filas, tiempo_algoritmo_columnas,
                               resultado_algoritmo_filas, resultado_algoritmo_columnas);
  return 0;
}