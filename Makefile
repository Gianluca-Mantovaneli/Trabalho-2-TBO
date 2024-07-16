# Nome do arquivo de saída
TARGET = Bin/trab2

# Compilador
CC = gcc

# Opções de compilação
CFLAGS = -Wall -Wpedantic

# Diretórios
SRCDIR = Sources
OBJDIR = Objects
BINDIR = Bin

# Arquivos fonte
SOURCES = $(wildcard $(SRCDIR)/*.c)

# Objetos gerados
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))

# Regra de compilação
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Regra de compilação dos objetos
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra de limpeza
clean:
	rm -f $(OBJECTS) $(TARGET)

run:
	./$(TARGET)