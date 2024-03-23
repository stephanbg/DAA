#pragma once

#include <fstream>
#include <filesystem>

#include "../nodo/nodo.h"

namespace fs = std::filesystem;

class Maquina {
 public:
  static void cuantasMaquinasACrear(const std::string&);
  void crearPrimeraTarea(const Nodo* kTarea) { tareas_.push_back(kTarea); };
  void insertarTarea(const Nodo* kTarea, const int kPos) {
    if (kPos >= 0 && kPos <= tareas_.size()) tareas_.insert(tareas_.begin() + kPos, kTarea);
    else {
      std::string error = "La posición de inserción está fuera del rango válido";
      throw (error);
    }
  }
  const std::vector<const Nodo*> getTareas() const { return tareas_; }
  static const int getNumeroMaquinas() { return numero_maquinas_; }
 private:
  std::vector<const Nodo*> tareas_;
  static int numero_maquinas_;
};