#include "dijkstra.h"

void dijkstra(Grafo grafo, int inicio)
{
    int V = grafo->V; // Número de vértices
    double dist[V];   // Array de distâncias
    bool visitado[V]; // Array de visitados
    int prev[V];      // Array de predecessores

    // Inicializa os arrays das distâncias, predecessores e visitados
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        prev[i] = -1;
        visitado[i] = false;
    }

    dist[inicio] = 0.0;                            // A distância do vértice de início para ele mesmo é 0
    PQ_init(V);                                    // Inicializa a fila de prioridade
    PQ_insert((Item){.id = inicio, .value = 0.0}); // Insere o vértice de início na fila de prioridade

    while (!PQ_empty())
    {
        Item u = PQ_delmin();
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
                PQ_insert((Item){.id = v, .value = dist[v]});
            }

            vizinho = vizinho->prox;
        }
    }

    PQ_finish();
    // Output das distâncias mínimas
    for (int i = 0; i < V; i++)
    {
        printf("Distância do nó %d ao nó %d: %f\n", inicio, i, dist[i]);
    }
}
