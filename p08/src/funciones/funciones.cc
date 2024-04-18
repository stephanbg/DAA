#include "funciones.h"

std::vector<std::string> extraerFicherosEjemplo(const std::string& kNombreDir) {
  std::vector<std::string> nombres_ficheros;
  int num_ficheros = 0;
  const int kCantidadFicherosPedidosPorUsr = cuantosFicherosAEjecutar(kNombreDir);
  fs::path directorio_absoluto = fs::absolute(kNombreDir);
  for (const auto& kEntrada : fs::directory_iterator(kNombreDir)) {
    if (kEntrada.is_regular_file()) {
      fs::path ruta_absoluta = directorio_absoluto / kEntrada.path().filename();
      nombres_ficheros.push_back(ruta_absoluta.string());
      if (++num_ficheros == kCantidadFicherosPedidosPorUsr) break;
    }
  }
  std::sort(nombres_ficheros.begin(), nombres_ficheros.end());
  return nombres_ficheros;
}

const int cuantosFicherosAEjecutar(const std::string& kNombreDir) {
  const int kNumMaximoFicheros = cantidadMaximaFicheros(kNombreDir);
  int cantidad;
  std::cout << "¿Cuántos ficheros quieres ejecutar? ";
  do {
    std::string input;
    std::getline(std::cin, input);
    if (input.empty()) return cantidadMaximaFicheros(kNombreDir);
    std::stringstream ss(input);
    if (!(ss >> cantidad)) std::cout << "Por favor, introduce un número válido: ";
    else if (cantidad < 1) std::cout << "Por favor, introduce un número mayor que 0: ";
    else {
      if (cantidad > kNumMaximoFicheros) {
        std::cout << "El número debe ser como máximo " << kNumMaximoFicheros << ": ";
      } else return cantidad;
    }
  } while (true);
}

const int cantidadMaximaFicheros(const std::string& kNombreDir) {
  int num_ficheros = 0;
  for (const auto& kEntrada : fs::directory_iterator(kNombreDir)) {
    if (kEntrada.is_regular_file()) ++num_ficheros;
  }
  return num_ficheros;
}

const std::string reemplazarComaDecimalPorPunto(const std::string& kCadena) {
  std::string cadena = kCadena;
  const size_t kPos = cadena.find(',');
  if (kPos != std::string::npos) cadena[kPos] = '.';
  return cadena;
}

const int contarDecimales(const double kNumero, const int kPrecisionMax) {
  std::stringstream ss;
  ss << std::fixed << std::setprecision(kPrecisionMax) << kNumero;
  std::string kNumeroStr = ss.str();
  const size_t puntoPos = kNumeroStr.find('.');
  if (puntoPos == std::string::npos) return 0; // No hay decimales
  const int kSizeNumero = kNumeroStr.size();
  int contador_decimales = 0, contador_ceros = 0;
  for (int i = puntoPos + 1; i < kSizeNumero; ++i) {
    if (kNumeroStr[i] != '0') {
      if (contador_ceros > 0) {
        contador_decimales += contador_ceros;
        contador_ceros = 0;
      }
      contador_decimales++;
    }
    else contador_ceros++;
  } 



  return contador_decimales;
}