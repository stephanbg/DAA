# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Asignatura: DISEÑO Y ANÁLISIS DE ALGORITMOS
# Curso: 3º
# Práctica 4: Framework DyV
# Autor: Stephan Brommer Gutiérrez
# Correo: alu0101493497@ull.es
# Fecha: 26/02/2024
# Archivo GNUMakefile

CXX = g++
CXXFLAGS = -std=c++17 -g
LDFLAGS =

all: main

main: main.o comprobar_parametros/comprobar_parametros.o sintaxis_fichero/sintaxis_fichero.o problema/problema.o tabla/tabla.o peticionesUsuario/peticionesUsuario.o solucion/solucion.o algoritmos_min_TCT/voraz/algoritmo_constructivo_voraz_TCT.o algoritmos_min_TCT/GRASP/algoritmo_GRASP_TCT.o algoritmos_min_TCT/GRASP/busquedaLocal/movimientoReInsercionInterGRASP.o algoritmos_min_TCT/GRASP/busquedaLocal/movimientoReInsercionIntraGRASP.o algoritmos_min_TCT/GRASP/busquedaLocal/movimientoSwapIntraGRASP.o algoritmos_min_TCT/GRASP/busquedaLocal/movimientoSwapInterGRASP.o funciones/funciones.o ejecutar_algoritmos/ejecutar_algoritmos.o algoritmos_min_TCT/GVNS/GVNS.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: all clean
	$(CXX) $(CXXFLAGS) -c $<

clean :
	find . -name '*.o' -type f -delete
	rm -rf *~ basura b i
	rm -rf a.out main
	find . -name '*~' -exec rm {} \;
	find . -name basura -exec rm {} \;