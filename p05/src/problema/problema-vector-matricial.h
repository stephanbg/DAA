#pragma once

#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "problema.h"

/**
 * @brief La clase ProblemaVectorial representa un problema vectorial.
 * Hereda de la clase Problema y proporciona funcionalidades
 * específicas para manipular vectores de enteros.
 */
class ProblemaVectorMatricial: public Problema<std::vector<std::vector<std::vector<int>>>> {
 public:
  /**
   * @brief Constructor de problemas aleatorios
   * @param generarAleatorio Si se indica como true se genera aleatorio
   *     el problema, si no está vacío
   */
  ProblemaVectorMatricial(const int kCantidadMatrices) { 
    problema_.resize(kCantidadMatrices);
  } 
  // Getters y Setters
  virtual const std::vector<std::vector<std::vector<int>>>& getProblema() const override { return problema_; }
  virtual std::vector<std::vector<std::vector<int>>>& setProblema() override { return problema_; }
  virtual void mostrarProblema() const override;
  void meterValores(const std::vector<std::vector<std::vector<int>>>&);
 private:
  std::vector<std::vector<std::vector<int>>> problema_{};
};