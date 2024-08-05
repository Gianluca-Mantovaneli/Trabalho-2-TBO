#include "inAndOut.h"

void LeituraArquivo(const char *entradaPath)
{
    // Leitura do arquivo de entrada
    FILE *file = fopen(entradaPath, "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo de entrada\n");
        return;
    }

    int V, E;    // V = número de vértices, E = número de arestas
    int S, C, M; // S = número de servidores, C = número de clientes, M = número de monitores

    char line[100];
    int contadorDeLinhas = 0;
    char *token;

    // Lendo a primeira linha para obter V e E
    if (fgets(line, sizeof(line), file) != NULL)
    {
        token = strtok(line, " ");
        V = atoi(token);
        token = strtok(NULL, " ");
        E = atoi(token);
        contadorDeLinhas++;
    }

    // Lendo a segunda linha para obter S, C e M
    if (fgets(line, sizeof(line), file) != NULL)
    {
        token = strtok(line, " ");
        S = atoi(token);
        token = strtok(NULL, " ");
        C = atoi(token);
        token = strtok(NULL, " ");
        M = atoi(token);
        contadorDeLinhas++;
    }

    // Declarando arrays para S, C e M após conhecer seus tamanhos
    // TODO: Armazenar isso em uma outra biblioteca grafoListaAdjacencias.h Alem do valores de S, C e M e dos arrays, armazenar também o grafo
    int arraryS[S];
    int arraryC[C];
    int arraryM[M];

    // Lendo as linhas seguintes para preencher os arrays S, C e M
    while (fgets(line, sizeof(line), file) != NULL)
    {
        contadorDeLinhas++;
        if (contadorDeLinhas < (S + 3) && contadorDeLinhas >= 3)
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
    }

    // Exibindo os valores lidos
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
}
