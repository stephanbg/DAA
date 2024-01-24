#pragma once
#include <vector>

class Matriz {
  public:
    Matriz();
    virtual void ejecutarAlgoritmo() = 0;
    void imprimirMatriz() const;
  protected:
    std::vector<std::vector<int>> matriz_{};
};