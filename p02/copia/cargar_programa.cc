#include "cargar_programa.h"
#include "funciones_necesarias.h"

CargarPrograma::CargarPrograma(const::std::string& kNombreFicheroRam, MemoriaPrograma& memoria) {
  std::ifstream archivo(kNombreFicheroRam);
  std::string cada_linea = "";
  puntero_fichero_ = 0;
  while (std::getline(archivo, cada_linea)) {
    lineas_fichero_.push_back(cada_linea);
    puntero_fichero_++;
    // Si esta correcta, separa la instruccion en palabras
    if (!cada_linea.empty()) ExtraerComentarios(cada_linea);
    if (!cada_linea.empty()) {
      BuscarEtiqueta(cada_linea);
      if (!cada_linea.empty()) {
        AlmacenarInstruccion(cada_linea);
      }
    }
  }
  SustituirEtiquetasPorValor();
  memoria = MemoriaPrograma(tabla_instrucciones_);
}

void CargarPrograma::ExtraerComentarios(std::string& linea) {
  const size_t kPosHashtag = linea.find('#');
  if (kPosHashtag != std::string::npos) { // Existe
    if (kPosHashtag == 0) linea = "";
    else linea = linea.substr(0, kPosHashtag - 1);
  }
}

void CargarPrograma::BuscarEtiqueta(std::string& linea) {
  const std::regex kPatron("\\s*[^\\s:]+\\s*:");
  std::vector<std::string> v_etiquetas = GuardarEtiquetasDeLinea(kPatron, linea);
  EliminarCoincidencias(v_etiquetas, linea);
  std::string etiqueta;
  const int kSizeVectorEtiquetas = v_etiquetas.size(); 
  for (int i = 0; i < kSizeVectorEtiquetas; ++i) {
    etiqueta = QuitarEspacios(v_etiquetas[i]);
    etiqueta = etiqueta.substr(0, etiqueta.size() - 1);
    AlmacenarEtiqueta(etiqueta);
  }
}

const std::vector<std::string> CargarPrograma::GuardarEtiquetasDeLinea(const std::regex& kPatron,
                                                                       const std::string& kLinea) {
  // Inicializar el iterador de búsqueda
  std::sregex_iterator iterador(kLinea.begin(), kLinea.end(), kPatron);
  std::sregex_iterator final;
  std::vector<std::string> v_coincidencias;
  // Bucle para encontrar y mostrar todas las coincidencias
  while (iterador != final) {
    std::smatch coincidencia = *iterador;
    v_coincidencias.push_back(coincidencia.str());
    // Avanzar al siguiente
    ++iterador;
  }
  return v_coincidencias;
}

void CargarPrograma::AlmacenarEtiqueta(const std::string& kEtiqueta) {
  const std::string kError = "No se puede ejecutar el programa si"
                             " hay 2 o más etiquetas repetidas.";
  auto iterador = tabla_etiqueta_valor_.find(kEtiqueta);
  if (iterador != tabla_etiqueta_valor_.end()) throw (kError);
  int valor = 0;
  if (!tabla_instrucciones_.empty()) valor = tabla_instrucciones_.size();
  tabla_etiqueta_valor_[kEtiqueta] = valor;
}

void CargarPrograma::AlmacenarInstruccion(const std::string& kInstruccion) {
  Instruccion palabras_instruccion;
  palabras_instruccion.set_instruccion() = SepararInstruccionEnPalabras(kInstruccion);
  if (!palabras_instruccion.get_instruccion().empty()) {
    palabras_instruccion.set_instruccion()[0] = ConvertirAMayusculas(palabras_instruccion.get_instruccion()[0]);
    tabla_instrucciones_.push_back(palabras_instruccion);
    GuardaPosInstruccionDelFichero();
  }
}

void CargarPrograma::GuardaPosInstruccionDelFichero() {
  direcciones_fichero_.push_back(puntero_fichero_);
}

const std::vector<std::string> CargarPrograma::SepararInstruccionEnPalabras(const std::string& kLinea) {
  std::vector<std::string> palabras_instruccion;
  // Separo la instrucción en palabras
  std::istringstream iss(kLinea);
  std::string palabra;
  while (iss >> palabra) {
    palabras_instruccion.push_back(palabra);
  }
  return palabras_instruccion;
}

void CargarPrograma::SustituirEtiquetasPorValor() {
  const int kSizeTablaInstrucciones = tabla_instrucciones_.size();
  for (int i = 0; i < kSizeTablaInstrucciones; ++i) {
    if (tabla_instrucciones_[i].get_instruccion()[0] == "JUMP" ||
        tabla_instrucciones_[i].get_instruccion()[0] == "JZERO" ||
        tabla_instrucciones_[i].get_instruccion()[0] == "JGTZ") {
      auto iterador = tabla_etiqueta_valor_.find(tabla_instrucciones_[i].get_instruccion()[1]);
      if (iterador != tabla_etiqueta_valor_.end()) {
        tabla_instrucciones_[i].set_instruccion()[1] = "=" + std::to_string(iterador->second);
      } else tabla_instrucciones_[i].set_instruccion()[1] = "=-1";
    }
  }
}

/*void Memoria::EjecutarLinea(std::string& linea,
                               std::vector<std::string>& palabras_instruccion) {
  // Comprobar todo tipo de error
  ExtraerComentarios(linea);
  if (!linea.empty()) {
    //SepararInstruccionEnPalabras(linea, palabras_instruccion);
  }
}*/

/*void Compilador::ComprobarInstruccion(const std::vector<std::string>& kPalabrasInstruccion) {
  std::vector<std::string> palabras_instruccion = kPalabrasInstruccion;
  if (EsEtiqueta(palabras_instruccion[0])) {
    AlmacenarEtiqueta(palabras_instruccion[0]);
    RotarUnoHaciaDerecha(palabras_instruccion);
  }
  // Si quito la etiqueta de la instrucción para saber si queda algo en la instrucción
  if (!palabras_instruccion.empty()) {
    // Instrucción limpia
    const std::string palabras_en_mayusculas = ConvertirAMayusculas(palabras_instruccion[0]);
    bool instruccion_correcta = false;
    if (palabras_en_mayusculas == "LOAD") {
    
    } else if (palabras_en_mayusculas == "STORE") {

    } else if (palabras_en_mayusculas == "ADD") {

    } else if (palabras_en_mayusculas == "SUB") {

    } else if (palabras_en_mayusculas == "MUL") {

    } else if (palabras_en_mayusculas == "DIV") {

    } else if (palabras_en_mayusculas == "READ") {

    } else if (palabras_en_mayusculas == "WRITE") {

    } else if (palabras_en_mayusculas == "JUMP") {

    } else if (palabras_en_mayusculas == "JZERO") {

    } else if (palabras_en_mayusculas == "JGTZ") {

    } else if (palabras_en_mayusculas == "HALT") {

    }
    if (!instruccion_correcta) MostrarInstruccionYLineaErronea(kPalabrasInstruccion);
    else AlmacenarInstruccion(palabras_instruccion);
  }
}

void Compilador::AlmacenarEtiqueta(const std::string& kEtiqueta) {
  int valor = 0;
  if (!tabla_instrucciones_.empty()) valor = tabla_instrucciones_.size();
  std::string etiqueta_sin_dos_puntos = kEtiqueta.substr(0, kEtiqueta.size() - 1);
  tabla_etiqueta_valor_[etiqueta_sin_dos_puntos] = valor;
}

void Compilador::MostrarInstruccionYLineaErronea(const std::vector<std::string>& kPalabrasInstruccion) {
  const int kCantidadPalabrasInstruccion = kPalabrasInstruccion.size();
  std::string instruccion = "";
  for (int i = 0; i < kCantidadPalabrasInstruccion; ++i) {
    instruccion += kPalabrasInstruccion[i] + " ";
  }
  std::string kError = "\n\nInstrucción --- " + instruccion + "\n";
  kError += "Línea --- " + std::to_string(puntero_linea_);
  throw (kError);
}*/