#include <stdio.h>
#include <stdlib.h>
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

void insereInFilter(int numero, Filter filter, int tipo)
{
    if (tipo == 0) // == servidor
    {
    }
    else if (tipo == 1) // == cliente
    {
        for (int i = 0; i < filter->C; i++)
        {
            if (filter->arraryC[i] == -1)
            {
                filter->arraryC[i] = numero;
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
            }
        }
    }
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
