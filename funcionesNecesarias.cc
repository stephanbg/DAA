#include "funcionesNecesarias.h"

// Función que devuelve el tiempo de ejecución en segundos
double medirTiempoEjecucion(const MultiplicarMatriz& operacion, const Matriz& matriz1, const Matriz& matriz2) {
  // Registra el tiempo de inicio
  auto start_time = std::chrono::high_resolution_clock::now();
  operacion.multiplicar(matriz1, matriz2);
  // Registra el tiempo de finalización
  auto end_time = std::chrono::high_resolution_clock::now();
  // Calcula la duración en segundos
  auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time);
  // Devuelve el tiempo de ejecución en segundos
  return duration.count();
}

void crearDatosParaMeterEnFichero(const Matriz& matriz1, Matriz& matriz2, double& tiempoAlgoritmoFilas,
                                  double& tiempoAlgoritmoColumnas, Matriz& resultadoAlgoritmoFilas,
                                  Matriz& resultadoAlgoritmoColumnas) {
  ComprobarFilasYColumnas comprobar;
  while (comprobar.ComprobarErrorEnSize(matriz1, matriz2) == EXIT_FAILURE) {
    matriz2 = Matriz();
  }
  MultiplicarMatriz* operacion = new MultiplicarPorFilas();
  tiempoAlgoritmoFilas = medirTiempoEjecucion(*operacion, matriz1, matriz2);
  resultadoAlgoritmoFilas = operacion->multiplicar(matriz1, matriz2);
  operacion = new MultiplicarPorColumnas();
  tiempoAlgoritmoColumnas = medirTiempoEjecucion(*operacion, matriz1, matriz2);
  resultadoAlgoritmoColumnas = operacion->multiplicar(matriz1, matriz2);  
}

void meterEnFichero(const Matriz& matriz1, const Matriz& matriz2, const double tiempoAlgoritmoFilas,
                    const double tiempoAlgoritmoColumnas, const Matriz& resultadoAlgoritmoFilas,
                    const Matriz& resultadoAlgoritmoColumnas) {
  // Nombre del archivo
  const std::string nombreArchivo = "resultados.txt";
  // Abre el archivo en modo de apéndice
  std::ofstream archivoSalida(nombreArchivo, std::ios::app);
  archivoSalida << "Matriz nº 1: " << std::endl << std::endl;
  archivoSalida << matriz1 << std::endl;
  archivoSalida << "Matriz nº 2: " << std::endl << std::endl;
  archivoSalida << matriz2 << std::endl;
  archivoSalida << "---------------------------------" << std::endl << std::endl;
  archivoSalida << "Resultado multiplicación de matrices por filas: " << std::endl << std::endl;
  archivoSalida << resultadoAlgoritmoFilas << std::endl;
  archivoSalida << "Tiempo de ejecución: " << tiempoAlgoritmoFilas << std::endl << std::endl;
  archivoSalida << "---------------------------------" << std::endl << std::endl;
  archivoSalida << "Resultado multiplicación de matrices por columnas: " << std::endl << std::endl;
  archivoSalida << resultadoAlgoritmoColumnas << std::endl;
  archivoSalida << "Tiempo de ejecución: " << tiempoAlgoritmoColumnas << std::endl << std::endl;
  archivoSalida.close();
}