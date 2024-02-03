#include "compilador.h"
#include "funciones_necesarias.h"

void Compilador::CompilarPrograma(const::std::string& kNombreFicheroRam) {
  std::ifstream archivo(kNombreFicheroRam);
  std::string cada_linea = "";
  std::vector<std::string> palabras_instruccion;
  puntero_linea_ = 0;
  while (std::getline(archivo, cada_linea)) {
    puntero_linea_++;
    // Si esta correcta, separa la instruccion en palabras
    CompilarLinea(cada_linea, palabras_instruccion);
    palabras_instruccion.erase(palabras_instruccion.begin(), palabras_instruccion.end());
  }
}

void Compilador::CompilarLinea(std::string& linea,
                               std::vector<std::string>& palabras_instruccion) {
  // Comprobar todo tipo de error
  ExtraerComentarios(linea);
  if (!linea.empty()) {
    SepararInstruccionEnPalabras(linea, palabras_instruccion);
  }
}

void Compilador::ExtraerComentarios(std::string& linea) {
  const size_t kPosHashtag = linea.find('#');
  if (kPosHashtag != std::string::npos) { // Existe
    if (kPosHashtag == 0) linea = "";
    else linea = linea.substr(0, kPosHashtag - 1);
  }
}

void Compilador::SepararInstruccionEnPalabras(const std::string& kLinea,
                                              std::vector<std::string>& palabras_instruccion) {
  // Separo la instrucción en palabras
  std::istringstream iss(kLinea);
  std::string palabra;
  while (iss >> palabra) {
    palabras_instruccion.push_back(palabra);
  }
  ComprobarInstruccion(palabras_instruccion);
}

void Compilador::ComprobarInstruccion(const std::vector<std::string>& kPalabrasInstruccion) {
  std::vector<std::string> palabras_instruccion = kPalabrasInstruccion;
  if (EsEtiqueta(palabras_instruccion[0])) {
    // AlmacenarEtiqueta()
    // Rodar vector 1 hacia la derecha
  }
  // Instrucción limpia
  const std::string palabras_en_mayusculas = ConvertirAMayusculas(palabras_instruccion[0]);
  bool instruccion_correcta = false;
  if (palabras_en_mayusculas == "LOAD") {
    if (ComprobarOperacionDirecta(palabras_instruccion)) { 
      instruccion_correcta = true;
    } else if ((!instruccion_correcta) &&
               ComprobarOperacionIndirecta(palabras_instruccion)) {
                instruccion_correcta = true;
    }
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
}

bool Compilador::ComprobarOperacionConstante(const std::vector<std::string>& kPalabrasInstruccion) {
  const std::regex kPatron("^\\d+$");
  if (std::regex_match(kPalabrasInstruccion[1], kPatron) == false) return false; // Si no sigue patrón error
  else if ((kPalabrasInstruccion.size() - 1) - (1) != 0) return false; // Si hay más de un operando error
  return true;
}

bool Compilador::ComprobarOperacionDirecta(const std::vector<std::string>& kPalabrasInstruccion) {
  const std::regex kPatron("^=\\d+$");
  if (std::regex_match(kPalabrasInstruccion[1], kPatron) == false) return false; // Si no sigue patrón error
  else if ((kPalabrasInstruccion.size() - 1) - (1) != 0) return false; // Si hay más de un operando error
  return true;
}

bool Compilador::ComprobarOperacionIndirecta(const std::vector<std::string>& kPalabrasInstruccion) {
  const std::regex kPatron("^*\\d+$");
  if (std::regex_match(kPalabrasInstruccion[1], kPatron) == false) return false; // Si no sigue patrón error
  else if ((kPalabrasInstruccion.size() - 1) - (1) != 0) return false; // Si hay más de un operando error
  return true;
}

bool Compilador::EsEtiqueta(const std::string& kPalabra) {
  const std::regex kPatron(".+:$");
  return std::regex_match(kPalabra, kPatron);
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
}

void Compilador::AlmacenarInstruccion(const std::vector<std::string>& kPalabrasInstruccion) {
  
}