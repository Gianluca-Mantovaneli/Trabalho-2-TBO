# Nome do arquivo de saída
TARGET = programa

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -Wpedantic

# Diretórios das bibliotecas
LIB_DIRS = -L/path/to/library1 -L/path/to/library2

# Bibliotecas extras
LIBS = -llibrary1 -llibrary2 -lm

# Arquivos fonte
SOURCES = main.c arquivo1.c arquivo2.c

# Objetos gerados
OBJECTS = $(SOURCES:.c=.o)

# Regra de compilação
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(LIB_DIRS) -o $(TARGET) $(OBJECTS) $(LIBS)

# Regra de compilação dos objetos
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra de limpeza
clean:
	rm -f $(OBJECTS) $(TARGET)