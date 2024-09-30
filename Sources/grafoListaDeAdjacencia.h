#if !defined(grafoListaDeAdjacencia_H)
#define grafoListaDeAdjacencia_H

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
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

int comparaRTT(const void *a, const void *b);

Grafo iniciaGrafo(int V, int E);

Filter iniciaFilter(int S, int C, int M);

Filter insereInFilter(int numero, Filter filter, int tipo);

void insereArestaDirecionada(Grafo grafo, int idEmissor, int idReceptor, double peso);

RTT *iniciaInflacao(Filter filter);

RTT *ordenaResultado(RTT *resultado, int C, int S);

void InsereInflacao(RTT *inflacao, int tamanho, int idCliente, int idServidor, double valor);

RTT *calculaInflacao(Grafo grafo, Filter filter, double **distancias);

double calculaRTT(int idCliente, int idServidor, double **distancias);

double calculaRTTEstrela(Filter filter, int idCliente, int idServidor, double **distancias); // Função que calcula o valor do RTT* entre um cliente e um servidor

double **IniciaMatriz(int V);

void DestroiMatriz(double **matriz, int V);

void destroiGrafo(Grafo grafo);

void destroiFilter(Filter filter);

void destroiInflacao(RTT *inflacao);

void imprimeMatriz(double **distancias, int V);

void imprimeGrafo(Grafo grafo);

#endif // grafoListaDeAdjacencia_H
