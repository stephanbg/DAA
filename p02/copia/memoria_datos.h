#pragma once

#include <iostream>
#include <vector>

class MemoriaDatos {
 public:
  MemoriaDatos(const int kNumeroRegistros) : registros_(kNumeroRegistros, 0) {}
  friend std::ostream& operator<<(std::ostream&, const MemoriaDatos&);
 private:
  std::vector<int> registros_;
};