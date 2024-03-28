#pragma once

#include <iostream>
#include <fstream>
#include <filesystem>
#include <algorithm>

#include "../nodo/nodo.h"

namespace fs = std::filesystem;

class Maquina {
 public:
  Maquina() { maquinas_.push_back(this); } 
  static void cuantasMaquinasACrear(const std::string&);
  void añadirTarea(const Nodo* kTarea) { tareas_.push_back(kTarea); };
  void insertarTarea(const Nodo* kTarea, const int kPos) {
    if (kPos >= 0 && kPos <= tareas_.size()) tareas_.insert(tareas_.begin() + kPos, kTarea);
    else {
      std::string error = "La posición de inserción está fuera del rango válido";
      throw (error);
    }
  }
  void cambiarTarea(const Nodo* kTarea, const int kPos) {
    if (kPos >= 0 && kPos <= tareas_.size()) tareas_[kPos] = kTarea;
    else {
      std::string error = "La posición para cambiar la tarea está fuera del rango válido";
      throw (error);
    }
  }
  void eliminarTarea(const Nodo* tarea) {
    auto it = std::find(tareas_.begin(), tareas_.end(), tarea);
    if (it != tareas_.end()) {
        tareas_.erase(it);
    }
  }  
  void limpiarTareas() { tareas_.clear(); }
  const std::vector<const Nodo*> getTareas() const { return tareas_; }
  const long long int getTCT() const { return tct_; }
  long long int& setTCT() { return tct_; }
  static const int getNumeroMaquinas() { return numero_maquinas_; }
  static void limpiarTareasDeTodasLasMaquinas();
  static void mostrarTareasDeTodasLasMaquinas();
 private:
  static std::vector<Maquina*> maquinas_;
  static int numero_maquinas_;
  std::vector<const Nodo*> tareas_;
  long long int tct_ = 0;
};