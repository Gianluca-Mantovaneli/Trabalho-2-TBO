#if !defined(grafoListaDeAdjacencia_H)
#define grafoListaDeAdjacencia_H

#include <stdio.h>
#include <stdlib.h>

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

typedef struct inflacao
{
    int idCliente;  // Identificador do cliente
    int idServidor; // Identificador do servidor
    double valor;   // Valor da inflação entre o RTT e RTT* de cada relação
} Inflacao;

// Macros para facilitar a ordenação do resultado da inflação
#define cliente(A) (A.idCliente)
#define servidor(A) (A.idServidor)
#define valor(A) (A.valor)
#define comparaInflacao(A, B) ((A).valor < (B).valor ? -1 : ((A).valor > (B).valor ? 1 : 0))

Grafo iniciaGrafo(int V, int E);

Filter iniciaFilter(int S, int C, int M);

Filter insereInFilter(int numero, Filter filter, int tipo);

void insereArestaDirecionada(Grafo grafo, int idEmissor, int idReceptor, double peso);

Inflacao *iniciaInflacao(int C, int S);

Inflacao *ordenaResultado(Inflacao *resultado, int C, int S);

void InsereInflacao(Inflacao *inflacao, int idCliente, int idServidor, double valor);

Inflacao *calculaInflacao(Grafo grafo, Filter filter);

void imprimeFilter(Filter filter);

void imprimeGrafo(Grafo grafo);

void destroiGrafo(Grafo grafo);

void destroiFilter(Filter filter);

#endif // grafoListaDeAdjacencia_H
