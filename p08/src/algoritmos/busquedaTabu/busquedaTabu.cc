#include "busquedaTabu.h"

Solucion BusquedaTabu::ejecutar(const Problema& kProblema, const int kNumElementosEnSolucion, const int kIteraciones) {  
  GRASP algortimoGRASP;
  const Solucion& kMejorSolucion = algortimoGRASP.ejecutar(kProblema, kNumElementosEnSolucion, kIteraciones);
  std::pair<Matriz, std::vector<int>> elementos_restantes = obtenerElementosFueraDeSolucion(kProblema, kMejorSolucion);
  const int kTenenciaTabu = 3, kIteracionesTabu = 10;
  busquedaTabu(kMejorSolucion, elementos_restantes, kProblema.getDistancias(), kTenenciaTabu, kIteracionesTabu);
  return solucion_;
}

void BusquedaTabu::busquedaTabu(
  const Solucion& kSolucionInicial,
  std::pair<Matriz, std::vector<int>>& elementos_restantes,
  const Matriz& kDistancias,
  const int kTenenciaTabu,
  const int kIteracionesTabu
) { 
  std::pair<Matriz, std::vector<int>> cada_elementos_restantes = elementos_restantes, mejor_elementos_restantes;
  Solucion mejor_solucion = kSolucionInicial, cada_solucion_inicial = kSolucionInicial;
  double criterio_aspiracion = kSolucionInicial.getFuncionObjetivo(), funcion_objetivo_actual;
  const int kSizeElementosRestantes = elementos_restantes.first.size();
  const int kSizeElementosSolucion = kSolucionInicial.size();
  int mejor_indice_solucion, mejor_indice_entorno, iter = 0;
  std::list<std::pair<int, int>> lista_tabu;
  do {
    for (int i = 0; i < kSizeElementosSolucion; ++i) {
      for (int j = 0; j < kSizeElementosRestantes; ++j) {
        const int kIndiceEnSolucion = cada_solucion_inicial.getIndicesElementosIntroducidos()[i];
        const int kIndiceEnEntorno = elementos_restantes.second[j];        
        if (contienePar(lista_tabu, std::make_pair(kIndiceEnSolucion, kIndiceEnEntorno))) continue;
        solucion_ = cada_solucion_inicial;
        elementos_restantes = cada_elementos_restantes;
        solucion_.swapPuntoEIndice(i, j, elementos_restantes);    
        funcion_objetivo_actual = calcularFuncionObjetivoParcial(cada_solucion_inicial, i, kDistancias);
        if (criterio_aspiracion < funcion_objetivo_actual) {   
          criterio_aspiracion = funcion_objetivo_actual;
          mejor_solucion = solucion_;
          mejor_indice_solucion = kIndiceEnSolucion;
          mejor_indice_entorno = kIndiceEnEntorno;
          mejor_elementos_restantes = elementos_restantes;
        }
      }
    }
    if (criterio_aspiracion > cada_solucion_inicial.getFuncionObjetivo()) {
      cada_solucion_inicial = mejor_solucion;
      cada_elementos_restantes = mejor_elementos_restantes;
    } else break;
    if (lista_tabu.size() == kTenenciaTabu) lista_tabu.pop_front();
    lista_tabu.push_back(std::make_pair(mejor_indice_solucion, mejor_indice_entorno));    
  } while (++iter <= kIteracionesTabu);
  solucion_ = mejor_solucion;
  solucion_.setFuncionObjetivo() = criterio_aspiracion;
}

std::pair<Matriz, std::vector<int>> BusquedaTabu::obtenerElementosFueraDeSolucion(
  const Problema& kProblema,
  const Solucion& kMejorSolucion
) const {
  Matriz cada_elemento_matriz;
  std::vector<int> cada_elemento_indice;
  const std::vector<int>& kIndicesIntroducidos = kMejorSolucion.getIndicesElementosIntroducidos();
  const int kSizeIndicesEnSolucion = kIndicesIntroducidos.size();
  for (const int& kIndiceProblema : kProblema.getIndicesProblema()) {
    bool esta_en_solucion = false;
    for (int i = 0; i < kSizeIndicesEnSolucion; ++i) {
      if (kIndicesIntroducidos[i] == kIndiceProblema) {
        esta_en_solucion = true;
        break;
      }
    }
    if (!esta_en_solucion) {
      cada_elemento_matriz.setMatriz().push_back(kProblema.getCoordenadas()[kIndiceProblema]);
      cada_elemento_indice.push_back(kIndiceProblema);
    }
  }
  return std::make_pair(cada_elemento_matriz, cada_elemento_indice);
}