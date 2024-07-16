# Nome do arquivo de saída
TARGET = trab2

# Compilador
CC = gcc

# Opções de compilação
CFLAGS = -Wall -Wpedantic

# Arquivos fonte
SOURCES = main.c

# Objetos gerados
OBJECTS = $(SOURCES:.c=.o)

# Regra de compilação
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Regra de compilação dos objetos
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra de limpeza
clean:
	rm -f $(OBJECTS) $(TARGET)

run:
	./$(TARGET)