#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

class CintaIn {
 public:
  CintaIn(const std::string&);
  const int get_puntero() const { return puntero_; }
  int& set_puntero() { return puntero_; }
  const std::vector<long double>& get_cinta() const { return cinta_; }
  std::vector<long double>& set_cinta() { return cinta_; }
  friend std::ostream& operator<<(std::ostream&, const CintaIn&);
 private:
  std::vector<long double> cinta_;
  int puntero_;
  void RellenarVector(const std::string&);
};