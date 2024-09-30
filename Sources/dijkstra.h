#if !defined(dijkstra_H)
#define dijkstra_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "priorityQueue.h"
#include "grafoListaDeAdjacencia.h"

#define INFINITO __DBL_MAX__

typedef struct grafo *Grafo;

void dijkstra(Grafo grafo, int origem, double **distancias);

#endif // dijkstra_H
