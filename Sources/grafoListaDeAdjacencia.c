#include "grafoListaDeAdjacencia.h"

Grafo iniciaGrafo(int V, int E)
{
    Grafo grafo = (Grafo)malloc(sizeof(struct grafo));
    grafo->V = V;
    grafo->E = E;
    grafo->listaDeAdjacencia = (Node **)malloc(V * sizeof(Node *));
    for (int i = 0; i < V; i++)
    {
        grafo->listaDeAdjacencia[i] = NULL;
    }
    return grafo;
}

Filter iniciaFilter(int S, int C, int M)
{
    Filter filter = (Filter)malloc(sizeof(struct filter));
    filter->S = S;
    filter->C = C;
    filter->M = M;
    filter->arraryS = (int *)malloc(S * sizeof(int));
    filter->arraryC = (int *)malloc(C * sizeof(int));
    filter->arraryM = (int *)malloc(M * sizeof(int));

    for (int i = 0; i < S; i++)
    {
        filter->arraryS[i] = -1;
    }
    for (int i = 0; i < C; i++)
    {
        filter->arraryC[i] = -1;
    }
    for (int i = 0; i < M; i++)
    {
        filter->arraryM[i] = -1;
    }
    return filter;
}

Filter insereInFilter(int numero, Filter filter, int tipo)
{
    if (tipo == 0) // == servidor
    {
        for (int i = 0; i < filter->S; i++)
        {
            if (filter->arraryS[i] == -1)
            {
                filter->arraryS[i] = numero;
                break;
            }
        }
    }
    else if (tipo == 1) // == cliente
    {
        for (int i = 0; i < filter->C; i++)
        {
            if (filter->arraryC[i] == -1)
            {
                filter->arraryC[i] = numero;
                break;
            }
        }
    }
    else if (tipo == 2) // == monitor
    {
        for (int i = 0; i < filter->M; i++)
        {
            if (filter->arraryM[i] == -1)
            {
                filter->arraryM[i] = numero;
                break;
            }
        }
    }
    return filter;
}

void insereArestaDirecionada(Grafo grafo, int idEmissor, int idReceptor, double peso)
{
    // Insere uma aresta direcionada de idEmissor para idReceptor com peso (Porem não estou verificando se já existe a aresta afim de economizar tempo de execução)
    Node *novoNode = (Node *)malloc(sizeof(Node));
    novoNode->id = idReceptor;
    novoNode->peso = peso;
    novoNode->prox = grafo->listaDeAdjacencia[idEmissor];
    grafo->listaDeAdjacencia[idEmissor] = novoNode;
}

Inflacao *iniciaInflacao(int C, int S)
{
    Inflacao *inflacao = (Inflacao *)malloc(C * S * sizeof(Inflacao));
    for (int i = 0; i < C; i++)
    {
        for (int j = 0; j < S; j++)
        {
            inflacao[i * S + j].idCliente = i;
            inflacao[i * S + j].idServidor = j;
            inflacao[i * S + j].valor = 0.0;
        }
    }
    return inflacao;
}

Inflacao *ordenaResultado(Inflacao *resultado, int C, int S)
{
    // qsort(resultado, C * S, sizeof(Inflacao), comparaInflacao);
    // TODO: resolver o problema de comparação do qsort que está dando erro
    return resultado;
}

void InsereInflacao(Inflacao *inflacao, int idCliente, int idServidor, double valor)
{
    Inflacao *inflacaoAtual = &inflacao[idCliente * idServidor];
    inflacaoAtual->valor = valor;
    inflacaoAtual->idCliente = idCliente;
    inflacaoAtual->idServidor = idServidor;
    inflacao[idCliente * idServidor] = *inflacaoAtual;
}

Inflacao *calculaInflacao(Grafo grafo, Filter filter)
{
    int C = filter->C;
    int S = filter->S;
    Inflacao *resultado = iniciaInflacao(C, S);

    for (int i = 0; i < C; i++)
    {
        for (int j = 0; j < S; j++)
        {
            int idCliente = filter->arraryC[i];
            int idServidor = filter->arraryS[j];
            // Equivalente a Equação RT T(a, b) = δ(a, b) + δ(b, a)
            double rtt = (dijkstra(grafo, idCliente, idServidor) + dijkstra(grafo, idServidor, idCliente));
            InsereInflacao(resultado, idCliente, idServidor, valor);
        }
    }

    return resultado;
}

void imprimeFilter(Filter filter)
{
    printf("S: ");
    for (int i = 0; i < filter->S; i++)
    {
        printf("%d ", filter->arraryS[i]);
    }
    printf("\nC: ");
    for (int i = 0; i < filter->C; i++)
    {
        printf("%d ", filter->arraryC[i]);
    }
    printf("\nM: ");
    for (int i = 0; i < filter->M; i++)
    {
        printf("%d ", filter->arraryM[i]);
    }
    printf("\n");
}

void imprimeGrafo(Grafo grafo)
{
    for (int i = 0; i < grafo->V; i++)
    {
        Node *atual = grafo->listaDeAdjacencia[i];
        printf("Vértice %d: ", i);
        while (atual != NULL)
        {
            printf(" -> %d(%lf) ", atual->id, atual->peso);
            atual = atual->prox;
        }
        printf("\n");
    }
}

void destroiGrafo(Grafo grafo)
{
    for (int i = 0; i < grafo->V; i++)
    {
        Node *atual = grafo->listaDeAdjacencia[i];
        while (atual != NULL)
        {
            Node *temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(grafo->listaDeAdjacencia);
    free(grafo);
}

void destroiFilter(Filter filter)
{
    free(filter->arraryS);
    free(filter->arraryC);
    free(filter->arraryM);
    free(filter);
}
