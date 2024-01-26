/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2023-2024
 *
 * @author Stephan Brommer Gutiérrez
 * Correo: alu0101493497@ull.edu.es
 * @date 30/01/2024
 * @file funciones_necesarias.cc
 * @brief Implementación de funciones auxiliares que van a ser necesarias en el resto del programa
 * @see {@link https://github.com/stephanbg/DAA}
 *
 */

#include "funciones_necesarias.h"

/**
 * @brief Se encarga de inicializar la semilla
 */
void IniciarSemilla() {
  const auto kSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
  srand(static_cast<unsigned>(kSeed));
}

/**
 * @brief Genera números aleatorios entre 1 y 100
 * @returns Devuelve el número aleatorio
 */    
int GenerarNumerosAleatorias() {
  return (rand() % 100) + 1;
}

/**
 * @brief Función que se encarga de medir el tiempo de ejecución del algoritmo de multiplicar matrices
 * @param[in] kOperacion referencia (constante) de cualquier tipo de operación de multiplicación entre matrices 
 * @param[in] kMatriz1 referencia (constante) de la primera matriz
 * @param[in] kMatriz2 referencia (constante) de la segunda matriz
 * @returns Devuelve el tiempo de ejecución del algoritmo de multiplicación en segundos.
 */
double MedirTiempoEjecucion(const MultiplicarMatriz& kOperacion, const Matriz& kMatriz1, const Matriz& kMatriz2) {
  const auto kInicio = std::chrono::high_resolution_clock::now();
  kOperacion.Multiplicar(kMatriz1, kMatriz2);
  const auto kFin = std::chrono::high_resolution_clock::now();
  const auto kDuracion = std::chrono::duration_cast<std::chrono::duration<double>>(kFin - kInicio);
  return kDuracion.count();
}

/**
 * @brief Función que se encarga de realizar todos los calculos de tiempos y resultados,
 *        para crear los datos que posteriormente se volcarán en un fichero.
 * @param[in] kMatriz1 referencia (constante) de la primera matriz
 * @param[in] matriz2 referencia de la segunda matriz
 * @param[in] tiempo_algoritmo_filas referencia al tiempo del algoritmo de multiplicación por filas
 * @param[in] tiempo_algoritmo_columnas referencia al tiempo del algoritmo de multiplicación por columnas
 * @param[in] resultado_algoritmo_filas referencia al resultado del algoritmo por filas
 * @param[in] resultado_algoritmo_columnas referencia al resultado del algoritmo por columnas
 */
void CrearDatosParaMeterEnFichero(const Matriz& kMatriz1, Matriz& matriz2, double& tiempo_algoritmo_filas,
                                  double& tiempo_algoritmo_columnas, Matriz& resultado_algoritmo_filas,
                                  Matriz& resultado_algoritmo_columnas) {
  ComprobarFilasYColumnas comprobar;
  // Tras estar creada la matriz 1, la matriz 2 se va calculando de nuevo de manera aleatoria hasta que coincidan
  // la cantidad de filas con las columnas de la matriz 1.
  while (comprobar.ComprobarErrorEnSize(kMatriz1, matriz2) == EXIT_FAILURE) {
    matriz2 = Matriz();
  }
  // MedirTiempoEjecucion: Realiza la operación de multiplicación, y solo calcula el tiempo
  // Multiplicar: Vuelve a realizar la operación para almacenar resultado   
  MultiplicarMatriz* operacion = new MultiplicarPorFilas();
  tiempo_algoritmo_filas = MedirTiempoEjecucion(*operacion, kMatriz1, matriz2);
  resultado_algoritmo_filas = operacion->Multiplicar(kMatriz1, matriz2);
  operacion = new MultiplicarPorColumnas();
  tiempo_algoritmo_columnas = MedirTiempoEjecucion(*operacion, kMatriz1, matriz2);
  resultado_algoritmo_columnas = operacion->Multiplicar(kMatriz1, matriz2);  
}

/**
 * @brief Función que se encarga de volcar todos los resultados de ambos algoritmos y las matrices iniciales
 *        en el fichero de salida con nombre "resultados.txt"
 * @param[in] kMatriz1 referencia (constante) de la primera matriz
 * @param[in] kMatriz2 referencia (constante) de la segunda matriz
 * @param[in] kTiempoAlgoritmoFilas referencia (constante) al tiempo del algoritmo de multiplicación por filas
 * @param[in] kTiempoAlgoritmoColumnas referencia (constante) al tiempo del algoritmo de multiplicación por columnas
 * @param[in] kResultadoAlgoritmoFilas referencia (constante) al resultado del algoritmo por filas
 * @param[in] kResultadoAlgoritmoColumnas referencia (constante) al resultado del algoritmo por columnas
 */
void MeterEnFichero(const Matriz& kMatriz1, const Matriz& kMatriz2, const double kTiempoAlgoritmoFilas,
                    const double kTiempoAlgoritmoColumnas, const Matriz& kResultadoAlgoritmoFilas,
                    const Matriz& kResultadoAlgoritmoColumnas) {
  const std::string kNombreArchivo = "resultados.txt";
  std::ofstream archivo_salida(kNombreArchivo, std::ios::app);
  archivo_salida << "Matriz nº 1: " << std::endl;
  archivo_salida << "Nº Filas: " << kMatriz1.get_matriz().size() << std::endl;
  archivo_salida << "Nº Columnas: " << kMatriz1.get_matriz()[0].size() << std::endl << std::endl;
  archivo_salida << kMatriz1 << std::endl;
  archivo_salida << "Matriz nº 2: " << std::endl;
  archivo_salida << "Nº Filas: " << kMatriz2.get_matriz().size() << std::endl;
  archivo_salida << "Nº Columnas: " << kMatriz2.get_matriz()[0].size() << std::endl << std::endl;  
  archivo_salida << kMatriz2 << std::endl;
  archivo_salida << "---------------------------------" << std::endl << std::endl;
  archivo_salida << "Resultado multiplicación de matrices por filas: " << std::endl;
  archivo_salida << "Nº Filas: " << kResultadoAlgoritmoFilas.get_matriz().size() << std::endl;
  archivo_salida << "Nº Columnas: " << kResultadoAlgoritmoFilas.get_matriz()[0].size() << std::endl << std::endl;  
  archivo_salida << kResultadoAlgoritmoFilas << std::endl;
  archivo_salida << "Tiempo de ejecución: " << kTiempoAlgoritmoFilas << std::endl << std::endl;
  archivo_salida << "---------------------------------" << std::endl << std::endl;
  archivo_salida << "Resultado multiplicación de matrices por columnas: " << std::endl;
  archivo_salida << "Nº Filas: " << kResultadoAlgoritmoColumnas.get_matriz().size() << std::endl;
  archivo_salida << "Nº Columnas: " << kResultadoAlgoritmoColumnas.get_matriz()[0].size() << std::endl << std::endl;    
  archivo_salida << kResultadoAlgoritmoColumnas << std::endl;
  archivo_salida << "Tiempo de ejecución: " << kTiempoAlgoritmoColumnas << std::endl << std::endl;
  archivo_salida.close();
}