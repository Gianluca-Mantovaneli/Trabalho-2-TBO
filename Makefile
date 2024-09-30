# Nome do arquivo de saída
TARGET = Bin/trab2

# Compilador
CC = gcc

# Opções de compilação
CFLAGS =  

# Diretórios
SRCDIR = Sources
OBJDIR = Objects
BINDIR = Bin

# Arquivos fonte
SOURCES = $(wildcard $(SRCDIR)/*.c)

# Objetos gerados
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))

# Argumentos
ARGS1 =  Entradas/N10_S3_C3_M3.txt soluções/saida1.txt
ARGS2 =  Entradas/N100_S20_C30_M5.txt soluções/saida2.txt
ARGS3 =  Entradas/N1000_S50_C300_M10.txt soluções/saida3.txt
ARGS4 =  Entradas/N10000_S50_C300_M10.txt soluções/saida4.txt

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

run1_valgrind:
	valgrind --leak-check=full ./$(TARGET) $(ARGS1)
run2_valgrind:
	valgrind --leak-check=full ./$(TARGET) $(ARGS2)
run3_valgrind:
	valgrind --leak-check=full ./$(TARGET) $(ARGS3)
run4_valgrind:
	valgrind --leak-check=full ./$(TARGET) $(ARGS4)
