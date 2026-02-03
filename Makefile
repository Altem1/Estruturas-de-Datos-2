# Variables para el compilador y banderas
CC = gcc
CFLAGS = -Wall -g

# Lista de archivos ejecutables que queremos generar
TARGETS = arreglo_1d arreglo_2d arreglo puntero

# Regla principal: compila todos los objetivos
all: $(TARGETS)

# Reglas específicas para cada archivo
arreglo_1d: Arreglo\ 1D.c
	$(CC) $(CFLAGS) -o arreglo_1d "Arreglo 1D.c"

arreglo_2d: Arreglo\ 2D.c
	$(CC) $(CFLAGS) -o arreglo_2d "Arreglo 2D.c"

arreglo: Arreglo.c
	$(CC) $(CFLAGS) -o arreglo Arreglo.c

puntero: Puntero.c
	$(CC) $(CFLAGS) -o puntero Puntero.c

# Regla para limpiar los archivos ejecutables creados
clean:
	rm -f $(TARGETS)
