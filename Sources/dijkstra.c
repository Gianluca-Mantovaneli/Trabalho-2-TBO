#include "priorityQueue.h"
#include "grafoListaDeAdjacencia.h"
#include <limits.h>
#include <stdbool.h>

void dijkstra(Grafo grafo, int inicio)
{
    int V = grafo->V;

    // Alocação dinâmica de memória para as variáveis locais
    double *dist = (double *)malloc(V * sizeof(double));
    int *prev = (int *)malloc(V * sizeof(int));
    bool *visitado = (bool *)malloc(V * sizeof(bool));

    PriorityQueue pq;
    PQ_init(&pq, V);

    // Inicializando as distâncias, predecessores e visitados
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        prev[i] = -1;
        visitado[i] = false;
    }

    dist[inicio] = 0.0;
    PQ_insert(&pq, (Item){.id = inicio, .value = 0.0});

    // Algoritmo de Dijkstra para encontrar as distâncias mínimas de um nó de origem para todos os outros
    while (!PQ_empty(&pq))
    {
        Item u = PQ_delmin(&pq);
        int u_id = u.id;

        if (visitado[u_id])
            continue;
        visitado[u_id] = true;

        Node *vizinho = grafo->listaDeAdjacencia[u_id];
        while (vizinho != NULL)
        {
            int v = vizinho->id;
            double peso = vizinho->peso;

            if (dist[u_id] + peso < dist[v])
            {
                dist[v] = dist[u_id] + peso;
                prev[v] = u_id;
                PQ_insert(&pq, (Item){.id = v, .value = dist[v]});
            }

            vizinho = vizinho->prox;
        }
    }

    PQ_finish(&pq);

TODO: // Implementar a função que calcula os rtts e imprime o resultado, nesse ponto eu tenho a lista de predecessores e as distâncias mínimas

    // Liberação da memória alocada
    free(dist);
    free(prev);
    free(visitado);
}
