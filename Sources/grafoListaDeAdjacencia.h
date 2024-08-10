#if !defined(grafoListaDeAdjacencia_H)
#define grafoListaDeAdjacencia_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "dijkstra.h"

typedef struct node
{
    int id;            // ID do vértice receptor
    double peso;       // Peso da aresta
    struct node *prox; // Próximo nó caso exista
} Node;

typedef struct grafo
{
    int V;                    // Número de vértices
    int E;                    // Número de arestas
    Node **listaDeAdjacencia; // Array de ponteiros para a lista de adjacência
} *Grafo;

typedef struct filter
{
    int S; // Número de servidores
    int C; // Número de clientes
    int M; // Número de monitores
    int *arraryS;
    int *arraryC;
    int *arraryM;
} *Filter;

typedef struct rtt
{
    int idCliente;  // Identificador do cliente
    int idServidor; // Identificador do servidor
    double valor;   // Valor da relação RTT entre cliente e servidor
} RTT;

// Macros para facilitar a ordenação do resultado da inflação
#define cliente(A) (A.idCliente)
#define servidor(A) (A.idServidor)
#define valor(A) (A.valor)
#define comparaRTT(A, B) ((A).valor < (B).valor ? -1 : ((A).valor > (B).valor ? 1 : 0))

Grafo iniciaGrafo(int V, int E);

Filter iniciaFilter(int S, int C, int M);

Filter insereInFilter(int numero, Filter filter, int tipo);

void insereArestaDirecionada(Grafo grafo, int idEmissor, int idReceptor, double peso);

RTT *iniciaInflacao(int C, int S);

RTT *ordenaResultado(RTT *resultado, int C, int S);

void InsereInflacao(RTT *inflacao, int idCliente, int idServidor, double valor);

RTT *calculaInflacao(Grafo grafo, Filter filter);

double calculaRTT(Grafo grafo, Filter filter, int idCliente, int idServidor); // Função que calcula o valor do RTT entre um cliente e um servidor

double calculaRTTEstrela(Grafo grafo, Filter filter, int idCliente, int idServidor); // Função que calcula o valor do RTT* entre um cliente e um servidor

void imprimeFilter(Filter filter);

void imprimeGrafo(Grafo grafo);

void destroiGrafo(Grafo grafo);

void destroiFilter(Filter filter);

void destroiInflacao(RTT *inflacao);

#endif // grafoListaDeAdjacencia_H
