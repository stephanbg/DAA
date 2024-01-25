#include "matriz.h"
#include "funcionesNecesarias.h"

int main() {
  Matriz matriz1, matriz2, resultadoAlgoritmoFilas, resultadoAlgoritmoColumnas;
  double tiempoAlgoritmoFilas, tiempoAlgoritmoColumnas;
  crearDatosParaMeterEnFichero(matriz1, matriz2, tiempoAlgoritmoFilas, tiempoAlgoritmoColumnas,
                               resultadoAlgoritmoFilas, resultadoAlgoritmoColumnas);
  meterEnFichero(matriz1, matriz2, tiempoAlgoritmoFilas, tiempoAlgoritmoColumnas,
                               resultadoAlgoritmoFilas, resultadoAlgoritmoColumnas);
  return 0;
}