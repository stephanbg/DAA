#pragma once

#include <iostream>
#include <vector>
#include <fstream>

class CintaOut {
 public:
  const int get_puntero() const { return puntero_; }
  int& set_puntero() { return puntero_; } 
  const std::vector<long double>& get_cinta() const { return cinta_; }
  std::vector<long double>& set_cinta() { return cinta_; }
  void MeterEnFichero(const std::string&);
  friend std::ostream& operator<<(std::ostream&, const CintaOut&);
 private:
  std::vector<long double> cinta_;
  int puntero_;
};