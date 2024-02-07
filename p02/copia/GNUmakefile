# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Asignatura: DISEÑO Y ANÁLISIS DE ALGORITMOS
# Curso: 3º
# Práctica 2: Simulador máquina RAM
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

main: main.o comprobar_parametros/comprobar_parametros.o funciones/funciones_necesarias.o cintas/cinta_in.o cintas/cinta_out.o cargar_programa/cargar_programa.o instruccion/instruccion.o memoria_programa/memoria_programa.o memoria_datos/memoria_datos.o alu/alu.o operaciones/add/add.o operaciones/div/div.o operaciones/halt/halt.o operaciones/jgtz/jgtz.o operaciones/jump/jump.o operaciones/jzero/jzero.o operaciones/load/load.o operaciones/mul/mul.o operaciones/read/read.o operaciones/store/store.o operaciones/sub/sub.o operaciones/write/write.o 
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: all clean
	$(CXX) $(CXXFLAGS) -c $<

clean :
	find . -name '*.o' -type f -delete
	rm -rf *~ basura b i
	rm -rf a.out main
	find . -name '*~' -exec rm {} \;
	find . -name basura -exec rm {} \;