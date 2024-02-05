#pragma once

#include <iostream>
#include <sstream>
#include <queue>
#include <string>
#include <fstream>
#include <iomanip>

class CintaIn {
 public:
  CintaIn(const std::string&);
  const std::queue<long double>& get_cinta() const { return cinta_; }
  std::queue<long double>& set_cinta() { return cinta_; }
  friend std::ostream& operator<<(std::ostream&, const CintaIn&);
 private:
  std::queue<long double> cinta_;
  void RellenarCola(const std::string&);
};