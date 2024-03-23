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

all: main clear

main: main.o grafo/grafoDirigidoCompleto.o sintaxis_fichero_grafo/sintaxis_fichero_grafo.o maquina/maquina.o algoritmos_min_TCT/algoritmo_constructivo_voraz_TCT.o funciones/funciones.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: all clean
	$(CXX) $(CXXFLAGS) -c $<

clear:
	rm -rf *.o
	rm -rf **/*.o

clean :
	find . -name '*.o' -type f -delete
	rm -rf *~ basura b i
	rm -rf a.out main
	find . -name '*~' -exec rm {} \;
	find . -name basura -exec rm {} \;