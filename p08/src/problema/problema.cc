#include "problema.h"

Problema::Problema(const std::string& kNombreFichero) {
  std::ifstream fichero(kNombreFichero);
  construirMatrices(fichero);
  rellenarDatosCoordenadas(fichero);
  rellenarDatosDistancias();
  fichero.close();
}

void Problema::construirMatrices(std::ifstream& fichero) {
  std::string cada_linea = "";
  getline(fichero, cada_linea);
  const int kNumElementos = std::stoi(cada_linea);
  getline(fichero, cada_linea);
  const int kDimensiones = std::stoi(cada_linea);
  coordenadas_ = Matriz(kNumElementos, kDimensiones);
  distancias_ = Matriz(kNumElementos, kNumElementos);
}

void Problema::rellenarDatosCoordenadas(std::ifstream& fichero) {
  std::string linea;
  int filas = 0, columnas = 0;
  while (getline(fichero, linea)) {
    std::stringstream ss(linea);
    std::string palabra;
    columnas = 0;
    while (ss >> palabra) {
      coordenadas_[filas][columnas++] = stod(reemplazarComaDecimalPorPunto(palabra));
    }
    filas++;
  }
}

void Problema::rellenarDatosDistancias() {
  const int kNumFilas = distancias_.getMatriz().size();
  for (int filas = 0; filas < kNumFilas; ++filas) {
    const int kNumColumnas = distancias_.getMatriz()[0].size();
    for (int columnas = filas + 1; columnas < kNumColumnas; ++columnas) {
      const int kNumDimensiones = coordenadas_.getMatriz()[0].size();
      double distancia = 0.0;
      for (int i = 0; i < kNumDimensiones; ++i) {
        distancia += (
          (coordenadas_[filas][i] - coordenadas_[columnas][i]) * (coordenadas_[filas][i] - coordenadas_[columnas][i])
        );
      }
      const double kSqrtDistancias = sqrt(distancia);
      distancias_[filas][columnas] = kSqrtDistancias;
      distancias_[columnas][filas] = kSqrtDistancias;
    }
  }
}

const std::vector<int> Problema::getIndicesProblema() const {
  std::vector<int> indices;
  const int kSizeMatriz = coordenadas_.size();
  for (int indice = 0; indice < kSizeMatriz; ++indice) indices.push_back(indice);
  return indices;
}

std::ostream& operator<<(std::ostream& salida, const Problema& kProblema) {
  salida << "Matriz coordenadas de cada elemento" << std::endl;
  salida << "-----------------------------------" << std::endl;
  salida << kProblema.getCoordenadas();
  salida << std::endl;
  salida << "Matriz distancias de cada elemento" << std::endl;
  salida << "----------------------------------" << std::endl;
  salida << kProblema.getDistancias();
  salida << std::endl;
  return salida;
}