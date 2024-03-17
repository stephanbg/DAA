#include "generador_instancias_aleatorias.h"

std::set<std::string> GeneradorInstanciasAleatorias::ficheros_aletorios_;

void GeneradorInstanciasAleatorias::generadorRand(const int kNumNodos, const std::string& nombreDirectorio) {
  const std::string kNombreFicheroRand = GeneradorInstanciasAleatorias::generarNombreFicheroAleatorio();
  // Construir la ruta completa al archivo
  fs::path ruta_completa = fs::absolute(nombreDirectorio) / kNombreFicheroRand;
  // Abrir el archivo en modo de escritura
  std::ofstream archivo(ruta_completa);
  archivo << kNumNodos << std::endl;
  int num_lineas = (kNumNodos * (kNumNodos - 1)) / 2, indice_nodo_actual = 0, indice_siguiente_conexion = 1;
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
    // Agregar el identificador al vector
    ids.push_back(id);
  }
  return ids;
}

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

const bool GeneradorInstanciasAleatorias::nombreExiste(const std::string& kNombre) {
  for (const auto& nombre_existente : ficheros_aletorios_) {
    if (nombre_existente == kNombre) return true;
  }
  return false;
}

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