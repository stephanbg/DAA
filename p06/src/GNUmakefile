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

main: main.o comprobar_parametros/comprobar_parametros.o grafo/grafoNoDirigidoCompleto.o sintaxis_fichero_grafo/sintaxis_fichero_grafo.o TSP/tsp.o TSP/voraz_tsp.o TSP/fuerza_bruta_tsp.o TSP/programacion_dinamica_tsp.o funciones/funciones.o funciones/peticionesUsuario.o generador_instancias_aleatorias/generador_instancias_aleatorias.o tablaResultadosTSP/tablaResultadosTSP.o controlTiempo/controlTiempo.o
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