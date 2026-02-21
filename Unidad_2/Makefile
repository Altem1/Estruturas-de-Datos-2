# Define el compilador que usas
CC = clang

# Banderas de compilación (-Wall muestra advertencias, -g es para poder debugear)
CFLAGS = -Wall -g

# ¡La magia! Busca automáticamente TODOS los archivos .c en la carpeta
SRC = $(wildcard *.c)

# El nombre del ejecutable que quieres generar
TARGET = pract.out

# Regla principal
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Regla para limpiar la carpeta (borrar el ejecutable)
clean:
	rm -f $(TARGET)