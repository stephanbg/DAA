#pragma once
#include <vector>
#include <iostream>

class Matriz {
  public:
    Matriz();
    Matriz(std::vector<std::vector<long int>>& matriz) : matriz_(matriz) {}
    const std::vector<std::vector<long int>>& getMatriz() const { return matriz_; }
    friend std::ostream& operator<<(std::ostream&, const Matriz&);
  private:
    std::vector<std::vector<long int>> matriz_{};
};