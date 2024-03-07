#pragma once

#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "solucion.h"

/**
 * @brief La clase ProblemaVectorial representa un problema vectorial.
 * Hereda de la clase Problema y proporciona funcionalidades
 * específicas para manipular vectores de enteros.
 */
class SolucionMatricial: public Solucion<std::vector<std::vector<int>>> {
 public:
  // Getters y Setters
  virtual const std::vector<std::vector<int>>& getSolucion() const override { return solucion_; }
  virtual std::vector<std::vector<int>>& setSolucion() override { return solucion_; }
  virtual void mostrarSolucion() const override;
 private:
  std::vector<std::vector<int>> solucion_{};
};