#include "cargar_programa.h"

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
  std::string kInstruccionSinComas = kInstruccion;
  std::replace(kInstruccionSinComas.begin(), kInstruccionSinComas.end(), ',', '.');
  Instruccion palabras_instruccion(kInstruccionSinComas);
  if (!palabras_instruccion.get_instruccion().empty()) {
    tabla_instrucciones_.push_back(palabras_instruccion);
    GuardaPosInstruccionDelFichero();
  }
}

void CargarPrograma::GuardaPosInstruccionDelFichero() {
  direcciones_fichero_.push_back(puntero_fichero_);
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