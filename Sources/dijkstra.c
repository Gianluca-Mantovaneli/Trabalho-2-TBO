#include "dijkstra.h"
double dijkstra(Grafo grafo, int origem, int destino)
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
        dist[i] = __DBL_MAX__;
        prev[i] = -1;
        visitado[i] = false;
    }

    dist[origem] = 0.0;
    PQ_insert(&pq, (Item){.id = origem, .value = 0.0});

    // Algoritmo de Dijkstra para encontrar as distâncias mínimas de um nó de origem para todos os outros
    while (!PQ_empty(&pq))
    {
        Item u = PQ_delmin(&pq);
        int u_id = u.id;

        if (visitado[u_id]) // Se o nó já foi visitado, podemos ignorá-lo
            continue;
        visitado[u_id] = true;

        // Verifica se alcançamos o destino, se sim, podemos parar a busca
        if (u_id == destino)
            break;

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

    double distanciaMinima = dist[destino]; // Armazena a distância mínima para o destino

    // Liberação da memória alocada
    free(dist);
    free(prev);
    free(visitado);
    PQ_finish(&pq);

    return distanciaMinima; // Retorna a menor distância entre a origem e o destino
}
