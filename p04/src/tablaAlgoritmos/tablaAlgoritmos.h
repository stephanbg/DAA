#pragma once

#include <vector>
#include <iostream>
#include <fstream>

class TablaAlgoritmos {
 public:
   void peticionUsuario() const;
   std::vector<int>& setSizeInstancias() { return sizeInstancias_; }
   std::vector<std::vector<double>>& setTiempoAlgoritmos() { return tiempoAlgoritmos_; }
   std::vector<std::vector<std::string>>& setNombresAlgoritmos() { return nombresAlgoritmos_; }
 private:
   std::vector<int> sizeInstancias_;
   std::vector<std::vector<double>> tiempoAlgoritmos_;
   std::vector<std::vector<std::string>> nombresAlgoritmos_;
   void imprimirTabla() const;
   void meterEnFicheroTabla() const;
};