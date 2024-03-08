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

main: main.o funcionesNecesarias/funcionesNecesarias.o debug/debug.o debug/modoNormal.o debug/modoDepurador.o introducirDatosEnConjunto/introducirDatosEnConjunto.o problema/problema-vectorial.o problema/problema-vector-matricial.o solucion/solucion-vectorial.o framework/algoritmoDyV.o framework/algoritmoDyVAccion.o algoritmos-DyV/mergesort.o algoritmos-DyV/quicksort.o algoritmos-DyV/busqueda_binaria.o algoritmos-DyV/hanoi.o algoritmos-DyV/strassen.o problema/problema-vector-pilas.o solucion/solucion-pila.o solucion/solucion-matricial.o tablaAlgoritmos/tablaAlgoritmos.o calculos/calculos.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: all clean
	$(CXX) $(CXXFLAGS) -c $<

clean :
	find . -name '*.o' -type f -delete
	rm -rf *~ basura b i
	rm -rf a.out main
	find . -name '*~' -exec rm {} \;
	find . -name basura -exec rm {} \;