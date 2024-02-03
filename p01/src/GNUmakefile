# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Asignatura: DISEÑO Y ANÁLISIS DE ALGORITMOS
# Curso: 3º
# Práctica 1: Análisis de complejidad
# Autor: Stephan Brommer Gutiérrez
# Correo: alu0101493497@ull.es
# Fecha: 30/01/2024
# Archivo GNUMakefile
#
# Historial de revisiones
# 24/01/2023 - Creación (primera versión) del código

CXX = g++
CXXFLAGS = -std=c++17 -g
LDFLAGS =

all: main

main: main.o matriz.o multiplicar_por_filas.o multiplicar_por_columnas.o funciones_necesarias.o comprobar_filas_columnas.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: all clean
	$(CXX) $(CXXFLAGS) -c $<

clean :
	rm -rf *.o main matriz multiplicar_por_filas multiplicar_por_columnas funciones_necesarias comprobar_filas_columnas ../doc
	rm -rf *~ basura b i
	rm -rf a.out
	find . -name '*~' -exec rm {} \;
	find . -name basura -exec rm {} \;