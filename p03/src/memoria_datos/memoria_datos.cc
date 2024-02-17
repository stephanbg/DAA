/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file memoria_datos.cc
 * @brief Implementación de la clase MemoriaDatos, que representa la memoria de datos de la Máquina RAM.
 *        Es decir, los registros.
 * 
 * @see {@link https://docs.google.com/document/d/1zf_w2HtS4zJX3iqr9yPm6f7rRNsrBxL7afCsMapujMQ/edit#heading=h.5bq8rsdy1ujx}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p03}
 */

#include "memoria_datos.h"

/**
 * @brief Construye un nuevo objeto MemoriaDatos.
 * 
 * @param kNumeroRegistros Número de registros que tendrá la memoria de datos.
 * @param estrategia Estrategia de almacenamiento a utilizar.
 */
MemoriaDatos::MemoriaDatos(const int kNumeroRegistros, EstrategiaAlmacenamiento* estrategia) {
  estrategia_ = estrategia;
  std::vector<long double> fila_registro;
  for (int i = 0; i < kNumeroRegistros; ++i) {
    fila_registro.resize(1, 0);
    registros_.push_back(fila_registro);
  }
}

/**
 * @brief Almacena un dato en la memoria de datos en la posición especificada.
 * 
 * @param kDato Dato a almacenar.
 * @param kIndiceFila Índice de la fila en la que se almacenará el dato.
 * @param kIndiceColumna Índice de la columna en la que se almacenará el dato (por defecto 0).
 */
void MemoriaDatos::almacenarDato(const long double kDato, const int kIndiceFila, const int kIndiceColumna) {
  estrategia_->almacenarDato(registros_, kDato, kIndiceFila, kIndiceColumna);
}

/**
 * @brief Obtiene un dato almacenado en la memoria de datos en la posición especificada.
 * 
 * @param kIndiceFila Índice de la fila del dato a obtener.
 * @param kIndiceColumna Índice de la columna del dato a obtener (por defecto 0).
 * @return Dato obtenido.
 */
const long double MemoriaDatos::obtenerDato(const int kIndiceFila, const int kIndiceColumna) const {
  return estrategia_->obtenerDato(registros_, kIndiceFila, kIndiceColumna);
}

/**
 * @brief Sobrecarga del operador de inserción para imprimir la memoria de datos.
 * 
 * @param os Flujo de salida.
 * @param kMemoria Memoria de datos a imprimir.
 * @return Referencia al flujo de salida.
 */
std::ostream& operator<<(std::ostream& os, const MemoriaDatos& kMemoria) {
  // Determina el número de decimales necesario para cada contenido
  int numero_decimales = 0;
  const int kSizeMemoria = kMemoria.registros_.size();
  // Imprime cada dato de los registros con el número adecuado de decimales
  for (int i = 0; i < kSizeMemoria; ++i) {
    os << "R" << i << ": ";
    for (int j = 0; j < kMemoria.registros_[i].size(); ++j) {
      numero_decimales = ContarDecimales(kMemoria.registros_[i][j]);      
      os << std::fixed << std::setprecision(numero_decimales) << kMemoria.registros_[i][j];
      if (j < kSizeMemoria - 1) os << " ";
    }
    if (i < kSizeMemoria - 1) os << std::endl;
  }
  return os;
}