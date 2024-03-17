#include "tablaResultadosTSP.h"

std::vector<std::string> TablaResultadosTSP::nombres_ficheros_;
std::vector<std::string> TablaResultadosTSP::nombres_algoritmos_;
std::vector<std::vector<std::pair<const long double, const long double>>> TablaResultadosTSP::matriz_datos_;

void TablaResultadosTSP::insertarDatoNombreFichero(const std::string& kNombreFichero) {
  nombres_ficheros_.push_back(kNombreFichero);
}

void TablaResultadosTSP::insertarDatoNombreAlgoritmo(const std::string& kNombreAlgoritmo) {
  nombres_algoritmos_.push_back(kNombreAlgoritmo);
}

void TablaResultadosTSP::insertarFilaMatrizDatos(
  const std::vector<std::pair<const long double, const long double>>& kCosteYTiempoEjecucionCadaFila
) {
  matriz_datos_.push_back(kCosteYTiempoEjecucionCadaFila);
}

void TablaResultadosTSP::mostrarTablaEnPantalla() {
  // Mostrar encabezados
  const int kSizeMatrizDatos = matriz_datos_.size();
  std::cout << std::endl;
  for (int i = 0; i < kSizeMatrizDatos; ++i) {
    std::cout << "Instancia: " << nombres_ficheros_[i] << std::endl;
    for (int j = 0; j < matriz_datos_[i].size(); ++j) {
      std::cout << "Valor " << nombres_algoritmos_[j] << ": " << matriz_datos_[i][j].first << std::endl;
      std::cout << "Tiempo " << nombres_algoritmos_[j] << " (ms) : " << matriz_datos_[i][j].second << std::endl;
      std::cout << std::endl;
    }
  }
}

void TablaResultadosTSP::mostrarTablaEnFichero() {
  std::ofstream archivo("resultados.txt", std::ofstream::app); // Abre en modo de apéndice
  if (!archivo.is_open()) {
    std::cerr << "Error al abrir el archivo." << std::endl;
    return;
  }
  const int kSizeMatrizDatos = matriz_datos_.size();
  for (int i = 0; i < kSizeMatrizDatos; ++i) {
    archivo << "Instancia: " << nombres_ficheros_[i] << std::endl;
    for (int j = 0; j < matriz_datos_[i].size(); ++j) {
      archivo << "Valor " << nombres_algoritmos_[j] << ": " << matriz_datos_[i][j].first << std::endl;
      archivo << "Tiempo " << nombres_algoritmos_[j] << " (ms) : " << matriz_datos_[i][j].second << std::endl;
      archivo << std::endl;
    }
  }  
}