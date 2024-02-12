/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 30 de Enero de 2024
 * @file cargar_programa.cc
 * @brief Implementación de la clase CargarPrograma para cargar un programa
 *        en la memoria de programa de la Máquina RAM.
 * @see {@link https://docs.google.com/document/d/1n6iua2wSG2UVns-mTA4YdMBVKfKIazkJi4HRzKVKS78/edit}
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p02}
 */

#include "cargar_programa.h"

/**
 * @brief Construye un nuevo objeto de CargarPrograma y carga el programa en la memoria.
 * 
 * @param kNombreFicheroRam Nombre del archivo que contiene el programa RAM.
 * @param memoria Referencia a la memoria de programa donde se cargará el programa.
 * @throw Lanza una excepción si no se pudo abrir el fichero o cerrar. 
 */
CargarPrograma::CargarPrograma(const::std::string& kNombreFicheroRam, MemoriaPrograma& memoria) {
  std::ifstream archivo(kNombreFicheroRam);
  const std::string kErrorApertura = "Apertura de archivo de entrada.";
  const std::string kErrorCierre = "Cierre de archivo de entrada.";
  if (!archivo.is_open()) throw (kErrorApertura);
  std::string cada_linea = "";
  puntero_fichero_ = 0;
  // Recorre el fichero extrayendo todo lo importante 
  while (std::getline(archivo, cada_linea)) {
    lineas_fichero_.push_back(cada_linea);
    puntero_fichero_++;
    if (!cada_linea.empty()) ExtraerComentarios(cada_linea);
    if (!cada_linea.empty()) {
      BuscarEtiqueta(cada_linea);
      if (!cada_linea.empty()) {
        AlmacenarInstruccion(cada_linea);
      }
    }
  }
  archivo.close();
  if (archivo.is_open()) throw (kErrorCierre);
  SustituirEtiquetasPorValor();
  // Finalemente llama al constructor de la Memoria de Programa para pasarle el vector de instrucciones
  memoria = MemoriaPrograma(tabla_instrucciones_);
}

/**
 * @brief Extrae los comentarios de la línea
 * 
 * @param linea Línea de la que se extraerán los comentarios
 */
void CargarPrograma::ExtraerComentarios(std::string& linea) {
  const size_t kPosHashtag = linea.find('#');
  if (kPosHashtag != std::string::npos) { // Si hay # hay comentarios
    if (kPosHashtag == 0) linea = "";
    else linea = linea.substr(0, kPosHashtag - 1);
  }
}

/**
 * @brief Busca etiquetas en una línea de código y las almacena.
 * 
 * @param linea La línea de código donde buscar etiquetas.
 */
void CargarPrograma::BuscarEtiqueta(std::string& linea) {
  // Puede tener espacios en blancoal inicio, luego la etiqueta no puede
  // tener ni espacios entre medio ni ':' y puede tener después espacios y finaliza en ':'
  const std::regex kPatron("\\s*[^\\s:]+\\s*:");
  std::vector<std::string> v_etiquetas = GuardarEtiquetasDeLinea(kPatron, linea); // Guarda las etiquetas
  EliminarCoincidencias(v_etiquetas, linea); // Elimina de la línea original las etiquetas
  std::string etiqueta;
  const int kSizeVectorEtiquetas = v_etiquetas.size(); 
  // Se encarga de almacenar las etiquetas quitando espacios
  for (int i = 0; i < kSizeVectorEtiquetas; ++i) {
    etiqueta = QuitarEspacios(v_etiquetas[i]);
    etiqueta = etiqueta.substr(0, etiqueta.size() - 1);
    AlmacenarEtiqueta(etiqueta);
  }
}

/**
 * @brief Guarda las etiquetas encontradas en una línea dada, utilizando un patrón de expresión regular.
 * 
 * @param kPatron El patrón de expresión regular utilizado para buscar las etiquetas.
 * @param kLinea La línea de texto en la que se buscarán las etiquetas.
 * @return Un vector que contiene las etiquetas encontradas en la línea.
 */
const std::vector<std::string> CargarPrograma::GuardarEtiquetasDeLinea(const std::regex& kPatron,
                                                                       const std::string& kLinea) {
  // Inicializar el iterador de búsqueda, para buscar las etiquetas
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

/**
 * @brief Almacena una etiqueta en la tabla de etiquetas y sus valores asociados.
 * 
 * @param kEtiqueta La etiqueta que se almacenará en la tabla_etiqueta_valor_.
 * @throw Lanza una excepción si encuentra dos etiquetas con el mismo nombre. 
 */
void CargarPrograma::AlmacenarEtiqueta(const std::string& kEtiqueta) {
  const std::string kError = "No se puede ejecutar el programa si"
                             " hay 2 o más etiquetas repetidas.";
  auto iterador = tabla_etiqueta_valor_.find(kEtiqueta);
  if (iterador != tabla_etiqueta_valor_.end()) throw (kError); // No pueden existir 2 etiquetas iguales 
  int valor = 0; // Si no hay ninguna etiqueta su pos es 0, si no es el tamaño del vector de instrucciones
  if (!tabla_instrucciones_.empty()) valor = tabla_instrucciones_.size();
  tabla_etiqueta_valor_[kEtiqueta] = valor;
}

/**
 * @brief Construirá la instrucción y la almacenará
 * 
 * @param kInstruccion La instrucción que se va a guardar en tabla_instrucciones_
 */
void CargarPrograma::AlmacenarInstruccion(const std::string& kInstruccion) {
  std::string kInstruccionSinComas = kInstruccion;
  std::replace(kInstruccionSinComas.begin(), kInstruccionSinComas.end(), ',', '.');
  // Construye la instrucción
  Instruccion palabras_instruccion(kInstruccionSinComas);
  // Si no está vacía la almacena
  if (!palabras_instruccion.get_instruccion().empty()) {
    tabla_instrucciones_.push_back(palabras_instruccion);
    GuardaPosInstruccionDelFichero();
  }
}

/**
 * @brief Guarda cuál es la posición equivalente de la instrucción en el fichero
 *        es decir, la línea del fichero
 */
void CargarPrograma::GuardaPosInstruccionDelFichero() {
  direcciones_fichero_.push_back(puntero_fichero_);
}

/**
 * @brief Cuando la instrucción es alguna de salto, busca en la tabla_etiqueta_valor_
 *        si encuentra el valor de la etiqueta a la que saltar. Si no la encuentra
 *        le pone un =-1 si la encuentra le pone el valor que tenía almacenado tabla_etiqueta_valor_
 * 
 */
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