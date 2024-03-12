/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Stephan Brommer Gutiérrez
 * @since 6 de marzo de 2024
 * @file strassen.h
 * @brief Definición de la clase Strassen, que se encarga de
 * realizar dicho algoritmo
 * @see {@link https://github.com/stephanbg/DAA/tree/main/p05/src}
 * @see {@link https://docs.google.com/document/d/1pwPk5iI5dRHo8M-raauPP5mgCUHy9m9j_au3UDkn_Rc/edit}
 */

#pragma once

#include "../framework/algoritmoDyV.h"
#include "../problema/problema-vector-matricial.h"
#include "../solucion/solucion-matricial.h"

/**
 * @brief Clase Strassen, hereda de AlgoritmoDyV
 * Recibiendo como plantilla un problema vectorial de matrices y
 * devuelve una solución matricial
 */
class Strassen: public AlgoritmoDyV<std::vector<std::vector<std::vector<int>>>, std::vector<std::vector<int>>> {
 private:
  virtual bool Small(const Problema<std::vector<std::vector<std::vector<int>>>>*) const override;
  virtual Solucion<std::vector<std::vector<int>>>* SolveSmall(const Problema<std::vector<std::vector<std::vector<int>>>>*) const override;
  virtual const std::vector<Problema<std::vector<std::vector<std::vector<int>>>>*> Divide(
      const Problema<std::vector<std::vector<std::vector<int>>>>*, const int) const override;
  virtual Solucion<std::vector<std::vector<int>>>* Combine(
      const std::vector<const Solucion<std::vector<std::vector<int>>>*>&) const override;
  virtual const std::string getA() const override { return "7"; }
  virtual const std::string getB() const override { return "n/2"; }
  virtual const std::string getC() const override { return "n^2"; }  
};