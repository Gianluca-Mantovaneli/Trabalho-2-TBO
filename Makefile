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

# Argumentos
ARGS1 =  Exemplos/entradas/N10_S3_C3_M3.txt saida1.txt
ARGS2 =  Exemplos/entradas/N100_S20_C30_M5.txt saida2.txt
ARGS3 =  Exemplos/entradas/N1000_S50_C300_M10.txt saida3.txt
ARGS4 =  Exemplos/entradas/N10000_S50_C300_M10.txt saida4.txt

# Regra de compilação
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Regra de compilação dos objetos
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regra de limpeza
clean:
	rm -f $(OBJECTS) $(TARGET) $(TARGET)_debug

# Regra para gerar o arquivo de debug
debug:
		$(CC) $(CFLAGS) -g $(SOURCES) -o $(TARGET)_debug
# Regra para executar o programa
run1:
	./$(TARGET) $(ARGS1)
run2:
	./$(TARGET) $(ARGS2)
run3:
	./$(TARGET) $(ARGS3)
run4:
	./$(TARGET) $(ARGS4)
