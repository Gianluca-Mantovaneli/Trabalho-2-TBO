#include "inAndOut.h"
#include "grafoListaDeAdjacencia.h"

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

    Grafo grafo = iniciaGrafo(V, E); // Inicializando a estrutura do grafo

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
    Filter filter = iniciaFilter(S, C, M);

    // Lendo as linhas seguintes para preencher os arrays S, C e M
    while (fgets(line, sizeof(line), file) != NULL)
    {
        contadorDeLinhas++;
        if (contadorDeLinhas < (S + 3) && contadorDeLinhas >= 3)
        {
            filter = insereInFilter(atoi(line), filter, 0);
        }
        else if (contadorDeLinhas < (S + C + 3) && contadorDeLinhas >= S + 3)
        {
            filter = insereInFilter(atoi(line), filter, 1);
        }
        else if (contadorDeLinhas < (S + C + M + 3) && contadorDeLinhas >= S + C + 3)
        {
            filter = insereInFilter(atoi(line), filter, 2);
        }
    }

    // Exibindo os valores lidos
    imprimeFilter(filter);

    // Destruindo as estruturas alocadas
    destroiGrafo(grafo);
    destroiFilter(filter);
    fclose(file);
}
