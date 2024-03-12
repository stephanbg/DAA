#include "strassen.h"

bool Strassen::Small(const Problema<std::vector<std::vector<std::vector<int>>>>* kProblema) const {
  // Si son 2 matrices de tamaño 1 x 1 son pequeñas par ahacer A x B
  return (kProblema->getProblema()[0].size() == 2);
}

Solucion<std::vector<std::vector<int>>>* Strassen::SolveSmall(const Problema<std::vector<std::vector<std::vector<int>>>>* kProblema) const {
  // Resolver el problema pequeño directamente
  Solucion<std::vector<std::vector<int>>>* solucion = new SolucionMatricial(2, 2);
  // Obtener las dos submatrices
  const auto& matrices = kProblema->getProblema();
  const auto& submatriz1 = matrices[0];
  const auto& submatriz2 = matrices[1];
  // Calcular los 7 subproblemas
  int p1, p2, p3, p4, p5, p6, p7;
  int A = matrices[0][0][0];
  int B = matrices[0][0][1];
  int C = matrices[0][1][0];
  int D = matrices[0][1][1];
  int E = matrices[1][0][0];
  int F = matrices[1][0][1];
  int G = matrices[1][1][0];
  int H = matrices[1][1][1];
  p1 = A * (F - H);
  p2 = (A + B) * H;
  p3 = (C + D) * E;
  p4 = D * (G - E);
  p5 = (A + D) * (E + H);
  p6 = (B - D) * (G + H);
  p7 = (A - C) * (E + F);
  // Agregar los resultados al objeto Solucion
  solucion->setSolucion()[0][0] = p5 + p4 - p2 + p6;
  solucion->setSolucion()[0][1] = p1 + p2;
  solucion->setSolucion()[1][0] = p3 + p4;
  solucion->setSolucion()[1][1] = p1 + p5 - p3 - p7;
  return solucion;
}

const std::vector<Problema<std::vector<std::vector<std::vector<int>>>>*> Strassen::Divide(
    const Problema<std::vector<std::vector<std::vector<int>>>>* kProblema,
    const int kSize) const {
  Problema<std::vector<std::vector<std::vector<int>>>>* problema = new ProblemaVectorMatricial;
  problema->setProblema() = kProblema->getProblema();
  auto& matrices = problema->setProblema();
  const std::vector<int> kFilasColumnasCeros(matrices[0].size(), 0);
  const int kCantidadMatrices = matrices.size();
  for (int i = 0; i < matrices.size(); ++i) {
    if (matrices[i].size() % 2 != 0)  { // Filas impares
      matrices[i].push_back(kFilasColumnasCeros);
    }
    if (matrices[i][0].size() % 2 != 0)  { // Columnas impares
      for (int j = 0; j < matrices[i].size(); ++j) {
        matrices[i][j].push_back(0);
      }
    }
  }
  const int kCantidadSubProblemas = kCantidadMatrices * 4;
  std::vector<Problema<std::vector<std::vector<std::vector<int>>>>*> subproblemas(kCantidadSubProblemas);
  for (int i = 0; i < kCantidadSubProblemas; ++i) {
    subproblemas[i] = new ProblemaVectorMatricial;
  }
  int filas, columnas, mitadFilas, mitadColumnas, posCadaSubmatriz = 0;
  for (int i = 0; i < kCantidadMatrices; ++i) {
    const auto& kMatriz = matrices[i];
    filas = kMatriz.size();
    columnas = kMatriz[0].size();
    mitadFilas = filas / 2;
    mitadColumnas = columnas / 2;
    // Dividir la matriz en cuatro submatrices
    std::vector<std::vector<int>> submatriz_superior_izquierda(mitadFilas, std::vector<int>(mitadColumnas));
    std::vector<std::vector<int>> submatriz_superior_derecha(mitadFilas, std::vector<int>(mitadColumnas));
    std::vector<std::vector<int>> submatriz_inferior_izquierda(mitadFilas, std::vector<int>(mitadColumnas));
    std::vector<std::vector<int>> submatriz_inferior_derecha(mitadFilas, std::vector<int>(mitadColumnas));
    for (int i = 0; i < filas; ++i) {
      for (int j = 0; j < columnas; ++j) {
        if (i < mitadFilas && j < mitadColumnas) {
          submatriz_superior_izquierda[i][j] = kMatriz[i][j];
        } else if (i < mitadFilas && j >= mitadColumnas) {
          submatriz_superior_derecha[i][j - mitadColumnas] = kMatriz[i][j];
        } else if (i >= mitadFilas && j < mitadColumnas) {
          submatriz_inferior_izquierda[i - mitadFilas][j] = kMatriz[i][j];
        } else {
          submatriz_inferior_derecha[i - mitadFilas][j - mitadColumnas] = kMatriz[i][j];
        }
      }
    }
    std::vector<std::vector<std::vector<int>>> cuatroSubMatrices(4);
    cuatroSubMatrices[0] = (submatriz_superior_izquierda);
    cuatroSubMatrices[1] = (submatriz_superior_derecha);
    cuatroSubMatrices[2] = (submatriz_inferior_izquierda);
    cuatroSubMatrices[3] = (submatriz_inferior_derecha);
    // Crear un nuevo objeto de tipo Problema
    Problema<std::vector<std::vector<std::vector<int>>>>* problema_con_submatrices =
        new ProblemaVectorMatricial;
    problema_con_submatrices->setProblema() = cuatroSubMatrices;
    subproblemas[posCadaSubmatriz++]->setProblema().push_back(problema_con_submatrices->getProblema()[0]);
    subproblemas[posCadaSubmatriz++]->setProblema().push_back(problema_con_submatrices->getProblema()[1]);
    subproblemas[posCadaSubmatriz++]->setProblema().push_back(problema_con_submatrices->getProblema()[2]);
    subproblemas[posCadaSubmatriz++]->setProblema().push_back(problema_con_submatrices->getProblema()[3]);
  }
  std::vector<Problema<std::vector<std::vector<std::vector<int>>>>*> resultadoSubProblemas;
  const int kMitadRecorrido = (kCantidadSubProblemas / 2) / 2;
  for (int i = 0; i < kMitadRecorrido; ++i) {
    for (int j = 0; j < kMitadRecorrido; ++j) {
      for (int k = 0; k < kMitadRecorrido; ++k) {
        int indiceA = i * kMitadRecorrido + k;
        int indiceB = (kMitadRecorrido * kMitadRecorrido) + (k * kMitadRecorrido) + j;
        std::vector<std::vector<std::vector<std::vector<int>>>> cadaParMatrices(2);
        cadaParMatrices[0] = subproblemas[indiceA]->getProblema();
        cadaParMatrices[1] = subproblemas[indiceB]->getProblema();
        std::vector<std::vector<std::vector<int>>> cadaParAux(2);
        cadaParAux[0] = cadaParMatrices[0][0];
        cadaParAux[1] = cadaParMatrices[1][0];
        Problema<std::vector<std::vector<std::vector<int>>>>* cadaPar = new ProblemaVectorMatricial(2);
        cadaPar->setProblema() = cadaParAux;
        resultadoSubProblemas.push_back(cadaPar);          
        
      }
    }
  }
  return resultadoSubProblemas;
}

Solucion<std::vector<std::vector<int>>>* Strassen::Combine(
    const std::vector<const Solucion<std::vector<std::vector<int>>>*>& kSoluciones) const {
  // Crear una solución matriz del tamaño correcto
  const int kCantidadSolucionesParciales = kSoluciones.size();
  const int kFilaColumnas = kCantidadSolucionesParciales / 2;
  Solucion<std::vector<std::vector<int>>>* solucion =
      new SolucionMatricial(kFilaColumnas, kFilaColumnas);
  // Recorrer las soluciones parciales y calcular la solución final
  int contadorCuadrantes = 1, mitad = kFilaColumnas / 2;
  for (int i = 0; i < kCantidadSolucionesParciales; i += 2) {
    const auto& solucionParcialA = *kSoluciones[i];
    const auto& solucionParcialB = *kSoluciones[i + 1];
    const auto& matrizSolucionA = solucionParcialA.getSolucion();
    const auto& matrizSolucionB = solucionParcialB.getSolucion();
    // Sumar o restar la matriz de solución parcial a la matriz final
    for (int f = 0; f < matrizSolucionA.size(); ++f) {
      for (int c = 0; c < matrizSolucionA[f].size(); ++c) {
        int suma = matrizSolucionA[f][c] + matrizSolucionB[f][c];
        if (contadorCuadrantes == 1) { // cuadrante 1
          solucion->setSolucion()[f][c] = suma;
        } else if (contadorCuadrantes == 2) { // cuadrante 2
          solucion->setSolucion()[f][c + mitad] = suma;
        } else if (contadorCuadrantes == 3) { // cuadrante 3
          solucion->setSolucion()[f + mitad][c] = suma;
        } else { // cuadrante 4
          solucion->setSolucion()[f + mitad][c + mitad] = suma;
        }
      }
    }
    contadorCuadrantes++;   
  }
  return solucion;
}