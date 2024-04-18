#include "voraz.h"

Solucion Voraz::ejecutar(const Problema& kProblema) {
  Matriz elementos = kProblema.getCoordenadas();
  const Matriz& distancias = kProblema.getDistancias();
  Solucion solucion;
  std::vector<double> cada_centro_gravedad = centroGravedad(elementos);
  double funcion_objetivo_anterior = 0.0;
    std::cout << "cada_centro_gravedad: ";
    for (auto a : cada_centro_gravedad) {
      std::cout << a << ", ";
    }
    std::cout << std::endl;  
  do {
    const std::vector<double> kCadaElementoMasLejano = (
      obtenerElementoMasAlejadoDeCentroGravedad(cada_centro_gravedad, elementos)
    );
    std::cout << "kCadaElementoMasLejano: ";
    for (auto a : kCadaElementoMasLejano) {
      std::cout << a << ", ";
    }
    std::cout << std::endl;
    const int kIndiceElementoMasLejano = kProblema.getIndiceElemento(kCadaElementoMasLejano);
    if (funcion_objetivo_anterior < maximizarFuncionObjetivo(solucion, distancias, kIndiceElementoMasLejano)) {
      funcion_objetivo_anterior = funcion_objetivo_;
      solucion.añadirElemento(kCadaElementoMasLejano);
      solucion.setIndicesElementosIntroducidos(kIndiceElementoMasLejano);
      elementos.eliminarElemento(kCadaElementoMasLejano);
      cada_centro_gravedad = centroGravedad(solucion.getCoordenadas());
      exit(1);
    } else {
      funcion_objetivo_ = funcion_objetivo_anterior;
      break; // Si no se ha podido maximizar
    }
  } while (!elementos.empty());
  return solucion;
}
