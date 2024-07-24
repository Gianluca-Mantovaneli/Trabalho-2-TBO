#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    // Leitura do arquivo de entrada

    FILE *file = fopen(argv[1], "r");
    int V, E;    // V = número de vértices, E = número de arestas
    int S, C, M; // S = número de servidores, C = número de clientes, M = número de monitores

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo de entrada\n");
        return 1;
    }

    char line[100];
    int contadorDeLinhas = 0;
    char *token;
    int arraryS[S];
    int arraryC[C];
    int arraryM[M];

    while (fgets(line, sizeof(line), file) != NULL) // Lê o arquivo linha por linha
    {
        contadorDeLinhas++;
        if (contadorDeLinhas == 1) // Lê a primeira linha do arquivo e atribui os valores de V e E
        {
            token = strtok(line, " ");
            V = atoi(token);
            token = strtok(NULL, " ");
            E = atoi(token);
        }
        else if (contadorDeLinhas == 2)
        {
            token = strtok(line, " ");
            S = atoi(token);
            token = strtok(NULL, " ");
            C = atoi(token);
            token = strtok(NULL, " ");
            M = atoi(token);
        }
        else if (contadorDeLinhas < (S + 3) && contadorDeLinhas >= 3)
        {
            arraryS[contadorDeLinhas - 3] = atoi(line);
        }
        else if (contadorDeLinhas < (S + C + 3) && contadorDeLinhas >= S + 3)
        {
            arraryC[contadorDeLinhas - 3 - S] = atoi(line);
        }
        else if (contadorDeLinhas < (S + C + M + 3) && contadorDeLinhas >= S + C + 3)
        {
            arraryM[contadorDeLinhas - 3 - S - C] = atoi(line);
        }
        else
        {
            /* code */
        }
    }
    printf("V = %d\nE = %d\n", V, E);
    for (int i = 0; i < S; i++)
    {
        printf("S[%d] = %d\n", i, arraryS[i]);
    }
    for (int i = 0; i < C; i++)
    {
        printf("C[%d] = %d\n", i, arraryC[i]);
    }
    for (int i = 0; i < M; i++)
    {
        printf("M[%d] = %d\n", i, arraryM[i]);
    }

    fclose(file);
    return 0;
}
