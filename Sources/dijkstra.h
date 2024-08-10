#if !defined(dijkstra_H)
#define dijkstra_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "priorityQueue.h"
#include "grafoListaDeAdjacencia.h"

typedef struct grafo *Grafo;

double dijkstra(Grafo grafo, int origem, int destino); // Função que calcula o valor do menor caminho entre dois vértices de um grafo

#endif // dijkstra_H
