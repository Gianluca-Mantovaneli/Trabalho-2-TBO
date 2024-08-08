#if !defined(dijkstra_H)
#define dijkstra_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "grafoListaDeAdjacencia.h"
#include "priorityQueue.h"

void dijkstra(Grafo grafo, int inicio);

#endif // dijkstra_H
