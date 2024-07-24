#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    // Leitura do arquivo de entrada

    FILE *file = fopen(argv[1], "r");
    int V, E; // V = número de vértices, E = número de arestas

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo de entrada\n");
        return 1;
    }

    char line[100];
    int contadorDeLinhas = 0;
    char *token;

    while (fgets(line, sizeof(line), file) != NULL) // Lê o arquivo linha por linha
    {
        contadorDeLinhas++;
        if (contadorDeLinhas == 1) // Lê a primeira linha do arquivo onde fica V e E
        {
            token = strtok(line, " ");
            V = atoi(token);
            token = strtok(NULL, " ");
            E = atoi(token);
        }
    }

    fclose(file);
    return 0;
}
