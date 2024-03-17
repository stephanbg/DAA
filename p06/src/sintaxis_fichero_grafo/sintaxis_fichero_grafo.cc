#include "sintaxis_fichero_grafo.h"

const bool SintaxisFicheroGrafo::numeroNodosValido(const std::string& kNumNodosDeFichero) {
  if (kNumNodosDeFichero.empty()) return false;
  if (!esNumeroEnteroSinSigno(kNumNodosDeFichero)) return false;
  if (stoi(kNumNodosDeFichero) < 2) return false; // Con menos de 2 nodos no se puede formar 1 grafo 
  return true;
}

const bool SintaxisFicheroGrafo::tresElementosPorLineaNodo1Nodo2Coste(
  const std::vector<std::string>& cada_linea
) {
  if (cada_linea.size() != 3) return false;
  if (!esNumeroSinSigno(cada_linea[2])) return false; // Coste numero positivo
  if (stold(cada_linea[2]) == 0) return false; // No puede ser 0
  return true;
}