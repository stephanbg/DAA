/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 14 de Marzo de 2024
 * @file generador_instancias_aleatorias.cc
 * @brief Implementación de la clase GeneradorInstanciasAleatorias
 * que generará ficheros aleatorios
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p06/src}
 * @see {@link https://docs.google.com/document/d/1a691HPtHQL4qBtI2qaTMTp23wxZvU8-CCIbGOyNJRQo/edit}
 */

#include "generador_instancias_aleatorias.h"

std::set<std::string> GeneradorInstanciasAleatorias::ficheros_aletorios_;

/**
 * @brief Genera un archivo de instancia aleatoria con el número especificado de nodos.
 * 
 * @param kNumNodos Número de nodos para la instancia aleatoria.
 * @param nombreDirectorio Directorio donde se guardará el archivo.
 */
void GeneradorInstanciasAleatorias::generadorRand(const int kNumNodos, const std::string& nombreDirectorio) {
  const std::string kNombreFicheroRand = GeneradorInstanciasAleatorias::generarNombreFicheroAleatorio();
  // Construir la ruta completa al archivo
  fs::path ruta_completa = fs::absolute(nombreDirectorio) / kNombreFicheroRand;
  // Abrir el archivo en modo de escritura
  std::ofstream archivo(ruta_completa);
  archivo << kNumNodos << std::endl;
  int num_lineas = (kNumNodos * (kNumNodos - 1)) / 2;
  int indice_nodo_actual = 0, indice_siguiente_conexion = 1;
  const std::vector<std::string> kIdentificadores =
      GeneradorInstanciasAleatorias::generadorIdsAleatorios(kNumNodos);
  while (num_lineas != 0) {
    const std::string kCadaLinea =
        GeneradorInstanciasAleatorias::generarConexionNodos(
          kIdentificadores,
          indice_nodo_actual,
          indice_siguiente_conexion
        );
    archivo << kCadaLinea << std::endl;
    if (indice_siguiente_conexion == (kNumNodos - 1)) {
      indice_nodo_actual++;
      indice_siguiente_conexion = indice_nodo_actual + 1;
    } else indice_siguiente_conexion++;
    num_lineas--;
  }
  archivo.close();
  ficheros_aletorios_.insert(kNombreFicheroRand);
}

/**
 * @brief Genera una conexión aleatoria entre dos nodos.
 * 
 * @param kIdentificadores Vector de identificadores de nodos.
 * @param kIndiceNodoActual Índice del nodo actual.
 * @param kIndiceSiguienteNodo Índice del siguiente nodo.
 * @return La cadena de conexión generada.
 */
const std::string GeneradorInstanciasAleatorias::generarConexionNodos(
  const std::vector<std::string>& kIdentificadores,
  const int kIndiceNodoActual,
  const int kIndiceSiguienteNodo
) {
  std::string conexion = "";
  const int kSizeIdentificadores = kIdentificadores.size();
  conexion += kIdentificadores[kIndiceNodoActual] + " " + kIdentificadores[kIndiceSiguienteNodo] + " " +
      formatearNumero(GeneradorInstanciasAleatorias::generarCosteAleatorio());
  return conexion;
}

/**
 * @brief Genera un número decimal aleatorio con una precisión aleatoria.
 * 
 * @return El número aleatorio generado.
 */
const long double GeneradorInstanciasAleatorias::generarCosteAleatorio() {
  std::random_device rand_device;
  std::mt19937 gen(rand_device());
  std::uniform_int_distribution<int> dist_precision(0, 4); // Precisión aleatoria entre 0 y 4
  int precision = dist_precision(gen);
  std::uniform_real_distribution<long double> dist_numero(1.0, 100.0); // Número aleatorio entre 1 y 100
  long double numero_aleatorio = dist_numero(gen);
  // Ajustar la precisión del número aleatorio
  long double multiplicador = 1;
  for (int i = 0; i < precision; ++i) {
    multiplicador *= 10;
  }
  numero_aleatorio *= multiplicador;
  numero_aleatorio = std::round(numero_aleatorio) / multiplicador;
  return numero_aleatorio;
}

/**
 * @brief Genera identificadores aleatorios para nodos.
 * 
 * @param kNumNodos Número de nodos para generar identificadores.
 * @return Un vector de identificadores aleatorios.
 */
const std::vector<std::string> GeneradorInstanciasAleatorias::generadorIdsAleatorios(const int kNumNodos) {
  std::vector<std::string> ids;
  const int kAlfabetoSize = 26;
  for (int i = 0; i < kNumNodos; ++i) {
    std::string id;
    int i_aux = i;
    do {
      // Obtener el valor de la posición actual
      int resto = i_aux % kAlfabetoSize;
      // Convertir el valor en una letra y agregarlo al identificador
      id = char('A' + resto) + id;
      // Dividir el número entre el tamaño del alfabeto
      i_aux /= kAlfabetoSize;
      // Restar 1 para hacer coincidir el rango con las letras (A-Z)
      i_aux -= 1;
    } while (i_aux >= 0);
    ids.push_back(id);
  }
  return ids;
}

/**
 * @brief Genera un nombre de archivo aleatorio que no existe en la lista de ficheros aleatorios.
 * 
 * @return El nombre de archivo aleatorio generado.
 */
const std::string GeneradorInstanciasAleatorias::generarNombreFicheroAleatorio() {
  // Crear un generador de números aleatorios
  std::random_device rand_device;
  std::mt19937 gen(rand_device());
  std::uniform_int_distribution<> dis(0, 9999);
  std::string nombre = "";
  do {
    int numero_aleatorio = dis(gen);
    nombre = "rand_" + std::to_string(numero_aleatorio) + ".txt";
  } while (GeneradorInstanciasAleatorias::nombreExiste(nombre));
  return nombre;  
}

/**
 * @brief Comprueba si un nombre de archivo ya existe en la lista de ficheros aleatorios.
 * 
 * @param kNombre El nombre de archivo a comprobar.
 * @return true si el nombre de archivo ya existe, false en caso contrario.
 */
const bool GeneradorInstanciasAleatorias::nombreExiste(const std::string& kNombre) {
  for (const auto& nombre_existente : ficheros_aletorios_) {
    if (nombre_existente == kNombre) return true;
  }
  return false;
}

/**
 * @brief Inserta los nombres de los archivos en la lista de ficheros aleatorios.
 * 
 * @param nombreDirectorio Directorio del cual se obtienen los nombres de archivos.
 */
void GeneradorInstanciasAleatorias::insertarFicheros(const std::string& nombreDirectorio) {
  fs::path ruta_absoluta = fs::absolute(nombreDirectorio);
  // Verificar si la ruta es un directorio
  if (!fs::is_directory(ruta_absoluta)) {
    std::cerr << "La ruta especificada no es un directorio." << std::endl;
    return;
  }
  // Iterar sobre todos los archivos en el directorio
  for (const auto& entrada : fs::directory_iterator(ruta_absoluta)) {
    // Verificar si la entrada es un archivo regular
    if (fs::is_regular_file(entrada)) {
      std::ifstream archivo(entrada.path());
      if (!GeneradorInstanciasAleatorias::nombreExiste(entrada.path().filename())) {
        ficheros_aletorios_.insert(entrada.path().filename());
      }
    }
  }
}

/**
 * @brief Elimina los archivos de instancia aleatoria del directorio especificado.
 * 
 * @param kNombreDirectorio Directorio donde se buscan y eliminan los archivos aleatorios.
 * @param kOpcion Opción de confirmación para eliminar los archivos.
 */
void GeneradorInstanciasAleatorias::eliminarFicherosRand(
  const std::string& kNombreDirectorio,
  const std::string& kOpcion
) {
  if (kOpcion != "S") return;
  ficheros_aletorios_.clear();
  fs::path ruta_absoluta = fs::absolute(kNombreDirectorio);
  // Verificar si la ruta es un directorio
  if (!fs::is_directory(ruta_absoluta)) {
    std::cerr << "La ruta especificada no es un directorio." << std::endl;
    return;
  }
  // Iterar sobre todos los archivos en el directorio
  for (const auto& entrada : fs::directory_iterator(ruta_absoluta)) {
    // Verificar si la entrada es un archivo regular y si su nombre comienza con "rand_" y termina con ".txt"
    if (fs::is_regular_file(entrada) &&
        entrada.path().filename().string().find("rand_") == 0 &&
        entrada.path().extension() == ".txt") {
      // Eliminar el archivo
      fs::remove(entrada.path());
    }
  }
}