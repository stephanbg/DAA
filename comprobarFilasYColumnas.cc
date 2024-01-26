#include "comprobarFilasYColumnas.h"

bool ComprobarFilasYColumnas::ComprobarErrorEnSize(const Matriz& matriz1, const Matriz& matriz2) {
  if (matriz1.getMatriz()[0].size() == matriz2.getMatriz().size()) {
    return EXIT_SUCCESS;
  }
  return EXIT_FAILURE;
}