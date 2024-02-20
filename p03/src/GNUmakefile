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

CXX = g++
CXXFLAGS = -std=c++17 -g
LDFLAGS =

all: main

main: main.o comprobar_parametros/comprobar_parametros.o funciones/funciones_necesarias.o cintas/cinta_in.o cintas/cinta_out.o cargar_programa/cargar_programa.o instruccion/instruccion.o memoria_programa/memoria_programa.o memoria_datos/memoria_datos.o alu/alu.o operaciones/load/load.o operaciones/adv/adv.o operaciones/store/store.o operaciones/add/add.o operaciones/sub/sub.o operaciones/mul/mul.o operaciones/div/div.o operaciones/read/read.o operaciones/write/write.o operaciones/jump/jump.o operaciones/jzero/jzero.o operaciones/jgtz/jgtz.o operaciones/halt/halt.o operando/operando_constante/operando_constante.o operando/operando_directo/operando_directo.o operando/operando_directo_vectorial/operando_directo_vectorial.o operando/operando_indirecto/operando_indirecto.o estrategia_almacenamiento/estrategia_almacenamiento_unico.o estrategia_almacenamiento/estrategia_almacenamiento_dinamico.o debug/debug_2.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: all clean
	$(CXX) $(CXXFLAGS) -c $<

clean :
	find . -name '*.o' -type f -delete
	rm -rf *~ basura b i
	rm -rf a.out main
	find . -name '*~' -exec rm {} \;
	find . -name basura -exec rm {} \;