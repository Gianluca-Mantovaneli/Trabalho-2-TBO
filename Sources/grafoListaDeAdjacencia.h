#if !defined(grafoListaDeAdjacencia_H)
#define grafoListaDeAdjacencia_H

typedef struct node
{
    int idReceptor;       // ID do vértice receptor
    double peso;          // Peso da aresta
    struct node *proximo; // Próximo nó caso exista
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

Grafo iniciaGrafo(int V, int E);

Filter iniciaFilter(int S, int C, int M);

void insereInFilter(int numero, Filter filter, int tipo);

void insereArestaNaoDirecionada(Grafo grafo, int idEmissor, int idReceptor, double peso);

void imprimeFilter(Filter filter);

void destroiGrafo(Grafo grafo);

void destroiFilter(Filter filter);

#endif // grafoListaDeAdjacencia_H
